#ifndef IMPORTERLYDPAKKE_H
#define IMPORTERLYDPAKKE_H

#include <QWidget>

namespace Ui {
class ImporterLydpakke;
}

class ImporterLydpakke : public QWidget
{
    Q_OBJECT

public:
    explicit ImporterLydpakke(QWidget *parent = 0);
    ~ImporterLydpakke();

private slots:
    void on_backButton_clicked();

private:
    Ui::ImporterLydpakke *ui;
};

#endif // IMPORTERLYDPAKKE_H
