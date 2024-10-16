#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include<QDebug>

class Radio : public QObject
{
    Q_OBJECT
public:
    explicit Radio(QObject *parent = nullptr);

signals:
    void quit();

    // Radio will listen to stations, that it will listen to messages emitted by stations
    public slots:
    void listen(int channel, QString name, QString message);


};

#endif // RADIO_H
