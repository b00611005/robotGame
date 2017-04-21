#ifndef ROBOT_H
#define ROBOT_H
#include <QTimeLine>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>

//Spec of the board
#define STEP 56
#define OFFSET 10
#define BOARDSIZE 8

static const int moves[5] = {0, 1, 0, -1, 0};
static const char commands[3] = {'L','R','M'};

struct Pose{
    int x;
    int y;
    int dir;
    bool operator==(const Pose rhs)
    {
        if(this->x == rhs.x && this->y == rhs.y && this->dir == rhs.dir)
           return true;
        else
            return false;
    }
};



//Methods

void setPose(int, int, char, Pose*, QGraphicsItem*);

bool robotMove(char, Pose*, QGraphicsItemAnimation* rb = NULL);

void dfs(std::vector<std::vector<char> >&, std::vector<char>&, Pose*, Pose*, int, int);


//Animation Zone

void moveIcon(Pose* target, QGraphicsItemAnimation* rb);

#endif // ROBOT_H
