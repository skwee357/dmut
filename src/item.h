#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QList>
#include <QVariant>
#include <QModelIndex>

class Item
{
public:
    enum class Type{
        ROOT,
        CHARACTER,
        ANIMATION,
        FRAME
    };

    Item(const QString& name);
    virtual ~Item();

    inline QString name() const { return mName; }
    inline void rename(const QString& name) { mName = name; }

    inline Item* parent() const { return mParent; }

    int rowCount() const;
    int columnCount() const;

    int rowIndex() const;

    virtual QVariant data(int column, int role) const;
    virtual Qt::ItemFlags flags() const;

    virtual bool setData(const QVariant& value, int column, int role);

    Item* at(int index) const;
    void add(Item* item);
    void remove(Item* item);

    virtual Item* getNewChild() = 0;
    virtual Type type() = 0;

private:
    Item* mParent;
    QString mName;
    QList<Item*> mChildren;
};

#endif // ITEM_H
