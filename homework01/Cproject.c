#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(){
	int type1 = 1;
	int type2 = 0;
	char main[5] = "Main";
	char help[5] = "Help";
	char exit[5] = "Exit";
	char title[15][40];
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
	}
	while(type1){
		game_screen(main);
		scanf("%d", &type1);
		if (type1 == 3){
			system("cls");
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

