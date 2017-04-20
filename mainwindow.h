#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimeline>
#include <QGraphicsItemAnimation>
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
    void on_pushButton_clicked();

    void on_pushButton_CalRoutes_clicked();

    void on_GUIsetPoseButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsItem *robotIcon;
    Pose robot;
    Pose destination;
    //Animation
    QTimeLine* timeLine;
    QGraphicsItemAnimation *robotAnimation;

    static int maxCnt;
};

#endif // MAINWINDOW_H
