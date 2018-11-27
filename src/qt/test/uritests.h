// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_TEST_URITESTS_H
#define SOLBIT_QT_TEST_URITESTS_H

#include <QObject>
#include <QTest>

class URITests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void uriTestsBase58();
    void uriTestsCashAddr();
    void uriTestFormatURI();
    void uriTestScheme();
};

#endif // SOLBIT_QT_TEST_URITESTS_H
