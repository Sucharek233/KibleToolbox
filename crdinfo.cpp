#include "crdinfo.h"
#include "ui_crdinfo.h"

CRDInfo::CRDInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRDInfo)
{
    ui->setupUi(this);
}

CRDInfo::~CRDInfo()
{
    delete ui;
}

void CRDInfo::on_pushButton_Ok_clicked()
{
    QString Command = ui->lineEdit_Command->text();
    QString Pin = ui->lineEdit_Pin->text();
    int pinInt = Pin.toInt();

    QMessageBox shortPin;
    shortPin.setWindowTitle("Short or incorrect PIN");
    shortPin.setText("PIN is too short or contains letters!\n"
                     "Please make a pin with atleast 6 numbers.\n\n"
                     "Cannot continue.");
    shortPin.setStyleSheet("QLabel {font-size: 20px;} QPushButton {font-size: 15px;}");

    if (pinInt != 0) {
        if (Pin.count() < 6) {
            shortPin.exec();
        } else {
            command = Command;
            pin = Pin.toInt();
            accept();
            close();
        }
    } else {
        shortPin.exec();
    }
}

void CRDInfo::on_pushButton_Cancel_clicked()
{
    reject();
    close();
}

void CRDInfo::on_pushButton_Get_clicked()
{
    QMessageBox command;
    command.setTextFormat(Qt::RichText);
    command.setStyleSheet("QLabel {font-size: 20px;} QPushButton {font-size: 15px;}");
    command.setWindowTitle("Get command");
    command.setText("Go to the <a href=\"https://remotedesktop.google.com/headless\">Chrome Remote Desktop webiste</a>.<br>"
                    "You might need to login into your Google account first.<br>"
                    "You must use the same account as you logged into Kible and on your PC.<br><br>"
                    "Click on the Begin button.<br>"
                    "If you click the Install button here, you don't have to do anything on the next screen, just click on Next.<br>"
                    "Now click on Authorize.<br>"
                    "It should give you 3 commands.<br>"
                    "Copy the one for Debian Linux<br>"
                    "Now just paste that command into this dialog (click Ok here first).<br><br>"
                    "You should now have the command.");
    command.exec();
}
