#include<stdio.h>

int main(){
	int damage;
	int mhp = 30;
	printf("공격력을 입력하세요: ");
	scanf("%d", &damage);
	printf("주인공의 공격력은 %d입니다.\n", damage);
	if(damage==mhp){
		printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n\n",damage);
		printf("적의 잔여 HP : %d\n\n", mhp-damage);
		printf("적을 물리쳤습니다!\nHappy End\n");
		}
	else if(damage<mhp){
		printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다,\n\n",damage);
		printf("적의 잔여 HP : %d\n\n",mhp-damage);
		printf("적이 주인공을 공격하여 주인공이 뒤졌습니다.\nGame Over\n");
	}
	else if(damage>mhp){
		printf("주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n\n",damage);
		printf("적의 잔여 HP : 0\n\n");
		printf("적을 물리쳤습니다!\nHappy End");
	}
}

