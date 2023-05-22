#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);	
}


void GotoXYZero(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
}

char title[15][40];
void InsertString(const char* string, int y){
	int length = strlen(string);
	int middle = (40-(length+1))/2;
	for (int a = 0; a <=(length-1); a++){
		title[y][a + middle] = string[a];
		GotoXYZero();
		printf("%sinput>", title);
	}
	Sleep(16);
	
}


void screen_reset(){
	for (int i=0; i<15; i++) {
		for (int j=0; j<40; j++){
			if (i == 0 || i == 14)
				title[i][j] = '-';
			else if (j == 0 || j == 38)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i==0 && j==0) || (i==14 && j==38) || 
				(i==0 & j==38) || (i==14 && j==0))
				title[i][j] = '@';
		}
		title[i][39] = '\n';
	}
	title[14][39] = '\0';
}

void game_screen(char* string) {

	if (string[0] == 'M') {
		system("cls");
		for (int i=0; i<15; i++) {
			for (int j=0; j<40; j++){
				if (i == 0 || i == 14)
					title[i][j] = '-';
				else if (j == 0 || j == 38)
					title[i][j] = '|';
				else
					title[i][j] = ' ';
				if ((i==0 && j==0) || (i==14 && j==38) || 
					(i==0 & j==38) || (i==14 && j==0))
					title[i][j] = '@';
			}
			title[i][39] = '\n';
		}
		InsertString("Dancing without the professor knowing", 5);
		InsertString("1.Start", 8);
		InsertString("2.Help", 9);
		InsertString("3.Exit", 10);
	}
	else if (string[0] == 'H') {
		for (int i=0; i<15; i++) {
			for (int j=0; j<40; j++){
				if (i == 0 || i == 14)
					title[i][j] = '-';
				else if (j == 0 || j == 38)
					title[i][j] = '|';
				else
					title[i][j] = ' ';
				if ((i==0 && j==0) || (i==14 && j==38) || 
					(i==0 & j==38) || (i==14 && j==0))
					title[i][j] = '@';
			}
			title[i][39] = '\n';
		}
		InsertString("Press the space bar to dance", 5);
		InsertString("when the professor is not watching!", 6);
		InsertString("Return to Main Screen?(1.yes/2. no)", 9);
	}
	else if (string[0] == 'E') { 
		for (int i=0; i<15; i++) {
			for (int j=0; j<40; j++){
				if (i == 0 || i == 14)
					title[i][j] = '-';
				else if (j == 0 || j == 38)
					title[i][j] = '|';
				else
					title[i][j] = ' ';
				if ((i==0 && j==0) || (i==14 && j==38) || 
					(i==0 & j==38) || (i==14 && j==0))
					title[i][j] = '@';
				}
				title[i][39] = '\n';
		}
		InsertString("input number 1 to exit", 7);
	}
	title[14][39] = '\0';	
}


int main(){
	int type1 = 1;
	int type2 = 0;
	char main[5] = "Main";
	char help[5] = "Help";
	char exit[5] = "Exit";
	hideCursor();
	while(type1){	
		game_screen(main);
		scanf("%d", &type1);
		if (type1 == 3){
			screen_reset();
			game_screen(exit);
			scanf("%d", &type2);
			if(type2 == 1)
				type1 = 0;
			else
				system("cls");
				continue;
		}
		else if (type1 == 2){
			type2 = 1;
			while(type2){
				system("cls");
				game_screen(help);
				scanf("%d", &type2);
				if (type2 == 1){
					system("cls");
					type2 = 0;
				}
				else
					type2 = 1;			
			}			
		}
		else{
			system("cls");
			continue;
		}
	}
}

