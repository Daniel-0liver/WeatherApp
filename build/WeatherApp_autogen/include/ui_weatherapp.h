/********************************************************************************
** Form generated from reading UI file 'weatherapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERAPP_H
#define UI_WEATHERAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherApp
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *cityNameLabel;
    QLineEdit *searchLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WeatherApp)
    {
        if (WeatherApp->objectName().isEmpty())
            WeatherApp->setObjectName(QString::fromUtf8("WeatherApp"));
        WeatherApp->resize(530, 290);
        centralwidget = new QWidget(WeatherApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cityNameLabel = new QLabel(centralwidget);
        cityNameLabel->setObjectName(QString::fromUtf8("cityNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        cityNameLabel->setFont(font);

        horizontalLayout->addWidget(cityNameLabel);

        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        WeatherApp->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WeatherApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WeatherApp->setStatusBar(statusbar);

        retranslateUi(WeatherApp);

        QMetaObject::connectSlotsByName(WeatherApp);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherApp)
    {
        WeatherApp->setWindowTitle(QApplication::translate("WeatherApp", "WeatherApp", nullptr));
        cityNameLabel->setText(QApplication::translate("WeatherApp", "Type the city name:", nullptr));
        searchButton->setText(QApplication::translate("WeatherApp", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherApp: public Ui_WeatherApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERAPP_H
