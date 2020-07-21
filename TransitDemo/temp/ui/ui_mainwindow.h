/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTextEdit *TE_message;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *LE_sourceIP;
    QLabel *label_2;
    QLineEdit *LE_sourcePort;
    QLabel *label_3;
    QLineEdit *LE_targetIP;
    QLabel *label_4;
    QLineEdit *LE_targetPort;
    QLabel *label_5;
    QLineEdit *LE_hostPort;
    QSpacerItem *verticalSpacer;
    QPushButton *PB_reset;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(434, 366);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TE_message = new QTextEdit(centralWidget);
        TE_message->setObjectName(QStringLiteral("TE_message"));

        gridLayout_2->addWidget(TE_message, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        LE_sourceIP = new QLineEdit(centralWidget);
        LE_sourceIP->setObjectName(QStringLiteral("LE_sourceIP"));

        gridLayout->addWidget(LE_sourceIP, 0, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        LE_sourcePort = new QLineEdit(centralWidget);
        LE_sourcePort->setObjectName(QStringLiteral("LE_sourcePort"));

        gridLayout->addWidget(LE_sourcePort, 1, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        LE_targetIP = new QLineEdit(centralWidget);
        LE_targetIP->setObjectName(QStringLiteral("LE_targetIP"));

        gridLayout->addWidget(LE_targetIP, 2, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        LE_targetPort = new QLineEdit(centralWidget);
        LE_targetPort->setObjectName(QStringLiteral("LE_targetPort"));

        gridLayout->addWidget(LE_targetPort, 3, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        LE_hostPort = new QLineEdit(centralWidget);
        LE_hostPort->setObjectName(QStringLiteral("LE_hostPort"));

        gridLayout->addWidget(LE_hostPort, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        PB_reset = new QPushButton(centralWidget);
        PB_reset->setObjectName(QStringLiteral("PB_reset"));

        verticalLayout->addWidget(PB_reset);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\272\220\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\272\220\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\270\255\345\277\203\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\270\255\345\277\203\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\345\244\207\347\224\250\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        PB_reset->setText(QApplication::translate("MainWindow", "\351\203\250\347\275\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
