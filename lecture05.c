#include <stdio.h>

int print_how_to_play_screen(){
	
	
	printf("################################\n");
	printf("##                            ##\n");	
	printf("##       To Avoid Enemy       ##\n");	
	printf("##                            ##\n");	
	printf("##  Press Space Bar to Jump   ##\n");	
	printf("##                            ##\n");	
	printf("################################\n");
	return 0;
		
}

int print_title_screen()
{
	printf("################################\n");
	printf("##                            ##\n");	
	printf("##          Dino Run          ##\n");	
	printf("##            V.0.1           ##\n");	
	printf("##                            ##\n");	
	printf("##                            ##\n");	
	printf("## 1. Start Game              ##\n");	
	printf("## 2. How to play             ##\n");	
	printf("## 3. Exit                    ##\n");	
	printf("##                            ##\n");	
	printf("################################\n");
	
	return 0;
}
int main(){
	int ans = 0;
	int menu = 1;
	while(menu){
		print_title_screen();
		printf("input>");
		scanf("%d", &menu);
		if(menu==2){
			while(menu){
				print_how_to_play_screen();
				printf("return to menu? (1.Yes 2.No)");
				scanf("%d", &menu);
				if(menu == 1){
				break;
				}
				else if(menu == 2){
				continue;
				}
			}
		}
		else if(menu==3){
			break;
		}
		else{
			continue;
		}
	}

}
