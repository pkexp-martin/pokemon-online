#include "analyze.h"
#include "network.h"
#include "client.h"

using namespace NetworkCli;

Analyzer::Analyzer()
{
    connect(&socket(), SIGNAL(connected()), SIGNAL(connected()));
    connect(&socket(), SIGNAL(disconnected()), SIGNAL(disconnected()));
    connect(this, SIGNAL(sendCommand(QByteArray)), &socket(), SLOT(send(QByteArray)));
    connect(&socket(), SIGNAL(isFull(QByteArray)), SLOT(commandReceived(QByteArray)));
    connect(&socket(), SIGNAL(error()), SLOT(error()));
}

void Analyzer::login(const QString &name, const QString &pass)
{
    QByteArray tosend;
    QDataStream in(&tosend, QIODevice::WriteOnly);

    in << uchar(Login) << name << pass;

    emit sendCommand(tosend);
}

void Analyzer::sendMessage(const QString &message)
{
    QByteArray tosend;
    QDataStream out(&tosend, QIODevice::WriteOnly);

    out << uchar(SendMessage) << message;

    emit sendCommand(tosend);
}

void Analyzer::connectTo(const QString &host, quint16 port)
{
    mysocket.connectToHost(host, port);
}

void Analyzer::error()
{
    emit connectionError(socket().error(), socket().errorString());
}

void Analyzer::commandReceived(const QByteArray &commandline)
{
    QDataStream in (commandline);
    uchar command;

    in >> command;

    switch (command) {
	case SendMessage:
	{
	    QString mess;
	    in >> mess;
	    emit messageReceived(mess);
	    break;
	}
	default:
	    emit protocolError(UnknownCommand, tr("Protocol error: unknown command received"));
    }
}

Network & Analyzer::socket()
{
    return mysocket;
}