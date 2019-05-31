#include "header.h"

int main(int argc, char** argv) {
	srand((unsigned)time(NULL));
	menu();
	
	getch();
	return 0;
}

void gotoxy (int x, int y)
{
    COORD coord;
    coord.X = x - 1; 
	coord.Y = y - 1; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu()
{
	// Build Menu
	Sleep(500);
	startgame();
}

void startgame()
{
	createPlayer_1();
	createPlayer_2();
	createBall();
	movePlayer();
}

bool inField(int y)
{
	if(y >= 20 || y <= 1)
		return true;
		
	return false;
}


void movePlayer()
{
	int player1, player2;
	while(1)
	{
		switch((player1 = getch()))
		{
			case 72:
			case 119:
				//UP
				player_1_cord--;
				if(inField(player_1_cord)) {
					player_1_cord++;
				}
				createPlayer_1();
				nextPlayer2Pos();
				updateBall();
				break;
			case 80:
			case 115:
				//Down
				player_1_cord++;
				if(inField(player_1_cord)) {
					player_1_cord--;
				}
				createPlayer_1();
				nextPlayer2Pos();
				updateBall();
				break;
		}
	}
}

void createPlayer_1()
{
	for(int i = 1; i <= 25; i++)
	{
		gotoxy(2, i);
		cout << " ";
	}
	
	gotoxy(2, player_1_cord);
	cout << "I";
	gotoxy(2, player_1_cord + 1);
	cout << "I";
	gotoxy(2, player_1_cord + 2);
	cout << "I";
	gotoxy(2, player_1_cord + 3);
	cout << "I";
	gotoxy(2, player_1_cord + 4);
	cout << "I";
	gotoxy(2, player_1_cord + 5);
	cout << "I";
}

void createPlayer_2()
{
	for(int i = 1; i <= 25; i++)
	{
		gotoxy(78, i);
		cout << " ";
	}
	
	gotoxy(78, player_2_cord);
	cout << "I";
	gotoxy(78, player_2_cord + 1);
	cout << "I";
	gotoxy(78, player_2_cord + 2);
	cout << "I";
	gotoxy(78, player_2_cord + 3);
	cout << "I";
	gotoxy(78, player_2_cord + 4);
	cout << "I";
	gotoxy(78, player_2_cord + 5);
	cout << "I";
}

void nextPlayer2Pos()
{
	int option;
	option = (rand() % 100) + 1;
	if(option >= 51) {
		// Up
		player_2_cord--;
		if(inField(player_2_cord))
		{
			player_2_cord++;
		}
		
		createPlayer_2();
	}else if(option <= 50) {
		// Up
		player_2_cord++;
		if(inField(player_2_cord))
		{
			player_2_cord--;
		}
		
		createPlayer_2();
	}
}

void createBall()
{
	gotoxy(ball_x, ball_y);
	cout << "O";
}

void updateBall()
{
	gotoxy(ball_x, ball_y);
	cout << " ";
	
	if(ball_direction == 1)	
	{
		ball_x--;
		if(!checkIfHit()) {
			gotoxy(ball_x, ball_y);
			cout << "0";	
		}else {
			//
			gameOver();
		}
		
	}else if(ball_direction == 2)	
	{
		ball_x++;
		if(!checkIfHit()) {
			gotoxy(ball_x, ball_y);
			cout << "0";	
		}else {
			gameOver();
		}
		cout << "0";
	}
}

bool checkIfHit()
{
	if(ball_x == 2)
		return true;
}

void gameOver()
{
	exit(0);
}

void clrscr()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets the window handle
    COORD coord = {0, 0}; // sets coordinates to 0,0
    DWORD count;
    
   	CONSOLE_SCREEN_BUFFER_INFO csbi;
   	GetConsoleScreenBufferInfo(hStdOut, &csbi); // gets the buffer info (screen) 
   	
    // fill all characters as ' ' (empty the screen)
    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
    
    // resets the cursor position
    SetConsoleCursorPosition(hStdOut, coord);
}	 


