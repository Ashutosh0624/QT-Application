#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDebug>

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr, int channel = 0, QString name = "unkown");  // station will broadcast these info to radio

    int channel;
    QString name;

signals:
    void send(int channel, QString name, QString message);

public slots:
    void braodcast(QString message);
};

#endif // STATION_H
