#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define WIDTH 60
#define HEIGHT 35
#define BUILDING_SIZE 2
#define NUM_BUILDINGS 3

char title[30][80];
int MainGameScreen[HEIGHT][WIDTH];

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void GotoXYZero() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void BackGround(int PlayerX, int PlayerY) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y == 0 || y == (HEIGHT - 1))
				MainGameScreen[y][x] = 0;
			else if (x == 0 || x == (WIDTH - 1))
				MainGameScreen[y][x] = 0;
			else if (x == PlayerX && y == PlayerY)
				MainGameScreen[y][x] = 2;
			else
				MainGameScreen[y][x] = 1;
		}
	}
	
	for (int n = 0; n < NUM_BUILDINGS; n++) {
		int startX = rand() % (WIDTH - BUILDING_SIZE);
		int startY = rand() % (HEIGHT - BUILDING_SIZE);

		for (int i = 0; i < BUILDING_SIZE; i++) {
			for (int j = 0; j < BUILDING_SIZE; j++) {
				MainGameScreen[startY + i][startX + j] = 3;
			}
		}
	}
}	

void BackGroundString() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (MainGameScreen[y][x] == 0)
				printf("\x1b[47m \x1b[0m");
			else if (MainGameScreen[y][x] == 1)
				printf("\x1b[40m \x1b[0m");
			else if (MainGameScreen[y][x] == 2)
				printf("\x1b[42m \x1b[0m");
			else if (MainGameScreen[y][x] == 3)
				printf("\x1b[46m \x1b[0m");
			else if (MainGameScreen[y][x] == 4)
				printf("\x1b[45m \x1b[0m");
		}
		printf("\n");
	}
}

void start_screen() {
	hideCursor();
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 29)
				title[i][j] = '-';
			else if (j == 0 || j == 78)
				title[i][j] = '|';
			else
				title[i][j] = '#';
			if ((i == 0 && j == 0) || (i == 29 && j == 78) ||
				(i == 0 && j == 78) || (i == 29 && j == 0))
				title[i][j] = '@';
		}
		title[i][79] = '\n';
	}
	title[29][79] = '\0';
	for (int i = 1; i < 29; i++) {
		for (int j = 1; j < 78; j++) {
			title[i][j] = ' ';
			GotoXYZero();
		}
		printf("%s\n", title);
		Sleep(16);
	}
}

void screen_reset() {
	hideCursor();
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 29)
				title[i][j] = '-';
			else if (j == 0 || j == 78)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 29 && j == 78) ||
				(i == 0 && j == 78) || (i == 29 && j == 0))
				title[i][j] = '@';
		}
		title[i][79] = '\n';
	}
	title[29][79] = '\0';
}

void InsertString(const char* string, int y) {
	int length = strlen(string);
	int middle = (80 - (length + 1)) / 2;
	for (int a = 0; a < length; a++) {
		title[y][a + middle] = string[a];
	}
	GotoXYZero();
	printf("%s\n", title);
	Sleep(16);
}

void game_screen(int choose) {
	hideCursor();
	if (choose == 1) {
		screen_reset();
		InsertString("Dancing without the professor knowing", 10);
		InsertString("1.Start", 16);
		InsertString("2.Help", 17);
		InsertString("3.Exit", 18);
	}
	else if (choose == 2) {
		screen_reset();
		InsertString("Press the space bar to dance", 10);
		InsertString("when the professor is not watching!", 11);
		InsertString("Return to Main Screen?(1.yes/2. no)", 18);
	}
	else if (choose == 3) {
		screen_reset();
		InsertString("input number 1 to exit", 15);
	}
}




int main() {
	int type1 = 1;
	int type2 = 0;

	system("mode con cols=100 lines=40");
	system("cls");
	start_screen();
	while (type1) {
		game_screen(1);
		type1 = getch() - '0';
		if (type1 == 1) {
			int pX = 1;
			int pY = 1;
			int ch;
			srand(time(NULL));
			system("mode con cols=61 lines=36");
			while (true) {
				BackGround(pX, pY);
				BackGroundString();
				hideCursor();
				GotoXYZero();

				if (GetAsyncKeyState('W') & 0x8000) {
					if (pY != 1)
						pY--;
				}
				else if (GetAsyncKeyState('A') & 0x8000) {
					if (pX > 2)
						pX = pX - 2;
					if (pX <= 2)
						pX = 1;
				}
				else if (GetAsyncKeyState('S') & 0x8000) {
					if (pY != (HEIGHT - 2))
						pY++;
				}
				else if (GetAsyncKeyState('D') & 0x8000) {
					if (pX < (WIDTH - 3))
						pX = pX + 2;
					if (pX >= (WIDTH - 3))
						pX = WIDTH - 2;
				}
			}
		}
		else if (type1 == 2) {
			type2 = 1;
			while (type2) {
				GotoXYZero();
				game_screen(2);
				type2 = getch() - '0';
				if (type2 == 1) {
					GotoXYZero();
					type2 = 0;
				}
				else
					type2 = 1;
			}
		}
		else if (type1 == 3) {
			screen_reset();
			game_screen(3);
			type2 = getch() - '0';
			if (type2 == 1) {
				system("cls");
				type1 = 0;
			}
			else
				GotoXYZero();
			continue;
		}
		else {
			GotoXYZero();
			continue;
		}
	}
	return 0;
}
