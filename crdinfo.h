#ifndef CRDINFO_H
#define CRDINFO_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class CRDInfo;
}

class CRDInfo : public QDialog
{
    Q_OBJECT

public:
    explicit CRDInfo(QWidget *parent = nullptr);
    ~CRDInfo();

    QString getCommand() {return command;}
    int getPin() {return pin;}

private slots:
    void on_pushButton_Ok_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Get_clicked();

private:
    Ui::CRDInfo *ui;

    QString command;
    int pin;
};

#endif // CRDINFO_H
