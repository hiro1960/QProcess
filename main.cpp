#include <QCoreApplication>
#include "commandline.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    commandline exec;

//    exec.onCommand("helloworld.exe");
    exec.onCommand("test.bat");

//    return a.exec();
    return 0;
}
