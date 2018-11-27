// Copyright (c) 2011-2014 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Copyright (c) 2017 The Solbit developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_SOLBITADDRESSVALIDATOR_H
#define SOLBIT_QT_SOLBITADDRESSVALIDATOR_H

#include <QValidator>

/**
 * Solbit address entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SolbitAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SolbitAddressEntryValidator(const std::string &cashaddrprefix, QObject *parent);

    State validate(QString &input, int &pos) const;

private:
    std::string cashaddrprefix;
};

/** Solbit address widget validator, checks for a valid solbit address.
 */
class SolbitAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SolbitAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SOLBIT_QT_SOLBITADDRESSVALIDATOR_H
