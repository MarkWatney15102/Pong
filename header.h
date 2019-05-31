#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void clrscr();
void gotoxy();
void menu();
void startgame();
void createPlayer_1();
void createPlayer_2();
void movePlayer();
void createBall();
bool inField();
void nextPlayer2Pos();
void updateBall();
bool checkIfHit();
void gameOver();

int player_1_cord = 7;
int player_2_cord = 7;

int ball_x = 39;
int ball_y = 15;
int ball_direction = 1;
