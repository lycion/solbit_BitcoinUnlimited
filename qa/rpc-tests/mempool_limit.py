#!/usr/bin/env python3
# Copyright (c) 2014-2015 The Solbit Core developers
# Copyright (c) 2015-2017 The Solbit Unlimited developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
import test_framework.loginit
# Test mempool limiting together/eviction with the wallet

from test_framework.test_framework import SolbitTestFramework
from test_framework.util import *

class MempoolLimitTest(SolbitTestFramework):

    def __init__(self):
        self.txouts = gen_return_txouts()

    def setup_network(self):
        self.nodes = []
        self.nodes.append(start_node(0, self.options.tmpdir, ["-maxmempool=5", "-spendzeroconfchange=0", "-minlimitertxfee=2", "-debug"]))
        self.is_network_split = False
        self.sync_all()
        self.relayfee = self.nodes[0].getnetworkinfo()['relayfee']

    def setup_chain(self):
        print("Initializing test directory "+self.options.tmpdir)
        initialize_chain_clean(self.options.tmpdir, 2)

    def run_test(self):
        txids = []
        utxos = create_confirmed_utxos(self.relayfee, self.nodes[0], 91)

        #create a mempool tx that will be evicted
        us0 = utxos.pop()
        inputs = [{ "txid" : us0["txid"], "vout" : us0["vout"]}]
        outputs = {self.nodes[0].getnewaddress() : 0.0001}
        tx = self.nodes[0].createrawtransaction(inputs, outputs)
        self.nodes[0].settxfee(self.relayfee) # specifically fund this tx with low fee
        txF = self.nodes[0].fundrawtransaction(tx)
        txFS = self.nodes[0].signrawtransaction(txF['hex'])
        txid = self.nodes[0].sendrawtransaction(txFS['hex'])

        relayfee = self.nodes[0].getnetworkinfo()['relayfee']
        base_fee = relayfee*100
        for i in range (3):
            txids.append([])
            txids[i] = create_lots_of_big_transactions(self.nodes[0], self.txouts, utxos[30*i:30*i+30], 30, (i+1)*base_fee)

        assert(txid not in self.nodes[0].getrawmempool())
        txdata = self.nodes[0].gettransaction(txid)
        assert(txdata['confirmations'] ==  0) #confirmation should still be 0

if __name__ == '__main__':
    MempoolLimitTest().main()
