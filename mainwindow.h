#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimeline>
#include <QGraphicsItemAnimation>
#include <QTextBrowser>
#include "robot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_run_clicked();

    void on_pushButton_CalRoutes_clicked();

    void on_GUIsetPoseButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:

    //Methods
    void displayText(Pose pose, QString text, QTextBrowser* display);

    //Objects
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItem *robotIcon;
    QGraphicsItem *dstIcon;
    Pose robot;
    Pose destination;
    //Animation
    QTimeLine* timeLine;
    QGraphicsItemAnimation *robotAnimation;
    static int maxCnt;


};

#endif // MAINWINDOW_H
