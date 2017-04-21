#include "robot.h"

void moveIcon(int orgX, int orgY, int targetX, int targetY, int dir, QGraphicsItemAnimation* rb){

    QTimeLine* timeLine = new QTimeLine;
    timeLine->setDuration(500); //Duration of the step.

    rb->setTimeLine(timeLine);
    rb->item()->setRotation((dir-1)*90);    //Set the absolute angle at step1
    rb->setPosAt(0, QPoint((orgX-1)*STEP+OFFSET, (8-orgY)*STEP+OFFSET));    //Set position at step0
    rb->setPosAt(1, QPoint((targetX-1)*STEP+OFFSET, (8-targetY)*STEP+OFFSET));  //Set position at step1

     timeLine->start();

    // Wait til the animation over.
    QTimer t;
    t.start(500);
    QEventLoop loop;
    QObject::connect(&t, SIGNAL(timeout()), &loop, SLOT(quit()));
    loop.exec();
}

void setPose(int x, int y, char dir, Pose* object, QGraphicsItem * rb){
    object->x = x;
    object->y = y;
    switch(dir){
        case 'N':
            object->dir = 0;
            rb->setRotation(-90);
            break;
        case 'E':
            object->dir = 1;
            rb->setRotation(0);
            break;
        case 'S':
            object->dir = 2;
            rb->setRotation(90);
            break;
        case 'W':
            object->dir = 3;
            rb->setRotation(180);
            break;
    }
    // Update the icon position
    rb->setPos((object->x-1)*STEP+OFFSET, (8-object->y)*STEP+OFFSET);
}


bool robotMove(char move, Pose* robot, QGraphicsItemAnimation * rb){

    //Turns
    if(move == 'L' || move == 'R' || move == 'l' || move == 'r'){
        int nextDir = 0;
        if(move == 'L' || move =='l'){
            nextDir = robot->dir - 1;
        }else if(move == 'R' || move == 'r'){
            nextDir = robot->dir + 1;
        }
        if(nextDir < 0) nextDir+=4;
        nextDir = nextDir % 4;

        if(rb!=NULL)    //if wanna move icon on the board.
            moveIcon(robot->x,robot->y, robot->x,robot->y, nextDir, rb);

        //Update robot pose
        robot->dir = nextDir;

    }else if(move == 'M' || move == 'm'){
    //Move Forward
        int nextX = robot->x + moves[robot->dir];
        int nextY = robot->y + moves[(robot->dir+1)%4];

        if( nextX == 0 || nextX > BOARDSIZE || nextY ==0 || nextY > BOARDSIZE){
            if(rb!=NULL)    //Only display when moving icon
                qDebug() << "Invalid Move : Bump in the wall\n";
            return false;
        }else{
            if(rb!=NULL) //if wanna move icon on the board.
                moveIcon(robot->x, robot->y, nextX, nextY ,robot->dir, rb );

            //Update robot pose.
            robot->x = nextX;
            robot->y = nextY;
        }
    }else{
        if(rb!=NULL)    //Only display when moving icon
            qDebug() << "Invalid Move : Unrecognized Command.\n";
        return false;
    }
    return true;
}



void dfs(std::vector<std::vector<char> > &routes, std::vector<char> &candidate, Pose*robot, Pose*dst, int stepCnt, int maxStep){

    if( stepCnt > maxStep )	return; //Exceed maxStep, return

    if(*robot == *dst){    //Reach destination, legal route
        routes.push_back(candidate);
    }

    Pose lastPose;
    for (int i = 0; i < (int) strlen(commands); i++){
        lastPose = *robot;
        if(!robotMove(commands[i], robot)) continue;   //if move invalid, continue.
        candidate.push_back(commands[i]);
        dfs(routes, candidate, robot, dst, stepCnt+1, maxStep );
        *robot = lastPose;
        candidate.pop_back();
    }
    return;
}

