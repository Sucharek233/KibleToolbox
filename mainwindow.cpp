#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Terminal_clicked()
{
    thread.setF("terminal", 0);
    thread.start();
}

void MainWindow::on_Firefox_clicked()
{
    thread.setF("firefox", 1);
    thread.start();
}
void MainWindow::on_FirefoxStart_clicked()
{
    thread.setF("firefox", 2);
    thread.start();
}

void MainWindow::on_Brave_clicked()
{
    thread.setF("brave", 1);
    thread.start();
}
void MainWindow::on_BraveStart_clicked()
{
    thread.setF("brave", 2);
    thread.start();
}

void MainWindow::on_CRD_Install_clicked()
{
    thread.setF("CRD", 0);
    thread.start();
}
void MainWindow::on_CRD_Setup_clicked()
{
    CRD.setModal(true);
    if (CRD.exec() == QDialog::Accepted) {
        QString command = CRD.getCommand();
        int pin = CRD.getPin();
        thread.setCRDInfo(command, pin);
        thread.setF("CRD", 1);
        thread.start();

        QMessageBox done;
        done.setStyleSheet("QLabel {font-size: 20px;} QPushButton {font-size: 15px;}");
        done.setWindowTitle("Finished");
        done.setText("Chrome Remote Desktop should be now configured!\n\n"
                     "If you saw \"OAuth Error\", don't worry about it. Just click on the reload button.\n\n"
                     "Enjoy!");
        done.exec();
    }
}
void MainWindow::on_CRD_Xfce_clicked()
{
    thread.setF("CRD", 2);
    thread.start();
}
void MainWindow::on_CRD_Start_clicked() {thread.setF("CRD", 3); thread.start();}
void MainWindow::on_CRD_Stop_clicked() {thread.setF("CRD", 4); thread.start();}
void MainWindow::on_CRD_Reload_clicked() {thread.setF("CRD", 5); thread.start();}
