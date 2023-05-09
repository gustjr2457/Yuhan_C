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
int main()
{
	
	int game_state = 1;
	char map[465]; /* 가로 : 30 + 1 (개행문자) 세로 : 15 */

	int i = 0;
	while(i<465)
	{
		map[i]='0';
		if(i % 31 == 0)
			map[i]='\n';
		i = i + 1;
	}
	map[i] = '\0';
	printf("%s",map);
	return 0;

	
}
