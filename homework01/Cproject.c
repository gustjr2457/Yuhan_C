﻿#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
	int type1 = 1;
	int type2 = 0;

	while(type1){
		game_main();
		int choice;
		printf("input> ");
		scanf("%d", &choice);
		if (choice == 3){
			system("cls");
			game_exit();
			printf("input> ");
			scanf("%d", &type2);
			if(type2 == 1)
				type1 = 0;
			else
				system("cls");
				continue;

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

