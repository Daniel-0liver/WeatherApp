#ifndef WEATHERAPP_H
#define WEATHERAPP_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class WeatherApp; }
QT_END_NAMESPACE

class TemperatureDialog;

class WeatherApp : public QMainWindow
{
    Q_OBJECT

public:
    WeatherApp(QWidget *parent = nullptr);
    ~WeatherApp();

private:
    Ui::WeatherApp *ui;
    TemperatureDialog *temperatureDialog;

private slots:
    void searchButtonClicked();
    void searchLineEditReturnPressed();
    void closeTemperatureDialog();
};

class TemperatureDialog : public QDialog
{
    Q_OBJECT

public:
    TemperatureDialog(const QString& temperatureString, const QPixmap& pixmap, QWidget* parent = nullptr);

private:
    QLabel *imageLabel;
};

#endif
