#include <stdio.h>

int main(){
	int hp = 30;
	int damage;
	printf("데미지를 입력하세요: ");
	scanf("%d", &damage);
	printf("주인공의 공격력: %d\n\n", damage);
	printf("몬스터에게 %d의 데미지를 입혔습니다.\n", damage);
	if(damage>=hp){
		printf("몬스터의 남은 체력: 0 \n");
		printf("몬스터가 죽었습니다!\nHappy End\n");
	}
	else{
		printf("몬스터의 남은 체력: %d \n", hp-damage);
		printf("몬스터가 주인공을 공격하여 사망했습니다.\nGame Over\n");
	}
		
}
