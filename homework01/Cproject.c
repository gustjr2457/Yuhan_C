#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

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

char title[30][80];


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
				(i == 0 & j == 78) || (i == 29 && j == 0))
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
				(i == 0 & j == 78) || (i == 29 && j == 0))
				title[i][j] = '@';
		}
		title[i][79] = '\n';
	}
	title[29][79] = '\0';
}

void InsertString(const char* string, int y) {
	int length = strlen(string);
	int middle = (80 - (length + 1)) / 2;
	for (int a = 0; a <= (length - 1); a++) {
		title[y][a + middle] = string[a];
		GotoXYZero();
		printf("%s\ninput> ", title);
		Sleep(16);
	}
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
	
	system("mode con:cols=100 lines=40");
	system("cls");
	start_screen();
	while (type1) {
		game_screen(1);
		type1 = getch() - '0';
		if (type1 == 3) {
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
		else {
			GotoXYZero();
			continue;
		}
	}
	return 0;
}
