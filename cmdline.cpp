#include "commandline.h"

commandline::commandline():
    process( new QProcess(this) )
{
    // Process event
    connect(process, SIGNAL(finished(int)), this, SLOT(onEndProcess()));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessStdout()));
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(onProcessStderr()));
}

commandline::~commandline()
{
    delete process;
}

void commandline::onCommand(QString cmdline)
{
    killProcess();

    qDebug() << "cmd : " << cmdline;
    process->start(cmdline);
    if (!process->waitForStarted()) {
        qWarning() << process->errorString();
        return;
    }
}

void commandline::killProcess()
{
    if (process->state() == QProcess::Running) {
        process->kill();
        if (!process->waitForFinished()) {
            qWarning() << process->errorString();
        }
    }
}

void commandline::onEndProcess()
{
    qDebug() << "end process";
}

void commandline::onProcessStdout()
{
    qDebug() << "process stdout";

    QByteArray arr = process->readAllStandardOutput();
    qDebug() << QString::fromLocal8Bit(arr);
}

void commandline::onProcessStderr()
{
    qDebug() << "process stderr";

    QByteArray arr = process->readAllStandardError();
    qDebug() << QString::fromLocal8Bit(arr);
}

void commandline::waitRead()
{
    while ( process->state() == QProcess::Running )
    {
        process->waitForReadyRead( 100 );   // 100msでloop
    }
}
