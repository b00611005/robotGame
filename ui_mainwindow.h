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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QTabWidget *tabWidget;
    QWidget *tab;
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
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QSpinBox *spinBoxIniY_2;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinBoxIniX_2;
    QComboBox *comboBox_Direction_2;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBox_FinalDir;
    QSpinBox *spinBoxFinalX;
    QLabel *label_11;
    QSpinBox *spinBoxFinalY;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_CalRoutes;
    QTableWidget *tableWidget;
    QLabel *label_14;
    QSpinBox *spinBox_maxSteps;
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
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 500, 500));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(530, 20, 361, 481));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 331, 291));
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
        textEdit_moves->setGeometry(QRect(30, 120, 281, 121));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 131, 30));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 250, 81, 32));
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 331, 440));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(175, 50, 61, 20));
        label_6->setFont(font1);
        spinBoxIniY_2 = new QSpinBox(groupBox_2);
        spinBoxIniY_2->setObjectName(QStringLiteral("spinBoxIniY_2"));
        spinBoxIniY_2->setGeometry(QRect(120, 50, 48, 24));
        spinBoxIniY_2->setMinimum(1);
        spinBoxIniY_2->setMaximum(8);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(96, 50, 21, 21));
        label_7->setFont(font);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 50, 21, 21));
        label_8->setFont(font);
        spinBoxIniX_2 = new QSpinBox(groupBox_2);
        spinBoxIniX_2->setObjectName(QStringLiteral("spinBoxIniX_2"));
        spinBoxIniX_2->setGeometry(QRect(30, 50, 48, 24));
        spinBoxIniX_2->setMinimum(1);
        spinBoxIniX_2->setMaximum(8);
        comboBox_Direction_2 = new QComboBox(groupBox_2);
        comboBox_Direction_2->setObjectName(QStringLiteral("comboBox_Direction_2"));
        comboBox_Direction_2->setGeometry(QRect(237, 46, 71, 31));
        comboBox_Direction_2->setFont(font2);
        comboBox_Direction_2->setEditable(false);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 26, 131, 20));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 90, 131, 20));
        comboBox_FinalDir = new QComboBox(groupBox_2);
        comboBox_FinalDir->setObjectName(QStringLiteral("comboBox_FinalDir"));
        comboBox_FinalDir->setGeometry(QRect(241, 106, 71, 31));
        comboBox_FinalDir->setFont(font2);
        comboBox_FinalDir->setEditable(false);
        spinBoxFinalX = new QSpinBox(groupBox_2);
        spinBoxFinalX->setObjectName(QStringLiteral("spinBoxFinalX"));
        spinBoxFinalX->setGeometry(QRect(34, 110, 48, 24));
        spinBoxFinalX->setMinimum(1);
        spinBoxFinalX->setMaximum(8);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(14, 110, 21, 21));
        label_11->setFont(font);
        spinBoxFinalY = new QSpinBox(groupBox_2);
        spinBoxFinalY->setObjectName(QStringLiteral("spinBoxFinalY"));
        spinBoxFinalY->setGeometry(QRect(124, 110, 48, 24));
        spinBoxFinalY->setMinimum(1);
        spinBoxFinalY->setMaximum(8);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(179, 110, 61, 20));
        label_12->setFont(font1);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(100, 110, 21, 21));
        label_13->setFont(font);
        pushButton_CalRoutes = new QPushButton(groupBox_2);
        pushButton_CalRoutes->setObjectName(QStringLiteral("pushButton_CalRoutes"));
        pushButton_CalRoutes->setGeometry(QRect(200, 160, 113, 32));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 210, 311, 221));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(13, 139, 130, 20));
        spinBox_maxSteps = new QSpinBox(groupBox_2);
        spinBox_maxSteps->setObjectName(QStringLiteral("spinBox_maxSteps"));
        spinBox_maxSteps->setGeometry(QRect(30, 160, 48, 24));
        spinBox_maxSteps->setMinimum(1);
        spinBox_maxSteps->setMaximum(99);
        tabWidget->addTab(tab_2, QString());
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

        tabWidget->setCurrentIndex(0);


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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        label_6->setText(QApplication::translate("MainWindow", "Direction:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_8->setText(QApplication::translate("MainWindow", "X: ", 0));
        comboBox_Direction_2->setCurrentText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Robot Initial Pose", 0));
        label_10->setText(QApplication::translate("MainWindow", "Robot Final Pose", 0));
        comboBox_FinalDir->setCurrentText(QString());
        label_11->setText(QApplication::translate("MainWindow", "X: ", 0));
        label_12->setText(QApplication::translate("MainWindow", "Direction:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Y:", 0));
        pushButton_CalRoutes->setText(QApplication::translate("MainWindow", "Calculate", 0));
        label_14->setText(QApplication::translate("MainWindow", "Maximum Steps", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
