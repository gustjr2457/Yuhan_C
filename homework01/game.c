#include <stdio.h>
#include "game.h"

void game_main(){
	char title[15][40];
	char gs[38] = "Dancing without the professor knowing";
	char st[8] = "1.Start";
	char He[7] = "2.Help";
	char Ex[7] = "3.Exit";
	for (int i = 0; i < 15; i ++){
		for (int j = 0; j < 40; j++){
			if (i == 0 || i == 14)
				title[i][j] = '-';
			else if (j == 0 || j == 38)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 14 && j == 38) ||
				(i == 0 && j == 38) || (i == 14 && j == 0))
				title[i][j] = '@';
		}
		title[i][39] = '\n';
	}
	for (int i = 0; i <= 36; i++) 
		title[5][i+1] = gs[i];
	for (int i = 0; i <= 6; i++)
		title[8][i+16] = st[i];
	for (int i = 0; i <= 5; i++)
		title[9][i+16] = He[i];
	for (int i = 0; i <= 5; i++)
		title[10][i+16] = Ex[i];

	title[14][39] = '\0';
	printf("%s\n", title);
}
void game_help() {
	char title[15][40];
	char first[29] = "Press the space bar to dance";
	char next[36] = "when the professor is not watching!";
	char mid[36] = "Return to Main Screen?(1.yes/2. no)";
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == 0 || i == 14)
				title[i][j] = '-';
			else if (j == 0 || j == 38)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 14 && j == 38) ||
				(i == 0 && j == 38) || (i == 14 && j == 0))
				title[i][j] = '@';
		}
		title[i][39] = '\n';
	}
	for (int i = 0; i <= 27; i++) 
		title[5][i + 6] = first[i];
	for (int i = 0; i <= 34; i++)
		title[6][i + 2] = next[i];
	for (int i = 0; i <= 34; i++) 
		title[9][i + 2] = mid[i];
	title[14][39] = '\0';
	printf("%s\n", title);
}

void game_exit(){
	char title[15][40];
	char close[23] = "input number 1 to exit";
	for (int i = 0; i < 15; i ++){
		for (int j = 0; j < 40; j++){
			if (i == 0 || i == 14)
				title[i][j] = '-';
			else if (j == 0 || j == 38)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 14 && j == 38) ||
				(i == 0 && j == 38) || (i == 14 && j == 0))
				title[i][j] = '@';
		}
		title[i][39] = '\n';
	}
	for (int i = 0; i <= 21; i++){
		title[7][i+8] = close[i];
	}

	title[14][39] = '\0';
	printf("%s\n", title);
}

