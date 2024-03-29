#!/usr/bin/env python3
# Copyright (c) 2014-2015 The Solbit Core developers
# Copyright (c) 2015-2017 The Solbit Unlimited developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
import test_framework.loginit
# Exercise the wallet keypool, and interaction with wallet encryption/locking

# Add python-solbitrpc to module search path:

from test_framework.test_framework import SolbitTestFramework
from test_framework.util import *

class KeyPoolTest(SolbitTestFramework):

    def run_test(self):
        nodes = self.nodes
        addr_before_encrypting = nodes[0].getnewaddress()
        addr_before_encrypting_data = nodes[0].validateaddress(addr_before_encrypting)
        wallet_info_old = nodes[0].getwalletinfo()
        assert(addr_before_encrypting_data['hdmasterkeyid'] == wallet_info_old['hdmasterkeyid'])
        
        # Encrypt wallet and wait to terminate
        nodes[0].encryptwallet('test')
        solbitd_processes[0].wait()
        # Restart node 0
        nodes[0] = start_node(0, self.options.tmpdir)
        # Keep creating keys
        addr = nodes[0].getnewaddress()
        addr_data = nodes[0].validateaddress(addr)
        wallet_info = nodes[0].getwalletinfo()
        assert(addr_before_encrypting_data['hdmasterkeyid'] != wallet_info['hdmasterkeyid'])
        assert(addr_data['hdmasterkeyid'] == wallet_info['hdmasterkeyid'])
        
        try:
            addr = nodes[0].getnewaddress()
            raise AssertionError('Keypool should be exhausted after one address')
        except JSONRPCException as e:
            assert(e.error['code']==-12)

        # put three new keys in the keypool
        nodes[0].walletpassphrase('test', 12000)
        nodes[0].keypoolrefill(3)
        nodes[0].walletlock()

        # drain the keys
        addr = set()
        addr.add(nodes[0].getrawchangeaddress())
        addr.add(nodes[0].getrawchangeaddress())
        addr.add(nodes[0].getrawchangeaddress())
        addr.add(nodes[0].getrawchangeaddress())
        # assert that four unique addresses were returned
        assert(len(addr) == 4)
        # the next one should fail
        try:
            addr = nodes[0].getrawchangeaddress()
            raise AssertionError('Keypool should be exhausted after three addresses')
        except JSONRPCException as e:
            assert(e.error['code']==-12)

        # refill keypool with three new addresses
        nodes[0].walletpassphrase('test', 1)
        nodes[0].keypoolrefill(3)
        # test walletpassphrase timeout
        time.sleep(1.1)
        assert_equal(nodes[0].getwalletinfo()["unlocked_until"], 0)

        # drain them by mining
        nodes[0].generate(1)
        nodes[0].generate(1)
        nodes[0].generate(1)
        nodes[0].generate(1)
        try:
            nodes[0].generate(1)
            raise AssertionError('Keypool should be exhausted after three addesses')
        except JSONRPCException as e:
            assert(e.error['code']==-12)

    # BU Removed, implemented in base class def setup_chain(self):
    #    print("Initializing test directory "+self.options.tmpdir)
    #    initialize_chain(self.options.tmpdir)

    def setup_network(self):
        self.nodes = start_nodes(1, self.options.tmpdir)

if __name__ == '__main__':
    KeyPoolTest().main(None,{"keypool":1})  # BU add limited keypool here, not across all other tests
