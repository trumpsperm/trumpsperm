// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_QT_BITCOINADDRESSVALIDATOR_H
#define BITCOINII_QT_BITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TrumpspermAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TrumpspermAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Trumpsperm address widget validator, checks for a valid trumpsperm address.
 */
class TrumpspermAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TrumpspermAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // BITCOINII_QT_BITCOINADDRESSVALIDATOR_H
