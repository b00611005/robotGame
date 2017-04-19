/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_Direction;
    QTextEdit *textEdit_moves;
    QLabel *label_5;
    QPushButton *pushButton;
    QSpinBox *spinBoxIniX;
    QSpinBox *spinBoxIniY;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(919, 570);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(530, 20, 331, 231));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 131, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 21, 21));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(106, 60, 21, 21));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 60, 61, 20));
        QFont font1;
        font1.setPointSize(13);
        label_4->setFont(font1);
        comboBox_Direction = new QComboBox(groupBox);
        comboBox_Direction->setObjectName(QStringLiteral("comboBox_Direction"));
        comboBox_Direction->setGeometry(QRect(240, 60, 71, 31));
        QFont font2;
        font2.setPointSize(12);
        comboBox_Direction->setFont(font2);
        comboBox_Direction->setEditable(false);
        textEdit_moves = new QTextEdit(groupBox);
        textEdit_moves->setObjectName(QStringLiteral("textEdit_moves"));
        textEdit_moves->setGeometry(QRect(30, 120, 281, 61));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 131, 30));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 190, 81, 32));
        spinBoxIniX = new QSpinBox(groupBox);
        spinBoxIniX->setObjectName(QStringLiteral("spinBoxIniX"));
        spinBoxIniX->setGeometry(QRect(40, 60, 48, 24));
        spinBoxIniX->setMinimum(1);
        spinBoxIniX->setMaximum(8);
        spinBoxIniY = new QSpinBox(groupBox);
        spinBoxIniY->setObjectName(QStringLiteral("spinBoxIniY"));
        spinBoxIniY->setGeometry(QRect(130, 60, 48, 24));
        spinBoxIniY->setMinimum(1);
        spinBoxIniY->setMaximum(8);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 500, 500));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        label->setText(QApplication::translate("MainWindow", "Robot Initial Pose", 0));
        label_2->setText(QApplication::translate("MainWindow", "X: ", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Direction:", 0));
        comboBox_Direction->setCurrentText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Movements", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
