#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include "string"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ComboBox Setup
    QStringList directions;
    directions<<"N"<<"E"<<"S"<<"W";
    ui->comboBox_Direction->addItems(directions);
    ui->comboBox_Direction_2->addItems(directions);
    ui->comboBox_FinalDir->addItems(directions);

    //TableView Setup
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    //Load images
    QImage bgImg(":/src/img/board.png");
    QImage robotImg(":/src/img/pacman.png");
    QImage dstImg(":/src/img/star.png");
    bgImg = bgImg.scaledToHeight(450);
    robotImg = robotImg.scaledToHeight(40);
    dstImg = dstImg.scaledToHeight(40);

    this->robotIcon = new QGraphicsPixmapItem(QPixmap::fromImage(robotImg));
    this->dstIcon = new QGraphicsPixmapItem(QPixmap::fromImage(dstImg));
    QGraphicsPixmapItem* bg = new QGraphicsPixmapItem(QPixmap::fromImage(bgImg));

    scene = new QGraphicsScene(this);
    scene->addItem(bg);
    scene->addItem(this->robotIcon);
    scene->addItem(this->dstIcon);


    robotIcon->setTransformOriginPoint(20,20);
    dstIcon->setTransformOriginPoint(20,20);
    setPose(ui->spinBoxIniX->value(),ui->spinBoxIniY->value(),ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot,this->robotIcon);
    setPose(ui->spinBoxIniX->value(),ui->spinBoxIniY->value(),ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot,this->dstIcon);

//    robotIcon->setFlag(QGraphicsItem::ItemIsMovable);
    ui->graphicsView->setScene(scene);

    //GUI Elements Visable Setup.
    ui->GUIsetPoseButton->setVisible(false);
    dstIcon->setVisible(false);

    //Animation Initialization
    robotAnimation = new QGraphicsItemAnimation;
    robotAnimation->setItem(robotIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    setPose(ui->spinBoxIniX->value(), ui->spinBoxIniY->value(),
            ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);

    qDebug() << "Robot: ( " << this->robot.x << ", " << this->robot.y << ", " << this->robot.dir <<")\n";
    QString moves = ui->textEdit_moves->toPlainText();
    moves.replace(" ", "");
    QStringList cmds = ui->textEdit_moves->toPlainText().split(',');

    for(int i = 0; i < cmds.length(); i++){
        robotMove(cmds.at(i).toStdString()[0], &this->robot, this->robotAnimation);
    }
    qDebug() << "Final Robot: ( " << this->robot.x << ", " << this->robot.y << ", " << this->robot.dir <<")\n";
}


void MainWindow::on_pushButton_CalRoutes_clicked()
{
    std::vector<char> candidate;
    std::vector< std::vector<char> > routes;

    //Set Poses
    setPose(ui->spinBoxIniX_2->value(), ui->spinBoxIniY_2->value(),
            ui->comboBox_Direction_2->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);
    setPose(ui->spinBoxFinalX->value(), ui->spinBoxFinalY->value(),
            ui->comboBox_FinalDir->currentText().toStdString().c_str()[0],&this->destination, this->dstIcon);

    //Calculate posible routes
    dfs(routes, candidate, &this->robot, &this->destination, 0, ui->spinBox_maxSteps->value());

    //Display the result on the table
    ui->tableWidget->setRowCount(routes.size());
    for(int i = 0; i < (int) routes.size(); i++){
        std::string temp;
        for(int j = 0; j < (int) routes[i].size(); j++){
            temp+=routes[i][j];
        }
        ui->tableWidget->setItem(i-1,1, new QTableWidgetItem(QString::fromStdString(temp)));
    }

    qDebug() << "Calculatoin Done: %d\n";
}

void MainWindow::on_GUIsetPoseButton_clicked()
{
    //Update the icon poses.
    if(ui->tabWidget->currentIndex() == 0){
        setPose(ui->spinBoxIniX->value(), ui->spinBoxIniY->value(),
                ui->comboBox_Direction->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);
    }else{
        setPose(ui->spinBoxIniX_2->value(), ui->spinBoxIniY_2->value(),
                ui->comboBox_Direction_2->currentText().toStdString().c_str()[0],&this->robot, this->robotIcon);
        setPose(ui->spinBoxFinalX->value(), ui->spinBoxFinalY->value(),
                ui->comboBox_FinalDir->currentText().toStdString().c_str()[0],&this->destination, this->dstIcon);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if( index ==0)
        this->dstIcon->setVisible(false);
    else
        this->dstIcon->setVisible(true);

    //Update the icon position
    this->on_GUIsetPoseButton_clicked();
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    //Reset the pose of icons.
    this->on_GUIsetPoseButton_clicked();

    //Move icons based on the moves.
    std::string moves = ui->tableWidget->item(index.row(), 0)->text().toStdString();
    for(int i = 0; i < (int)moves.length(); i++){
        robotMove(moves.at(i), &this->robot, this->robotAnimation);
    }
}
