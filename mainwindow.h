#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "thread.h"
#include "crdinfo.h"
#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Firefox_clicked();

    void on_FirefoxStart_clicked();

    void on_Brave_clicked();

    void on_BraveStart_clicked();

    void on_Terminal_clicked();

    void on_CRD_Install_clicked();

    void on_CRD_Setup_clicked();

    void on_CRD_Start_clicked();

    void on_CRD_Stop_clicked();

    void on_CRD_Reload_clicked();

    void on_CRD_Xfce_clicked();

private:
    Ui::MainWindow *ui;

    functionThread thread;

    CRDInfo CRD;
};
#endif // MAINWINDOW_H
