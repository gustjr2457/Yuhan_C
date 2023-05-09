#include <stdio.h>


int game_start(){
	int b = 0;	
	char map[30][15];
	while(b<16){
		for(int a=0; a<31; a++){
			map[a][b] = '@';
			if(a % 30 == 0){
				printf("%s", map);
				map[a][b] = '\n';
				a = 0;
			}
			a++;
		}
		b++;
	}
	
	printf("%s", map);
	return 0;
}





int main(){

	int b = 0;
	int a = 0;	
	char map[30][15];
	while(b<16){
		while(a<31){
			map[a][b] = '#';
			a++;
		}
		b++;
	}
	
	printf("%s", map);
	
	
}

