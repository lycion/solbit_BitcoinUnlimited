// Copyright (c) 2011-2013 The Solbit Core developers
// Copyright (c) 2015-2017 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_TRANSACTIONDESC_H
#define SOLBIT_QT_TRANSACTIONDESC_H

#include <QObject>
#include <QString>

class TransactionRecord;

class CWallet;
class CWalletTx;

/** Provide a human-readable extended HTML description of a transaction.
 */
class TransactionDesc : public QObject
{
    Q_OBJECT

public:
    static QString toHTML(CWallet *wallet, CWalletTx &wtx, TransactionRecord *rec, int unit, QString labelFreeze);

private:
    TransactionDesc() {}
    static QString FormatTxStatus(const CWalletTx &wtx);
};

#endif // SOLBIT_QT_TRANSACTIONDESC_H
