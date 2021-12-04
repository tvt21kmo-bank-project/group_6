#include "kokeilu.h"

Kokeilu::Kokeilu(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant Kokeilu::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex Kokeilu::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex Kokeilu::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int Kokeilu::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Kokeilu::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant Kokeilu::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
