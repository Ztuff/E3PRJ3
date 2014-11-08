#ifndef SLETLYDPAKKE_H
#define SLETLYDPAKKE_H

#include <QWidget>

namespace Ui {
class SletLydpakke;
}

class SletLydpakke : public QWidget
{
    Q_OBJECT

public:
    explicit SletLydpakke(QWidget *parent = 0);
    ~SletLydpakke();

private:
    Ui::SletLydpakke *ui;
};

#endif // SLETLYDPAKKE_H
