// Copyright (c) 2009-2014 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Copyright (c) 2017 The Solbit developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "chainparams.h"
#include "config.h"
#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTestsBase58()
{
    SendCoinsRecipient rv;
    QString scheme =
        QString::fromStdString(Params(CBaseChainParams::MAIN).CashAddrPrefix());
    QUrl uri;
    uri.setUrl(QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?req-dontexist="));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?dontexist="));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?amount=0.001"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?amount=1.001"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseSolbitURI(scheme, "solbitcash://175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?"
                                     "message=Wikipedia Example Address",
                                     &rv));
    QVERIFY(rv.address == QString("175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString("solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));
}

void URITests::uriTestsCashAddr() {
    SendCoinsRecipient rv;
    QUrl uri;
    QString scheme =
        QString::fromStdString(Params(CBaseChainParams::MAIN).CashAddrPrefix());
    uri.setUrl(QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?"
                       "req-dontexist="));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?dontexist="));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(
        QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?label="
                "Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?amount=0.001"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?amount=1.001"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?amount=100&"
        "label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?message="
        "Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseSolbitURI(
        scheme, "solbitcash://"
                "qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?"
                "message=Wikipedia Example Address",
        &rv));
    QVERIFY(rv.address ==
            QString("solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?req-message="
        "Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?amount=1,"
        "000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));

    uri.setUrl(QString(
        "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?amount=1,"
        "000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseSolbitURI(scheme, uri, &rv));
}

namespace {
class UriTestConfig : public DummyConfig {
public:
    UriTestConfig(bool _useCashAddr)
        : useCashAddr(_useCashAddr), net(CBaseChainParams::MAIN) {}
    bool UseCashAddrEncoding() const override { return useCashAddr; }
    const CChainParams &GetChainParams() const override { return Params(net); }
    void SetChainParams(const std::string &n) { net = n; }

private:
    bool useCashAddr;
    std::string net;
};

} // anon ns

void URITests::uriTestFormatURI() {
    {
        UriTestConfig cfg(true);
        SendCoinsRecipient r;
        r.address = "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a";
        r.message = "test";
        QString uri = GUIUtil::formatSolbitURI(cfg, r);
        QVERIFY(uri == "solbitcash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a?"
                       "message=test");
    }

    {
        UriTestConfig cfg(false);
        SendCoinsRecipient r;
        r.address = "175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W";
        r.message = "test";
        QString uri = GUIUtil::formatSolbitURI(cfg, r);
        QVERIFY(uri ==
                "solbitcash:175tWpb8K1S7NmH4Zx6rewF9WQrcZv245W?message=test");
    }
}

void URITests::uriTestScheme() {
    {
        // cashaddr - scheme depends on selected chain params
        UriTestConfig config(true);
        config.SetChainParams(CBaseChainParams::MAIN);
        QVERIFY("solbitcash" == GUIUtil::solbitURIScheme(config));
        config.SetChainParams(CBaseChainParams::TESTNET);
        QVERIFY("sbttest" == GUIUtil::solbitURIScheme(config));
        config.SetChainParams(CBaseChainParams::REGTEST);
        QVERIFY("sbtreg" == GUIUtil::solbitURIScheme(config));
    }
    {
        // legacy - scheme is "solbitcash" regardless of chain params
        UriTestConfig config(false);
        config.SetChainParams(CBaseChainParams::MAIN);
        QVERIFY("solbitcash" == GUIUtil::solbitURIScheme(config));
        config.SetChainParams(CBaseChainParams::TESTNET);
        QVERIFY("solbitcash" == GUIUtil::solbitURIScheme(config));
        config.SetChainParams(CBaseChainParams::REGTEST);
        QVERIFY("solbitcash" == GUIUtil::solbitURIScheme(config));
    }
}
