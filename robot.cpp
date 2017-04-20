#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "vector"
#define BOARDSIZE 8

struct Pose{
    int x;
    int y;
    int dir;
};

static const int moves[5] = {0, 1, 0, -1, 0};

static const char movements[3] = {'L','R','M'};

//static int maxCnt;

//std::vector< std::vector<char> > routes;

void copyPose(Pose orign, Pose* target){
//    printf("(%d, %d, %d)\n", orign->x,orign->y, orign->dir);
//    fflush(stdout);
//    int x = target->x;
//    orign->x = x;
    target->x = orign.x;
    target->y = orign.y;
    target-> dir = orign.dir;
//    printf("(%d, %d, %d)\n", orign.x,orign.y, orign.dir);
//    fflush(stdout);
}

bool comparePose(Pose* orign, Pose* target){
    if(orign->x == target->x && orign->y == target->y && orign->dir == target->dir)
        return true;
    else
        return false;
}

void setPose(int x, int y, char dir, Pose* object){
    object->x = x;
    object->y = y;
    switch(dir){
        case 'N':
            object->dir = 0;
            break;
        case 'E':
            object->dir = 1;
            break;
        case 'S':
            object->dir = 2;
            break;
        case 'W':
            object->dir = 3;
            break;
    }
}


bool robotMove(char move, Pose* robot){
    //Turn
    if(move == 'L' || move == 'R' || move == 'l' || move == 'r'){
        if(move == 'L'){
            robot->dir--;
        }else if(move == 'R' || move == 'r'){
            robot->dir++;
        }
        if(robot->dir < 0) robot->dir+=4;
        robot->dir = robot->dir % 4;
    }else if(move == 'M' || move == 'm'){
        int futureX = robot->x + moves[robot->dir];
        int futureY = robot->y + moves[(robot->dir+1)%4];
        if( futureX == 0 || futureX == BOARDSIZE || futureY ==0 || futureY == BOARDSIZE){
//            fprintf(stderr, "Invalid Move : Bump in the wall\n");
            return false;
        }else{
            robot->x = futureX;
            robot->y = futureY;
        }
    }else{
//        fprintf(stderr,"Invalid Move : Unrecognized Command.\n");
        return false;
    }
    return true;
        // printf("Robot: (%d, %d, %d) \n", robot.x, robot.y, robot.dir);
}



void dfs(std::vector<std::vector<char> > &routes, std::vector<char> &candidate, Pose* robot, Pose* dest, int cnt, int maxCnt){
//    printf("Cnt: %d\n", cnt);
//    fflush(stdout);
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

