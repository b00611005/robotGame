#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "vector"
#include <QDebug>
#include <QTimeLine>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>

#define BOARDSIZE 8
#define STEP 56
#define OFFSET 10

struct Pose{
    int x;
    int y;
    int dir;
};

static const int moves[5] = {0, 1, 0, -1, 0};

static const char movements[3] = {'L','R','M'};

void copyPose(Pose orign, Pose* target){

    target->x = orign.x;
    target->y = orign.y;
    target-> dir = orign.dir;

}

bool comparePose(Pose* orign, Pose* target){
    if(orign->x == target->x && orign->y == target->y && orign->dir == target->dir)
        return true;
    else
        return false;
}

void moveIcon(int orgX, int orgY, int targetX, int targetY, int orgDir, int dir, QGraphicsItemAnimation* rb){

    QTimeLine* timeLine = new QTimeLine;
//        rb->setRotationAt(0, orgDir);
//            if(dir == 1)
//               rb->setRotationAt(1, 90*dir);
//            else
//                rb->setRotationAt(1, 90*dir);
        rb->setTimeLine(timeLine);
//        qDebug()<<rb->xTranslationAt(0) <<rb->yTranslationAt(0);
//        rb->setTranslationAt(0, 0,0);
//        rb->setPosAt(1, QPoint((targetX-orgX)*STEP, -(targetY-orgY)*STEP));
                rb->setPosAt(0,QPoint(0,0));
        rb->setTranslationAt(1, 10,10);

            timeLine->setUpdateInterval(40);
            timeLine->setLoopCount(1);
            timeLine->setDuration(1000);
            timeLine->start();
}

void setPose(int x, int y, char dir, Pose* object, QGraphicsItem * rb){
    object->x = x;
    object->y = y;
    rb->setPos((object->x-1)*STEP+OFFSET, (8-object->y)*STEP+OFFSET);

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
            rb->setRotation(180);
            break;
        case 'W':
            object->dir = 3;
            rb->setRotation(270);
            break;
    }
}


bool robotMove(char move, Pose* robot, QGraphicsItemAnimation * rb = NULL){
    //Turn
    if(move == 'L' || move == 'R' || move == 'l' || move == 'r'){
        if(move == 'L' || move =='l'){
            robot->dir--;
        }else if(move == 'R' || move == 'r'){
            robot->dir++;
        }
        if(robot->dir < 0) robot->dir+=4;
        robot->dir = robot->dir % 4;

    }else if(move == 'M' || move == 'm'){
        int futureX = robot->x + moves[robot->dir];
        int futureY = robot->y + moves[(robot->dir+1)%4];
        if( futureX == 0 || futureX > BOARDSIZE || futureY ==0 || futureY > BOARDSIZE){
//            fprintf(stderr, "Invalid Move : Bump in the wall\n");
            return false;
        }else{
            moveIcon(robot->x,robot->y, futureX, futureY ,0 ,0, rb );
            robot->x = futureX;
            robot->y = futureY;
        }
    }else{
//        fprintf(stderr,"Invalid Move : Unrecognized Command.\n");
        return false;
    }
        // printf("Robot: (%d, %d, %d) \n", robot.x, robot.y, robot.dir);
    return true;
}



void dfs(std::vector<std::vector<char> > &routes, std::vector<char> &candidate, Pose* robot, Pose* dest, int cnt, int maxCnt){

    if(comparePose(robot, dest)){
        routes.push_back(candidate);
        return;
    }
    if( cnt > maxCnt )	return;
    Pose backup;
    for (int i = 0; i < (int)strlen(movements); i++){
        copyPose(*robot, &backup);
        robotMove(movements[i], robot);
        candidate.push_back(movements[i]);
        dfs(routes, candidate, robot, dest, cnt+1, maxCnt );
        copyPose(backup, robot);
        candidate.pop_back();
    }
    return;
}

