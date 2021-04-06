#ifndef HIDER_H
#define HIDER_H


#include <QEvent>
#include <QPaintEvent>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QApplication>




class Hider : public QObject
{
    Q_OBJECT
public:
    Hider(QObject *parent = 0) : QObject(parent){}
    bool eventFilter(QObject *, QEvent *ev){
        return ev->type() == QEvent::Paint;
    }
    void hide(QWidget *wdg){
        wdg->installEventFilter(this);
        wdg->update();
    }
    void unhide(QWidget *wdg){
        wdg->removeEventFilter(this);
        wdg->update();
    }
    Q_SLOT void hideWidget()
    {
        QObject *s = sender();
        if(s->isWidgetType()) { hide(qobject_cast<QWidget*>(s));}
    }


};

#endif // HIDER_H
