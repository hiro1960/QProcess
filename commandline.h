#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include <QDebug>
#include <QString>
#include <QProcess>

class commandline:public QObject
{
    Q_OBJECT

public:
    commandline();
    ~commandline();

private:
    void killProcess();

    QProcess *process;

private slots:
    void onEndProcess();
    void onProcessStdout();
    void onProcessStderr();

public:
    void onCommand( QString cmdline );

};

#endif // COMMANDLINE_H
