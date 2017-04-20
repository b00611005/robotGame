#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include <QDir>
#include <QStandardItemModel>
#include "string"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    QImage robot("/Users/mickie/Documents/Qt Porject/robotGame/android_robot.png");
    background = background.scaledToHeight(450);
    robot = robot.scaledToHeight(50);
    QGraphicsPixmapItem* bgd = new QGraphicsPixmapItem(QPixmap::fromImage(background));
    QGraphicsPixmapItem* robot1 = new QGraphicsPixmapItem(QPixmap::fromImage(robot));
    scene = new QGraphicsScene(this);
    robot1->setPos(15,15);
    scene->addItem(bgd);
    scene->addItem(robot1);
    robot1->setFlag(QGraphicsItem::ItemIsMovable);

    QPen blackpen(Qt::black);
    QBrush redBrush(Qt::red);
    blackpen.setWidth(6);
    QGraphicsRectItem* rect1 = scene->addRect(8,8,40,40,blackpen,redBrush);
    rect1->setFlag(QGraphicsItem::ItemIsMovable);

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


void MainWindow::on_pushButton_CalRoutes_clicked()
{
    std::vector<char> candidate;
    std::vector< std::vector<char> > routes;

    //Set Poses
    setPose(ui->spinBoxIniX_2->value(), ui->spinBoxIniY_2->value(),
            ui->comboBox_Direction_2->currentText().toStdString().c_str()[0],&this->robot);
    setPose(ui->spinBoxFinalX->value(), ui->spinBoxFinalY->value(),
            ui->comboBox_FinalDir->currentText().toStdString().c_str()[0],&this->destination);
    dfs(routes, candidate, &this->robot, &this->destination, 0, ui->spinBox_maxSteps->value());
    ui->tableWidget->setRowCount(routes.size());
    for(int i = 0; i < routes.size(); i++){
        std::string temp;
        for(int j = 0; j < routes[i].size(); j++){
            temp+=routes[i][j];
        }
        ui->tableWidget->setItem(i-1,1, new QTableWidgetItem(QString::fromStdString(temp)));
    }
    printf("Calculatoin Done: %d\n", routes.size());
    fflush(stdout);
}
