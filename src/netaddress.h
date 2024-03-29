// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2017 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_NETADDRESS_H
#define SOLBIT_NETADDRESS_H

#include <stdint.h>
#include <string>
#include <vector>

#if defined(HAVE_CONFIG_H)
#include "config/solbit-config.h"
#endif

#include "compat.h" // socklen_t
#include "serialize.h"


extern const unsigned char pchIPv4[12];

enum
{
    IPV6_ADDR_SCOPE_RESERVED = 0x0,
    IPV6_ADDR_SCOPE_GLOBAL = 0x0e,
};

enum Network
{
    NET_UNROUTABLE = 0,
    NET_IPV4,
    NET_IPV6,
    NET_TOR,

    NET_MAX,
};

/** IP address (IPv6, or IPv4 using mapped IPv6 range (::FFFF:0:0/96)) */
class CNetAddr
{
protected:
    unsigned char ip[16]; // in network byte order
    uint32_t scopeId; // for scoped/link-local ipv6 addresses

public:
    CNetAddr();
    CNetAddr(const struct in_addr &ipv4Addr);
    CNetAddr(const struct in6_addr &pipv6Addr, const uint32_t scope = IPV6_ADDR_SCOPE_RESERVED);
    explicit CNetAddr(const char *pszIp);
    explicit CNetAddr(const std::string &strIp);
    void Init();
    void SetIP(const CNetAddr &ip);

    /**
     * Set raw IPv4 or IPv6 address (in network byte order)
     * @note Only NET_IPV4 and NET_IPV6 are allowed for network.
     */
    void SetRaw(Network network, const uint8_t *data);

    bool SetSpecial(const std::string &strName); // for Tor addresses
    bool IsIPv4() const; // IPv4 mapped address (::FFFF:0:0/96, 0.0.0.0/0)
    bool IsIPv6() const; // IPv6 address (not mapped IPv4, not Tor)
    bool IsRFC1918() const; // IPv4 private networks (10.0.0.0/8, 192.168.0.0/16, 172.16.0.0/12)
    bool IsRFC2544() const; // IPv4 inter-network communcations (192.18.0.0/15)
    bool IsRFC6598() const; // IPv4 ISP-level NAT (100.64.0.0/10)
    bool IsRFC5737() const; // IPv4 documentation addresses (192.0.2.0/24, 198.51.100.0/24, 203.0.113.0/24)
    bool IsRFC3849() const; // IPv6 documentation address (2001:0DB8::/32)
    bool IsRFC3927() const; // IPv4 autoconfig (169.254.0.0/16)
    bool IsRFC3964() const; // IPv6 6to4 tunnelling (2002::/16)
    bool IsRFC4193() const; // IPv6 unique local (FC00::/7)
    bool IsRFC4380() const; // IPv6 Teredo tunnelling (2001::/32)
    bool IsRFC4843() const; // IPv6 ORCHID (2001:10::/28)
    bool IsRFC4862() const; // IPv6 autoconfig (FE80::/64)
    bool IsRFC6052() const; // IPv6 well-known prefix (64:FF9B::/96)
    bool IsRFC6145() const; // IPv6 IPv4-translated address (::FFFF:0:0:0/96)
    bool IsTor() const;
    bool IsLocal() const;
    bool IsRoutable() const;
    bool IsValid() const;
    bool IsMulticast() const;
    enum Network GetNetwork() const;
    std::string ToString() const;
    std::string ToStringIP() const;
    unsigned int GetByte(int n) const;
    uint64_t GetHash() const;
    bool GetInAddr(struct in_addr *pipv4Addr) const;
    std::vector<unsigned char> GetGroup() const;
    int GetReachabilityFrom(const CNetAddr *paddrPartner = NULL) const;

    bool GetIn6Addr(struct in6_addr *pipv6Addr) const;

    friend bool operator==(const CNetAddr &a, const CNetAddr &b);
    friend bool operator!=(const CNetAddr &a, const CNetAddr &b);
    friend bool operator<(const CNetAddr &a, const CNetAddr &b);

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        READWRITE(FLATDATA(ip));
    }

    friend class CSubNet;
};

/** A combination of a network address (CNetAddr) and a (TCP) port */
class CService : public CNetAddr
{
protected:
    unsigned short port; // host order

public:
    CService();
    CService(const CNetAddr &ip, unsigned short port);
    CService(const struct in_addr &ipv4Addr, unsigned short port);
    CService(const struct sockaddr_in &addr);
    CService(const struct in6_addr &ipv6Addr, unsigned short port);
    CService(const struct sockaddr_in6 &addr);
    explicit CService(const char *pszIpPort, int portDefault);
    explicit CService(const char *pszIpPort);
    explicit CService(const std::string &strIpPort, int portDefault);
    explicit CService(const std::string &strIpPort);

    void SetPort(unsigned short portIn);
    unsigned short GetPort() const;
    bool GetSockAddr(struct sockaddr *paddr, socklen_t *addrlen) const;
    bool SetSockAddr(const struct sockaddr *paddr);
    friend bool operator==(const CService &a, const CService &b);
    friend bool operator!=(const CService &a, const CService &b);
    friend bool operator<(const CService &a, const CService &b);
    std::vector<unsigned char> GetKey() const;
    std::string ToString() const;
    std::string ToStringPort() const;
    std::string ToStringIPPort() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        READWRITE(FLATDATA(ip));
        unsigned short portN = htons(port);
        READWRITE(FLATDATA(portN));
        if (ser_action.ForRead())
            port = ntohs(portN);
    }
};

class CSubNet
{
protected:
    /// Network (base) address
    CNetAddr network;
    /// Netmask, in network byte order
    uint8_t netmask[16];
    /// Is this value valid? (only used to signal parse errors)
    bool valid;

public:
    CSubNet();
    explicit CSubNet(const std::string &strSubnet);

    // constructor for single ip subnet (<ipv4>/32 or <ipv6>/128)
    explicit CSubNet(const CNetAddr &addr);

    bool Match(const CNetAddr &addr) const;

    std::string ToString() const;
    bool IsValid() const;

    friend bool operator==(const CSubNet &a, const CSubNet &b);
    friend bool operator!=(const CSubNet &a, const CSubNet &b);
    friend bool operator<(const CSubNet &a, const CSubNet &b);

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        READWRITE(network);
        READWRITE(FLATDATA(netmask));
        READWRITE(FLATDATA(valid));
    }
};


#endif
