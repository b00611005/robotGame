#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include <QDir>
//#include "robot.cpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList directions;
    directions<<"N"<<"E"<<"S"<<"W";
    ui->comboBox_Direction->addItems(directions);

//    QImage image("/Users/mickie/Documents/Qt Porject/robotGame/img.jpeg");
      QImage image("../img.jpeg");
    scene = new QGraphicsScene(this);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    setPose(ui->spinBoxIniX->value(), ui->spinBoxIniY->value(),
            ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot);
    printf("Robot: (%d, %d, %d)\n", this->robot.x, this->robot.y, this->robot.dir);
    fflush(stdout);
    QStringList moves = ui->textEdit_moves->toPlainText().split(',');
    for(int i = 0; i < moves.length(); i++){
        robotMove(moves.at(i).toStdString()[0], &this->robot);
    }
    printf("Final Robot: (%d, %d, %d)\n", this->robot.x, this->robot.y, this->robot.dir);
    fflush(stdout);
}

