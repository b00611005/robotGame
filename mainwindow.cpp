#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include <QDir>
#include <QStandardItemModel>
#include <QThread>
#include "string"
#include <QGraphicsRotation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //PushButton setup
    ui->GUIsetPoseButton->setVisible(false);

    // comboBox setup
    QStringList directions;
    directions<<"N"<<"E"<<"S"<<"W";
    ui->comboBox_Direction->addItems(directions);
    ui->comboBox_Direction_2->addItems(directions);
    ui->comboBox_FinalDir->addItems(directions);

    //tableView
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //Background
    QImage background("/Users/mickie/Documents/Qt Porject/robotGame/board.png");
    QImage robot("/Users/mickie/Documents/Qt Porject/robotGame/pacman.png");
    background = background.scaledToHeight(450);
    robot = robot.scaledToHeight(40);

    QGraphicsPixmapItem* bgd = new QGraphicsPixmapItem(QPixmap::fromImage(background));
    this->robotIcon = new QGraphicsPixmapItem(QPixmap::fromImage(robot));
    scene = new QGraphicsScene(this);
    robotIcon->setTransformOriginPoint(20,20);
    setPose(ui->spinBoxIniX->value(),ui->spinBoxIniY->value(),ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot,this->robotIcon);
    scene->addItem(bgd);
    scene->addItem(robotIcon);
//    robotIcon->setFlag(QGraphicsItem::ItemIsMovable);

    //Animation Zone
//    timeLine = new QTimeLine;

    robotAnimation = new QGraphicsItemAnimation;
         robotAnimation->setItem(robotIcon);
         robotAnimation->setTranslationAt(0,0,0);
//         robotAnimation->setTimeLine(timeLine);
////              robotAnimation->setRotationAt(0, 0);
////              robotAnimation->setRotationAt(1, 90);
////         robotAnimation->setTranslationAt(0,0,0);
////         robotAnimation->setTranslationAt(1,0,-56);

//    timeLine->setUpdateInterval(40);
//    timeLine->setLoopCount(0);
//    timeLine->setCurveShape(QTimeLine::SineCurve);
//    timeLine->setDuration(1000);
//    timeLine->start();


    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    setPose(ui->spinBoxIniX->value(), ui->spinBoxIniY->value(),
            ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);
    printf("Robot: (%d, %d, %d)\n", this->robot.x, this->robot.y, this->robot.dir);
    fflush(stdout);
    QStringList moves = ui->textEdit_moves->toPlainText().split(',');

    for(int i = 0; i < moves.length(); i++){
        robotMove(moves.at(i).toStdString()[0], &this->robot, this->robotAnimation);
//        robotAnimation->setTranslationAt(0,0,0);
//        robotAnimation->setTranslationAt(1,robot);
    }
    printf("Final Robot: (%d, %d, %d)\n", this->robot.x, this->robot.y, this->robot.dir);
    fflush(stdout);
}


void MainWindow::on_pushButton_CalRoutes_clicked()
{
    std::vector<char> candidate;
    std::vector< std::vector<char> > routes;

    //Set Poses
    setPose(ui->spinBoxIniX_2->value(), ui->spinBoxIniY_2->value(),
            ui->comboBox_Direction_2->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);
    setPose(ui->spinBoxFinalX->value(), ui->spinBoxFinalY->value(),
            ui->comboBox_FinalDir->currentText().toStdString().c_str()[0],&this->destination, this->robotIcon);
    dfs(routes, candidate, &this->robot, &this->destination, 0, ui->spinBox_maxSteps->value());
    ui->tableWidget->setRowCount(routes.size());
    for(int i = 0; i < (int) routes.size(); i++){
        std::string temp;
        for(int j = 0; j < (int) routes[i].size(); j++){
            temp+=routes[i][j];
        }
        ui->tableWidget->setItem(i-1,1, new QTableWidgetItem(QString::fromStdString(temp)));
    }
    printf("Calculatoin Done: %d\n", (int)routes.size());
    fflush(stdout);
}

void MainWindow::on_GUIsetPoseButton_clicked()
{
    setPose(ui->spinBoxIniX->value(), ui->spinBoxIniY->value(),
            ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);

}
