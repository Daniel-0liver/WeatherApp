#include "weatherapp.h"
#include "./ui_weatherapp.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

WeatherApp::WeatherApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeatherApp)
{
    ui->setupUi(this);

    connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &WeatherApp::searchLineEditReturnPressed);
    
	connect(ui->searchButton, &QPushButton::clicked, this, &WeatherApp::searchButtonClicked);
    
	temperatureDialog = nullptr;
}

WeatherApp::~WeatherApp()
{
    delete ui;
}

void WeatherApp::searchLineEditReturnPressed()
{
    searchButtonClicked();
}

void WeatherApp::closeTemperatureDialog()
{
    if (temperatureDialog)
    {
        temperatureDialog->close();
    }
}

void WeatherApp::searchButtonClicked()
{
    QString city = ui->searchLineEdit->text();
    QString apiKey = "489b3812e338e39828ef74e51310e92d";
    QString apiUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;
	QNetworkAccessManager *manager = new QNetworkAccessManager(this);
	QNetworkRequest request;
	request.setUrl(QUrl(apiUrl));

    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {

            QByteArray response = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);

            QJsonObject jsonObject = jsonResponse.object();
            if (jsonObject.contains("main")) {
                QJsonValue temperatureValue = jsonObject["main"].toObject()["temp"];
                if (temperatureValue.isDouble()) {
                    double temperature = temperatureValue.toDouble() - 273.15;
                    QString temperatureString = "Right now in " + city + " it's: " + QString::number(temperature, 'f', 2) + " °C\n\nPress ESC to return.";

                    closeTemperatureDialog();
                    temperatureDialog = new TemperatureDialog(temperatureString, QPixmap("../images/sol.png"), this);
                    temperatureDialog->exec();
                }
            }
        } else {
            QMessageBox::warning(this, "Error", "City not found!");
        }

        reply->deleteLater();
        manager->deleteLater();
    });
}

TemperatureDialog::TemperatureDialog(const QString& temperatureString, const QPixmap& pixmap, QWidget* parent)
    : QDialog(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QHBoxLayout* imageLayout = new QHBoxLayout();
    QSpacerItem* spacerBefore = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);
    imageLayout->addItem(spacerBefore);

    QLabel* imageLabel = new QLabel(this);
    imageLabel->setPixmap(pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLayout->addWidget(imageLabel);

    QSpacerItem* spacerAfter = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);
    imageLayout->addItem(spacerAfter);

    layout->addLayout(imageLayout);

    QLabel* textLabel = new QLabel(temperatureString, this);
    layout->addWidget(textLabel);
}
