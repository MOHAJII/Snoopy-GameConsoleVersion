#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "../utils/asciart.h"

#define COLONNE 21
#define LIGNE 10
#define PLAYER 0x2
#define OBSTACLE 'X'
#define MOVABLE_BLOC 'H'
#define TELEPORT_POINT 0x4
#define COIN 0xE
#define BORDER 0x0DB
#define EMPTY ' '
#define BALL 0xF

typedef struct
{
    int x;
    int y;
} Cordonee;

typedef struct
{
    Cordonee position;
    int lives;
} Player;

typedef struct
{
    Cordonee position;
    Cordonee direction;
} Ball;

typedef struct
{
    Cordonee position;
    int movable; 
} MovableBlock;

Player player;
Ball ball;
clock_t startTime;
int gameOver, win, nbrCoins, timer, score , paused;
char * label;
char matrix[LIGNE + 2][COLONNE + 2];

void setup();
void drawGame();
void levelLabel(char *label);
void updatePlayer();
void pausegame();
void updateBall();
void checkCoins(int x, int y);
void setConsoleColor(int colorCode);
void saveScore();
void displayScoreTable();
void collision();
void addObstacle(int x, int y);
void addMouvableBlock(int x, int y);
void moveBlock(int fromX, int fromY, int toX, int toY);
void teleport(int *x,int *y);
void addteleportBlock(int x,int y);

#endif
