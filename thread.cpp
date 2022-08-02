#include "thread.h"

void runScript(QString script)
{
    QFile scriptFile("/tmp/script");
    scriptFile.open(QIODevice::ReadWrite);
    scriptFile.resize(0);
    scriptFile.write(script.toUtf8());
    scriptFile.close();

    system("xfce4-terminal -e \"sh /tmp/script\"");

//    scriptFile.remove();
}

void runApp(QString app)
{
    system(app.toUtf8() + " &");
}

void functionThread::run()
{
    if (function == "terminal") {
        runApp("xfce4-terminal");
    } else if (function == "firefox") {
        if (type == 1) {
            QString script = "echo Updating repositories\n"
                             "echo\n"
                             "sudo apt update\n"
                             "echo\n"
                             "echo Installing Firefox\n"
                             "echo\n"
                             "sudo apt install firefox -y\n"
                             "echo\n"
                             "echo \"\033[92mFirefox installed!\"\n"
                             "sleep 3";
            runScript(script);
        } else if (type == 2) {
            runApp("firefox");
        }
    } else if (function == "brave") {
        if (type == 1) {
            QString script = "echo Updating repositories\n"
                             "echo\n"
                             "sudo apt update\n"
                             "echo\n"
                             "echo Installing Brave\n"
                             "echo\n"
                             "sudo apt install apt-transport-https curl -y\n"
                             "sudo curl -fsSLo /usr/share/keyrings/brave-browser-archive-keyring.gpg https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg\n"
                             "echo \"deb [signed-by=/usr/share/keyrings/brave-browser-archive-keyring.gpg arch=amd64] https://brave-browser-apt-release.s3.brave.com/ stable main\" | sudo tee /etc/apt/sources.list.d/brave-browser-release.list\n"
                             "sudo apt update\n"
                             "sudo apt install brave-browser -y\n"
                             "echo\n"
                             "echo \"\033[92mBrave installed!\"\n"
                             "sleep 3";
            runScript(script);
        } else if (type == 2) {
            runApp("brave-browser --no-sandbox");
        }
    } else if (function == "CRD") {
        if (type == 0) {
            QString script = "echo Downloading Chrome remote desktop\n"
                             "echo\n"
                             "wget https://dl.google.com/linux/direct/chrome-remote-desktop_current_amd64.deb -O crd.deb\n"
                             "echo\n"
                             "Installing Chrome remote desktop\n"
                             "echo\n"
                             "sudo apt install ./crd.deb -y\n"
                             "echo\n"
                             "echo Installing other important packages\n"
                             "sudo apt install xvfb xbase-clients -y\n"
                             "echo\n"
                             "echo \"\033[92mChrome remote desktop installed!\"\n"
                             "sleep 3";
            runScript(script);
        } else if (type == 1) {
            QString CRDCommand = command + " --pin=" + QString::number(pin) + "\n"
                                 "echo\n"
                                 "echo \"\033[92mChrome remote desktop should be configured now!\"\n"
                                 "sleep 5";
            runScript(CRDCommand);
        } else if (type == 2) {
            QString script = "echo Updating repositories\n"
                             "echo\n"
                             "sudo apt update\n"
                             "echo\n"
                             "echo Installing XFCE4\n"
                             "echo\n"
                             "sudo apt install xfce4* -y\n"
                             "echo\n"
                             "echo \"\033[92mXFCE4 installed!\"\n"
                             "sleep 3";
            runScript(script);
        } else if (type == 3) {
            runScript("sudo service chrome-remote-desktop start\n"
                      "sleep 3");
        } else if (type == 4) {
            runScript("sudo service chrome-remote-desktop stop\n"
                      "sleep 3");
        } else if (type == 5) {
            runScript("sudo service chrome-remote-desktop reload\n"
                      "sleep 3");
        }
    }
}
