// Copyright (c) 2017 The Solbit Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_TEST_SOLBITADDRESSVALIDATORTESTS_H
#define SOLBIT_QT_TEST_SOLBITADDRESSVALIDATORTESTS_H

#include <QObject>
#include <QTest>

class SolbitAddressValidatorTests : public QObject {
    Q_OBJECT

private Q_SLOTS:
    void inputTests();
};

#endif
