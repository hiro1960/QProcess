#include <QCoreApplication>
#include "commandline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    commandline exec;

    exec.onCommand("helloworld.exe");
    exec.waitRead();    // 終了を待つ
    exec.onCommand("test.bat");
    exec.waitRead();    // 終了を待つ

//    return a.exec();
    return 0;
}
