// Copyright (c) 2011-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_WALLETFRAME_H
#define SOLBIT_QT_WALLETFRAME_H

#include <QFrame>
#include <QMap>

class SolbitGUI;
class ClientModel;
class PlatformStyle;
class SendCoinsRecipient;
class WalletModel;
class WalletView;
class Config;

QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE

class WalletFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WalletFrame(const PlatformStyle *platformStyle, const Config *cfg, SolbitGUI *_gui = 0);
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(const QString &name, WalletModel *walletModel);
    bool setCurrentWallet(const QString &name);
    bool removeWallet(const QString &name);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient &recipient);

    void showOutOfSyncWarning(bool fShow);

private:
    QStackedWidget *walletStack;
    SolbitGUI *gui;
    ClientModel *clientModel;
    QMap<QString, WalletView *> mapWalletViews;

    bool bOutOfSync;

    const PlatformStyle *platformStyle;
    const Config *cfg;

    WalletView *currentWalletView();

public Q_SLOTS:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();
};

#endif // SOLBIT_QT_WALLETFRAME_H
