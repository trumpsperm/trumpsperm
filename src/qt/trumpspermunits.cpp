// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/trumpspermunits.h>

#include <consensus/amount.h>

#include <QStringList>

#include <cassert>

static constexpr auto MAX_DIGITS_TPS = 16;

TrumpspermUnits::TrumpspermUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<TrumpspermUnit> TrumpspermUnits::availableUnits()
{
    QList<TrumpspermUnit> unitlist;
    unitlist.append(Unit::TPS);
    unitlist.append(Unit::mTPS);
    unitlist.append(Unit::uTPS);
    unitlist.append(Unit::SAT2);
    return unitlist;
}

QString TrumpspermUnits::longName(Unit unit)
{
    switch (unit) {
    case Unit::TPS: return QString("TPS");
    case Unit::mTPS: return QString("mTPS");
    case Unit::uTPS: return QString::fromUtf8("µTPS (bits)");
    case Unit::SAT2: return QString("Satooshi (sat2)");
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

QString TrumpspermUnits::shortName(Unit unit)
{
    switch (unit) {
    case Unit::TPS: return longName(unit);
    case Unit::mTPS: return longName(unit);
    case Unit::uTPS: return QString("bits");
    case Unit::SAT2: return QString("sat2");
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

QString TrumpspermUnits::description(Unit unit)
{
    switch (unit) {
    case Unit::TPS: return QString("Trumpsperms");
    case Unit::mTPS: return QString("Milli-Trumpsperms (1 / 1" THIN_SP_UTF8 "000)");
    case Unit::uTPS: return QString("Micro-Trumpsperms (bits) (1 / 1" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
    case Unit::SAT2: return QString("Satooshi (sat2) (1 / 100" THIN_SP_UTF8 "000" THIN_SP_UTF8 "000)");
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

qint64 TrumpspermUnits::factor(Unit unit)
{
    switch (unit) {
    case Unit::TPS: return 100'000'000;
    case Unit::mTPS: return 100'000;
    case Unit::uTPS: return 100;
    case Unit::SAT2: return 1;
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

int TrumpspermUnits::decimals(Unit unit)
{
    switch (unit) {
    case Unit::TPS: return 8;
    case Unit::mTPS: return 5;
    case Unit::uTPS: return 2;
    case Unit::SAT2: return 0;
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

QString TrumpspermUnits::format(Unit unit, const CAmount& nIn, bool fPlus, SeparatorStyle separators, bool justify)
{
    // Note: not using straight sprintf here because we do NOT want
    // localized number formatting.
    qint64 n = (qint64)nIn;
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    QString quotient_str = QString::number(quotient);
    if (justify) {
        quotient_str = quotient_str.rightJustified(MAX_DIGITS_TPS - num_decimals, ' ');
    }

    // Use SI-style thin space separators as these are locale independent and can't be
    // confused with the decimal marker.
    QChar thin_sp(THIN_SP_CP);
    int q_size = quotient_str.size();
    if (separators == SeparatorStyle::ALWAYS || (separators == SeparatorStyle::STANDARD && q_size > 4))
        for (int i = 3; i < q_size; i += 3)
            quotient_str.insert(q_size - i, thin_sp);

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n > 0)
        quotient_str.insert(0, '+');

    if (num_decimals > 0) {
        qint64 remainder = n_abs % coin;
        QString remainder_str = QString::number(remainder).rightJustified(num_decimals, '0');
        return quotient_str + QString(".") + remainder_str;
    } else {
        return quotient_str;
    }
}


// NOTE: Using formatWithUnit in an HTML context risks wrapping
// quantities at the thousands separator. More subtly, it also results
// in a standard space rather than a thin space, due to a bug in Qt's
// XML whitespace canonicalisation
//
// Please take care to use formatHtmlWithUnit instead, when
// appropriate.

QString TrumpspermUnits::formatWithUnit(Unit unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    return format(unit, amount, plussign, separators) + QString(" ") + shortName(unit);
}

QString TrumpspermUnits::formatHtmlWithUnit(Unit unit, const CAmount& amount, bool plussign, SeparatorStyle separators)
{
    QString str(formatWithUnit(unit, amount, plussign, separators));
    str.replace(QChar(THIN_SP_CP), QString(THIN_SP_HTML));
    return QString("<span style='white-space: nowrap;'>%1</span>").arg(str);
}

QString TrumpspermUnits::formatWithPrivacy(Unit unit, const CAmount& amount, SeparatorStyle separators, bool privacy)
{
    assert(amount >= 0);
    QString value;
    if (privacy) {
        value = format(unit, 0, false, separators, true).replace('0', '#');
    } else {
        value = format(unit, amount, false, separators, true);
    }
    return value + QString(" ") + shortName(unit);
}

bool TrumpspermUnits::parse(Unit unit, const QString& value, CAmount* val_out)
{
    if (value.isEmpty()) {
        return false; // Refuse to parse invalid unit or empty string
    }
    int num_decimals = decimals(unit);

    // Ignore spaces and thin spaces when parsing
    QStringList parts = removeSpaces(value).split(".");

    if(parts.size() > 2)
    {
        return false; // More than one dot
    }
    const QString& whole = parts[0];
    QString decimals;

    if(parts.size() > 1)
    {
        decimals = parts[1];
    }
    if(decimals.size() > num_decimals)
    {
        return false; // Exceeds max precision
    }
    bool ok = false;
    QString str = whole + decimals.leftJustified(num_decimals, '0');

    if(str.size() > 18)
    {
        return false; // Longer numbers will exceed 63 bits
    }
    CAmount retvalue(str.toLongLong(&ok));
    if(val_out)
    {
        *val_out = retvalue;
    }
    return ok;
}

QString TrumpspermUnits::getAmountColumnTitle(Unit unit)
{
    return QObject::tr("Amount") + " (" + shortName(unit) + ")";
}

int TrumpspermUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant TrumpspermUnits::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(longName(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant::fromValue(unit);
        }
    }
    return QVariant();
}

CAmount TrumpspermUnits::maxMoney()
{
    return MAX_MONEY;
}

namespace {
qint8 ToQint8(TrumpspermUnit unit)
{
    switch (unit) {
    case TrumpspermUnit::TPS: return 0;
    case TrumpspermUnit::mTPS: return 1;
    case TrumpspermUnit::uTPS: return 2;
    case TrumpspermUnit::SAT2: return 3;
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

TrumpspermUnit FromQint8(qint8 num)
{
    switch (num) {
    case 0: return TrumpspermUnit::TPS;
    case 1: return TrumpspermUnit::mTPS;
    case 2: return TrumpspermUnit::uTPS;
    case 3: return TrumpspermUnit::SAT2;
    }
    assert(false);
}
} // namespace

QDataStream& operator<<(QDataStream& out, const TrumpspermUnit& unit)
{
    return out << ToQint8(unit);
}

QDataStream& operator>>(QDataStream& in, TrumpspermUnit& unit)
{
    qint8 input;
    in >> input;
    unit = FromQint8(input);
    return in;
}
