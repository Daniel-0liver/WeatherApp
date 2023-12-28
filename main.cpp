#include "weatherapp.h"

#include <QApplication>

//Main function to iniatiate the program
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherApp w;
    w.show();
    return a.exec();
}