/*
     Basic implementation of Signals-Slots concepts
     Implements communication between objects of Radio class and Station class.
*/
#include<iostream>
#include<QDebug>
#include <QCoreApplication>
#include "radio.h"
#include "station.h"
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio boombox;
    Station *channels[3];

    // create some stations
    channels[0] = new Station(&boombox, 94, "Music Hungama");
    channels[1] = new Station(&boombox, 102, "Science & Tech");
    channels[2] = new Station(&boombox, 94, "News");

    // Note : when the radio quit, the application should quit
    boombox.connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit,Qt::DirectConnection);
    /*
        -> When the radio is to be closed, then the entire application will be closed.
    */
    // Connecting and Disconnecting
    /*for(int i = 0; i<3; i++){
        Station *channel = channels[i];
        boombox.connect(channel, &Station::send, &boombox, &Radio::listen);
    }  */      // whenever the station sends something, the radio boomBox will listen to it

    do{
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin); // reading the standard input stream;
        QString line = qtin.readLine().trimmed().toUpper(); // reading the line, trimming the white space and making it all in one variable -line;

        // establish connection

        // All the objects are connected
        // Based on end user's input

        if(line == "OFF")
        {
            qInfo()<<"Turning the radio Off";
            for(int i = 0; i<3; i++){
                Station *channel = channels[i];
                boombox.disconnect(channel, &Station::send, &boombox, &Radio::listen); // If radio is Off, disconnect all the channels;
                }
            qInfo() <<" Radio is OFF";
        }

        if(line == "ON")
        {
            qInfo()<<"Turning the radio On";
            for(int i = 0; i<3; i++){
                Station *channel = channels[i];
                boombox.connect(channel, &Station::send, &boombox, &Radio::listen); // If radio is Off, disconnect all the channels;
                }
            qInfo() <<" Radio is ON";
        }

        if(line == "TEST")
        {
            qInfo()<<"Testing";
            for(int i = 0; i<3; i++){
                Station *channel = channels[i];
                channel->braodcast("Broadcasting the message");
               }
            qInfo() <<" Testing completed";
        }

        if(line == "Quit")
        {
            qInfo()<<"Quitting";
            emit boombox.quit();
                break;
        }

        }while(true);

       return a.exec();
}
