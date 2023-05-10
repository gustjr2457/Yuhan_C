#include <stdio.h>
#include <windows.h>

void game_main() {
	char title[15][40];
	char gs[9] = "Dino Run";
	char st[8] = "1.Start";
	char He[7] = "2.Help";
	char Ex[7] = "3.Exit";
	for (int i = 0; i< 15; i++) {
		for (int j = 0; j <40; j++) {
			if (i == 0 || i == 14)
				title[i][j] = '-';
			else if(j == 0 || j == 38)
				title[i][j] = '|';	
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 14 && j == 38) ||
				(i == 0 && j == 38) || (i == 14 && j == 0))
				title[i][j] = '@';
		}
		title[i][39] = '\n';
	}
	for (int i = 0; i <= 7; i++) {
		title[5][i + 16] = gs[i];
	}
	for (int i = 0; i <= 6; i++) {
		title[8][i + 16] = st[i];
	}
	for (int i = 0; i <= 5; i++) {
		title[9][i + 16] = He[i];
	}
	for (int i = 0; i <= 5; i++) {
		title[10][i + 16] = Ex[i];
	}

	
	title[14][39] = '\0';

	printf("%s\n", title);
}

void game_help() {
	char title[15][40];
	char first[29] = "Press the space bar to jump!";
	char mid[36] =   "Return to Main Screen?(1.yes/2. no)";
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
	for (int i = 0; i <= 26; i++) {
		title[5][i + 6] = first[i];
	}
	for (int i = 0; i <= 34; i++) {
		title[9][i + 2] = mid[i];
	}
	title[14][39] = '\0';
	printf("%s\n", title);
}

int main()
{
	int type1 = 1;
	int type2 = 0;
	char yn;
	while(type1){
		game_main();
		int choice;
		printf("input> ");
		scanf("%d", &choice);
		if (choice == 3){
			system("cls");
			type1 = 0;
		}
		else if (choice == 2){
			type2 = 1;
			while(type2){
				system("cls");
				game_help();
				printf("input> ");
				scanf("%d", &type2);
				if (type2 == 1){
					system("cls");
					type2 = 0;
				}
				else if (type2 != 1 && type2 != 2){
					system("cls");
					continue;
				}
			}
		}
		else {
			system("cls");
			continue;
		}
	}



}

