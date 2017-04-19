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

static int maxCnt;

std::vector< std::vector<char> > routes;

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
    if(move == 'L' || move == 'R'){
        if(move == 'L'){
            robot->dir--;
        }else if(move == 'R'){
            robot->dir++;
        }
        if(robot->dir < 0) robot->dir+=4;
        robot->dir = robot->dir % 4;
    }else if(move == 'M'){
        int futureX = robot->x + moves[robot->dir];
        int futureY = robot->y + moves[(robot->dir+1)%4];
        if( futureX == 0 || futureX == BOARDSIZE || futureY ==0 || futureY == BOARDSIZE){
            fprintf(stderr, "Invalid Move : Bump in the wall");
            return false;
        }else{
            robot->x = futureX;
            robot->y = futureY;
        }
    }else{
        fprintf(stderr,"Invalid Move : Unrecognized Command.");
        return false;
    }
    return true;
        // printf("Robot: (%d, %d, %d) \n", robot.x, robot.y, robot.dir);
}


//void dfs(int cnt, std::vector<std::vector<char> > &routes, std::vector<char> &candidate){
//    if( cnt > maxCnt )	return;

//     for (int i = 0; i < (int)strlen(movements); i++){
//        int orignX = robot.x;
//        int orignY = robot.y;
//        int orignDir = robot.dir;
//        move(movements[i]);
//        candidate.push_back(movements[i]);
//        // dfs(routes, &candidate, robot.x, robot.y, robot.dir, )
//     }

//     return;
//}


