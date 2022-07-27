#ifndef CPUSHBUTTONDROPLISTENER_H
#define CPUSHBUTTONDROPLISTENER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>

class CPushButtonDropListener : public QPushButton
{
    Q_OBJECT

public:
    explicit CPushButtonDropListener(QWidget *parent);

    void dropEvent (QDropEvent *evt);
    void dragEnterEvent (QDragEnterEvent *evt);

signals:
    void entered();
    void dropped();
};

#endif // CPUSHBUTTONDROPLISTENER_H
