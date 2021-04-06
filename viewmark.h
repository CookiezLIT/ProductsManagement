
#ifndef VIEWMARK_H
#define VIEWMARK_H

#include <QDialog>

namespace Ui {
class viewMark;
}

class viewMark : public QDialog
{
    Q_OBJECT

public:
    explicit viewMark(QWidget *parent = nullptr);
    ~viewMark();

private slots:

private:
    Ui::viewMark *ui;
};

#endif // VIEWMARK_H
