#ifndef ROBOT_H
#define ROBOT_H

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


//method
void setPose(int, int, char, Pose*);
bool robotMove(char, Pose*);
void dfs(std::vector<std::vector<char> > &routes, std::vector<char> &candidate,int cnt);
#endif // ROBOT_H
