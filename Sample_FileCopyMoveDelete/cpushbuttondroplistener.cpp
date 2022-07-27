#include "cpushbuttondroplistener.h"


CPushButtonDropListener::CPushButtonDropListener(QWidget *parent) : QPushButton(parent)
{
    setAcceptDrops (true);
    setMouseTracking (true);
}

void CPushButtonDropListener::dropEvent(QDropEvent *evt)
{
    emit dropped ();
}

void CPushButtonDropListener::dragEnterEvent(QDragEnterEvent *evt)
{
    emit entered ();
}

