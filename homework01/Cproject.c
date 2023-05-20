#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(){
	int type1 = 1;
	int type2 = 0;
	char main[5] = "Main";
	char help[5] = "Help";
	char exit[5] = "Exit";
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

