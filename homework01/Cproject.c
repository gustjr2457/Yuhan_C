#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define WIDTH 60
#define HEIGHT 35

char title[30][80];
int MainGameScreen[HEIGHT][WIDTH];
int DunGeonScreen[HEIGHT + 10][WIDTH];


struct Monster {
	int atk;
	int hp;
} monster;

void monsterstat(int mon) {
	if (mon == 0) {
		monster.atk = 10;
		monster.hp = 20;
		// Slime
	}
	else if (mon == 1) {
		monster.atk = 15;
		monster.hp = 30;
		// Pig
	}
	else if (mon == 2) {
		monster.atk = 8;
		monster.hp = 20;
		// MushRoom
	}
}

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void GotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void BackGround(int PlayerX, int PlayerY) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y == 0 || y == (HEIGHT - 1))
				MainGameScreen[y][x] = 1;
			else if (x == 0 || x == (WIDTH - 1))
				MainGameScreen[y][x] = 1;
			else
				MainGameScreen[y][x] = 2;
		}
	}
	for (int y = 20; y < 22; y++) {
		for (int x = 20; x < 22; x++) {
			MainGameScreen[y - 15][x + 5] = 4; // y = 5, 6 x = 25, 26
			MainGameScreen[y - 5][x + 20] = 5; // y = 15, 16 x = 40, 41
			MainGameScreen[y + 5][x - 5] = 6; // y = 25, 26 x = 15, 16
		}
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (x == PlayerX && y == PlayerY)
				MainGameScreen[y][x] = 3;
		}
	}


}

void BackGroundString() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (MainGameScreen[y][x] == 1)
				printf("\x1b[47m \x1b[0m");
			else if (MainGameScreen[y][x] == 2)
				printf("\x1b[40m \x1b[0m");
			else if (MainGameScreen[y][x] == 3)
				printf("\x1b[101m \x1b[0m");
			else if (MainGameScreen[y][x] == 4)
				printf("\x1b[44mD\x1b[0m"); // 던전 y = 5, 6 x = 25, 26
			else if (MainGameScreen[y][x] == 5)
				printf("\x1b[45mS\x1b[0m"); // 상점 y = 15, 16 x = 40, 41
			else if (MainGameScreen[y][x] == 6)
				printf("\x1b[46mE\x1b[0m"); // 게임종료 y = 25, 26 x = 15, 16
		}
		printf("\n");
	}
}

void start_screen() {
	hideCursor();
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 29)
				title[i][j] = '-';
			else if (j == 0 || j == 78)
				title[i][j] = '|';
			else
				title[i][j] = '#';
			if ((i == 0 && j == 0) || (i == 29 && j == 78) ||
				(i == 0 && j == 78) || (i == 29 && j == 0))
				title[i][j] = '@';
		}
		title[i][79] = '\n';
	}
	title[29][79] = '\0';
	for (int i = 1; i < 29; i++) {
		for (int j = 1; j < 78; j++) {
			title[i][j] = ' ';
			GotoXY(0, 0);
		}
		printf("%s\n", title);
		Sleep(16);
	}
}

void screen_reset() {
	hideCursor();
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 80; j++) {
			if (i == 0 || i == 29)
				title[i][j] = '-';
			else if (j == 0 || j == 78)
				title[i][j] = '|';
			else
				title[i][j] = ' ';
			if ((i == 0 && j == 0) || (i == 29 && j == 78) ||
				(i == 0 && j == 78) || (i == 29 && j == 0))
				title[i][j] = '@';
		}
		title[i][79] = '\n';
	}
	title[29][79] = '\0';
}

void InsertString(const char* string, int y) {
	int length = strlen(string);
	int middle = (80 - (length + 1)) / 2;
	for (int a = 0; a < length; a++) {
		title[y][a + middle] = string[a];
	}
	GotoXY(0, 0);
	printf("%s\n", title);
}

void game_screen(int choose) {
	hideCursor();
	if (choose == 1) {
		screen_reset();
		InsertString("RPG", 10);
		InsertString("1.Start", 16);
		InsertString("2.Help", 17);
		InsertString("3.Exit", 18);
	}
	else if (choose == 2) {
		screen_reset();
		InsertString("Press the W,A,S,D keys to move the character", 10);
		InsertString("Press F to enter the portal and fight monsters!", 11);
		InsertString("Return to Main Screen?(1.yes/2. no)", 18);
	}
	else if (choose == 3) {
		screen_reset();
		InsertString("input number 1 to exit", 15);
	}
	else if (choose == 4) {
		screen_reset();
		InsertString("Choose your Character!", 10);
		InsertString("1.Warrior", 16);
		InsertString("2.Archor", 17);
		InsertString("3.Magician", 18);
		printf("\x1b[0minput> ");
	}
	else if (choose == 5) {
		screen_reset();
		InsertString("Press E to exit", 15);
		InsertString("Press B to return to the game", 17);
	}
	else if (choose == 6) {
		screen_reset();
		InsertString("Press H = MAXHP Enhance(+10): 20Gold", 12);
		InsertString("Press J = ATK Enhance(+5): 20Gold", 13);
		InsertString("Press R = Resurrection: 30Gold", 14);
		InsertString("Press B to return to the game", 20);
	}
	else if (choose == 7) {
		screen_reset();
		InsertString("Are you sure you want to buy this item?", 12);
		InsertString("(Y/N)", 16);
	}
	else if (choose == 8) {
		screen_reset();
		InsertString("You purchased the item successfully!", 12);
	}
	else if (choose == 9) {
		screen_reset();
		InsertString("You don't have enough money!", 12);
	}
	else if (choose == 10) {
		screen_reset();
		InsertString("You cannot enter due to lack of HP.", 12);
	}
	else if (choose == 11) {
		screen_reset();
		InsertString("Game Over..", 12);
	}
	else if (choose == 12) {
		screen_reset();
		InsertString("You cannot purchase this item.", 12);
	}
}
void DunGeonScreenReset() {
	for (int y = 0; y < HEIGHT + 10; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y == 0 || y == ((HEIGHT + 10) - 1))
				DunGeonScreen[y][x] = 0;
			else if (x == 0 || x == ((WIDTH)-1))
				DunGeonScreen[y][x] = 0;
			else if ((y == 30 || y == 37) || (y > 30 && x == (WIDTH / 2)))
				DunGeonScreen[y][x] = 0;
			else
				DunGeonScreen[y][x] = 1;
		}
	}
}

void Dungeon(int* plaatk, int* plahp, int* playermhp, int* plamoney) {
	hideCursor();
	int gametype, montype, starthp, platype, playing;
	gametype = 1;
	starthp = *playermhp;
	while (gametype) {
		srand(time(NULL));
		montype = rand() % 3;
		Sleep(1000);
		DunGeonScreenReset();
		if (montype == 0) {
			monsterstat(0); //slime
			for (int y = 10; y <= 20; y++) {
				for (int x = 19; x <= 39; x++) {
					if ((y == 10 && x == 29) || (y == 11 && x == 28) || (y == 11 && x == 30)
						|| (y == 11 && x == 27) || (y == 11 && x == 31) || (y == 12 && x == 26)
						|| (y == 12 && x == 32) || (y == 13 && x == 25) || (y == 13 && x == 33)
						|| (y == 14 && x == 24) || (y == 14 && x == 34) || (y == 15 && x == 25)
						|| (y == 15 && x == 33)) {
						DunGeonScreen[y][x] = 2;
						DunGeonScreen[y][x - 1] = 2;
						DunGeonScreen[y][x + 1] = 2;
					}
					if (y == 15) {
						if (x > 24 && x < 32) {
							DunGeonScreen[y][x] = 2;
						}
					}
				}
			}
			DunGeonScreen[13][27] = 3;
			DunGeonScreen[13][26] = 0;
			DunGeonScreen[13][31] = 3;
			DunGeonScreen[13][32] = 0;
			for (int y = 0; y < HEIGHT + 10; y++) {
				for (int x = 0; x < WIDTH; x++) {
					if (DunGeonScreen[y][x] == 0)
						printf("\x1b[47m \x1b[0m");
					else if (DunGeonScreen[y][x] == 1)
						printf("\x1b[40m \x1b[0m");
					else if (DunGeonScreen[y][x] == 2)
						printf("\x1b[46m \x1b[0m");
					else if (DunGeonScreen[y][x] == 3)
						printf("\x1b[41m \x1b[0m");
				}
				printf("\n");
			}
			while (true) {
				GotoXY(1, 1);
				printf("Monster HP: %d", monster.hp);
				GotoXY(1, 2);
				printf("Monster ATK: %d", monster.atk);
				GotoXY(1, 3);
				printf("Player HP: %d", *plahp);
				GotoXY(1, 4);
				printf("Player ATK: %d", *plaatk);
				GotoXY(1, 5);
				printf("Money: %d", *plamoney);
				GotoXY(10, 33);
				printf("1. Attack");
				GotoXY(41, 33);
				printf("2. Heal");
				GotoXY(10, 40);
				printf("3. Bag");
				GotoXY(41, 40);
				printf("4. Run");
				playing = getch() - '0';
				if (playing == 1) {
					monster.hp -= *plaatk;
					playing = 0;
					GotoXY(18, 27);
					printf("Player attacked monster!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                        ");
				}
				else if (playing == 2) {
					*plahp += 10;
					if (plahp >= starthp) {
						*plahp = starthp;
					}
					playing = 0;
					GotoXY(18, 27);
					printf("Player has healed!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                    ");
				}
				else if (playing == 3) {
					GotoXY(18, 27);
					printf("Not implemented!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                   ");
					continue;
					playing = 0;
				}
				else if (playing == 4) {
					int a = rand() % 4;
					if (a == 0 || a == 1 || a == 2) {
						GotoXY(15, 27);
						printf("You have successfully escaped!");
						Sleep(1500);
						GotoXY(15, 27);
						printf("                              ");
						gametype = 0;
						break;
					}
					else if (a == 3) {
						GotoXY(18, 27);
						printf("You couldn't escape!");
						Sleep(1500);
						GotoXY(18, 27);
						printf("                              ");
					}
					playing = 0;
				}
				else {
					continue;
				}
				if (monster.hp <= 0) {
					GotoXY(18, 27);
					printf("The monster is down!");
					Sleep(2000);
					*plamoney += 10;
					GotoXY(18, 27);
					printf("                     ");
					break;
				}
				*plahp -= monster.atk;
				GotoXY(18, 27);
				printf("Monster attacked Player!");
				Sleep(1500);
				GotoXY(18, 27);
				printf("                          ");
				if (monster.hp <= 10 && monster.hp > 0) {
					GotoXY(1, 1);
					printf("               ");
				}
				if (*plahp < 100) {
					GotoXY(1, 3);
					printf("                        ");
				}
				if (*plahp <= 0) {
					GotoXY(26, 27);
					printf("You Died!");
					*plahp = 0;
					Sleep(1500);
					gametype = 0;
					break;
				}
			}
		}
		else if (montype == 1) {
			monsterstat(1); //zombie
			for (int y = 10; y <= 17; y++) {
				for (int x = 23; x <= 35; x++) {
					DunGeonScreen[y][x] = 4;
				}
			}
			DunGeonScreen[13][24] = 3;
			DunGeonScreen[13][25] = 3;
			DunGeonScreen[13][26] = 3;
			DunGeonScreen[13][32] = 3;
			DunGeonScreen[13][33] = 3;
			DunGeonScreen[13][34] = 3;
			for (int y = 0; y < HEIGHT + 10; y++) {
				for (int x = 0; x < WIDTH; x++) {
					if (DunGeonScreen[y][x] == 0)
						printf("\x1b[47m \x1b[0m");
					else if (DunGeonScreen[y][x] == 1)
						printf("\x1b[40m \x1b[0m");
					else if (DunGeonScreen[y][x] == 2)
						printf("\x1b[46m \x1b[0m");
					else if (DunGeonScreen[y][x] == 3)
						printf("\x1b[41m \x1b[0m");
					else if (DunGeonScreen[y][x] == 4)
						printf("\x1b[42m \x1b[0m");
				}
				printf("\n");
			}
			while (true) {
				GotoXY(1, 1);
				printf("Monster HP: %d  ", monster.hp);
				GotoXY(1, 2);
				printf("Monster ATK: %d  ", monster.atk);
				GotoXY(1, 3);
				printf("Player HP: %d", *plahp);
				GotoXY(1, 4);
				printf("Player ATK: %d", *plaatk);
				GotoXY(1, 5);
				printf("Money: %d", *plamoney);
				GotoXY(10, 33);
				printf("1. Attack");
				GotoXY(41, 33);
				printf("2. Heal");
				GotoXY(10, 40);
				printf("3. Bag");
				GotoXY(41, 40);
				printf("4. Run");
				playing = getch() - '0';
				if (playing == 1) {
					monster.hp -= *plaatk;
					playing = 0;
					GotoXY(18, 27);
					printf("player attacked monster!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                        ");
				}
				else if (playing == 2) {
					*plahp += 10;
					if (*plahp >= starthp) {
						*plahp = starthp;
					}
					playing = 0;
					GotoXY(18, 27);
					printf("player has healed!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                    ");
				}
				else if (playing == 3) {
					GotoXY(18, 27);
					printf("Not implemented!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                   ");
					continue;
					playing = 0;
				}
				else if (playing == 4) {
					int a = rand() % 4;
					if (a == 0 || a == 1 || a == 2) {
						GotoXY(15, 27);
						printf("You have successfully escaped!");
						Sleep(1500);
						GotoXY(15, 27);
						printf("                              ");
						gametype = 0;
						break;
					}
					else if (a == 3) {
						GotoXY(18, 27);
						printf("You couldn't escape!");
						Sleep(1500);
						GotoXY(18, 27);
						printf("                              ");
					}
					playing = 0;
				}
				else {
					continue;
				}
				if (monster.hp <= 0) {
					GotoXY(18, 27);
					printf("The monster is down!");
					Sleep(2000);
					*plamoney += 10;
					GotoXY(18, 27);
					printf("                     ");
					GotoXY(1, 5);
					printf("                     ");
					break;
				}
				*plahp -= monster.atk;
				GotoXY(18, 27);
				printf("Monster attacked Player!");
				Sleep(1500);
				GotoXY(18, 27);
				printf("                          ");
				if (monster.hp <= 10 && monster.hp > 0) {
					GotoXY(1, 1);
					printf("               ");
				}
				if (*plahp < 100) {
					GotoXY(1, 3);
					printf("                        ");
				}
				if (*plahp <= 0) {
					GotoXY(26, 27);
					printf("You Died!");
					*plahp = 0;
					Sleep(1500);
					gametype = 0;
					break;
				}
			}
		}
		else if (montype == 2) {
			monsterstat(2); //MushRoom
			for (int y = 10; y <= 17; y++) {
				for (int x = 20; x <= 38; x++) {
					DunGeonScreen[y][x] = 5;
					if (y == 16 && (35 >= x && x >= 23))
						DunGeonScreen[y][x] = 1;
					if (y == 15 && (x == 23 || x == 35))
						DunGeonScreen[y][x] = 1;
				}
			}
			for (int y = 12; y <= 14; y++) {
				for (int x = 24; x <= 26; x++) {
					if (y == 13 && x == 25) {
						DunGeonScreen[y][x] = 0;
					}
					else
						DunGeonScreen[y][x] = 1;
				}
				for (int x2 = 32; x2 <= 34; x2++) {
					if (y == 13 && x2 == 33) {
						DunGeonScreen[y][x2] = 0;
					}
					else
						DunGeonScreen[y][x2] = 1;
				}
			}

			for (int y = 0; y < HEIGHT + 10; y++) {
				for (int x = 0; x < WIDTH; x++) {
					if (DunGeonScreen[y][x] == 0)
						printf("\x1b[47m \x1b[0m");
					else if (DunGeonScreen[y][x] == 1)
						printf("\x1b[40m \x1b[0m");
					else if (DunGeonScreen[y][x] == 2)
						printf("\x1b[46m \x1b[0m");
					else if (DunGeonScreen[y][x] == 3)
						printf("\x1b[41m \x1b[0m");
					else if (DunGeonScreen[y][x] == 4)
						printf("\x1b[42m \x1b[0m");
					else if (DunGeonScreen[y][x] == 5)
						printf("\x1b[43m \x1b[0m");
				}
				printf("\n");
			}
			while (true) {
				GotoXY(1, 1);
				printf("Monster HP: %d", monster.hp);
				GotoXY(1, 2);
				printf("Monster ATK: %d", monster.atk);
				GotoXY(1, 3);
				printf("Player HP: %d", *plahp);
				GotoXY(1, 4);
				printf("Player ATK: %d", *plaatk);
				GotoXY(1, 5);
				printf("Money: %d", *plamoney);
				GotoXY(10, 33);
				printf("1. Attack");
				GotoXY(41, 33);
				printf("2. Heal");
				GotoXY(10, 40);
				printf("3. Bag");
				GotoXY(41, 40);
				printf("4. Run");
				playing = getch() - '0';
				if (playing == 1) {
					monster.hp -= *plaatk;
					playing = 0;
					GotoXY(18, 27);
					printf("player attacked monster!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                        ");
				}
				else if (playing == 2) {
					*plahp += 10;
					if (*plahp >= starthp) {
						*plahp = starthp;
					}
					playing = 0;
					GotoXY(18, 27);
					printf("player has healed!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                    ");
				}
				else if (playing == 3) {
					GotoXY(18, 27);
					printf("Not implemented!");
					Sleep(1500);
					GotoXY(18, 27);
					printf("                   ");
					continue;
					playing = 0;
				}
				else if (playing == 4) {
					int a = rand() % 4;
					if (a == 0 || a == 1 || a == 2) {
						GotoXY(15, 27);
						printf("You have successfully escaped!");
						Sleep(1500);
						GotoXY(15, 27);
						printf("                              ");
						gametype = 0;
						break;
					}
					else if (a == 3) {
						GotoXY(18, 27);
						printf("You couldn't escape!");
						Sleep(1500);
						GotoXY(18, 27);
						printf("                              ");
					}
					playing = 0;
				}
				else {
					continue;
				}
				if (monster.hp <= 0) {
					GotoXY(18, 27);
					printf("The monster is down!");
					Sleep(2000);
					*plamoney += 10;
					GotoXY(18, 27);
					printf("                     ");
					GotoXY(1, 5);
					printf("                     ");
					break;
				}
				*plahp -= monster.atk;
				GotoXY(18, 27);
				printf("Monster attacked Player!");
				Sleep(1500);
				GotoXY(18, 27);
				printf("                          ");
				if (monster.hp <= 10 && monster.hp > 0) {
					GotoXY(1, 1);
					printf("               ");
				}
				if (*plahp < 100) {
					GotoXY(1, 3);
					printf("                        ");
				}
				if (*plahp <= 0) {
					GotoXY(26, 27);
					printf("You Died!");
					Sleep(1500);
					*plahp = 0;
					gametype = 0;
					break;
				}
			}
		}
	}
}



int main() {
	int type1 = 1;
	int type2 = 0;
	int type3 = 1;
	int ChooseCharacter, PlayerHP, PlayerATK, PlayerMaxHP;
	int PlayerMoney = 0;
	int* playerhp = &PlayerHP;
	int* playeratk = &PlayerATK;
	int* playermaxhp = &PlayerMaxHP;
	int* playermoney = &PlayerMoney;
	system("mode con cols=80 lines=32");
	system("cls");
	start_screen();
	while (type1) { //메인메뉴
		game_screen(1);
		type1 = getch() - '0';
		int pX = 1;
		int pY = 1;
		int pick = 1;
		if (type1 == 1) {
			while (pick) { //캐릭터선택창
				game_screen(4);
				scanf("%d", &ChooseCharacter);
				if (ChooseCharacter == 1) {
					PlayerATK = 10;
					PlayerHP = 90; //전사
					PlayerMaxHP = 90;
				}
				else if (ChooseCharacter == 2) {
					PlayerATK = 13;
					PlayerHP = 80; //궁수
					PlayerMaxHP = 80;
				}
				else if (ChooseCharacter == 3) {
					PlayerATK = 15;
					PlayerHP = 70; //마법사
					PlayerMaxHP = 70;
				}
				else {
					continue;
				}
				break;
			}
			while (type3) { //게임시작
				system("mode con cols=61 lines=36");
				BackGround(pX, pY);
				BackGroundString();
				hideCursor();
				GotoXY(0, 0);
				if (GetAsyncKeyState('W') & 0x8000) {
					if (pY != 1)
						pY--;
				}
				else if (GetAsyncKeyState('A') & 0x8000) {
					if (pX > 2)
						pX = pX - 2;
					if (pX <= 2)
						pX = 1;
				}
				else if (GetAsyncKeyState('S') & 0x8000) {
					if (pY != (HEIGHT - 2))
						pY++;
				}
				else if (GetAsyncKeyState('D') & 0x8000) {
					if (pX < (WIDTH - 3))
						pX = pX + 2;
					if (pX >= (WIDTH - 3))
						pX = WIDTH - 2;
				}
				if ((pY == 5 && pX == 25) || (pY == 5 && pX == 26) || (pY == 6 && pX == 25)
					|| (pY == 6 && pX == 26)) {
					if (GetAsyncKeyState(VK_SPACE) & 0x8000) { // 던전
						if (PlayerHP <= 0) {
							system("mode con cols=80 lines=32");
							game_screen(10);
							Sleep(2000);
							continue;
						}
						else
							while (true) {
								system("mode con cols=61 lines=46");
								GotoXY(0, 0);
								Dungeon(playeratk, playerhp, playermaxhp, playermoney);
								break;
							}
					}
				}
				if ((pY == 25 && pX == 15) || (pY == 25 && pX == 16) || (pY == 26 && pX == 15)
					|| (pY == 26 && pX == 16)) {
					if (GetAsyncKeyState(VK_SPACE) & 0x8000) { // 게임종료
						GotoXY(0, 0);
						system("cls");
						system("mode con cols=80 lines=32");
						game_screen(5);
						while (true) {
							if (GetAsyncKeyState('E') & 0x8000) {
								return 0;
							}
							else if (GetAsyncKeyState('B') & 0x8000) {
								break;
							}
						}
					}
				}
				if ((pY == 15 && pX == 40) || (pY == 15 && pX == 41) || (pY == 16 && pX == 40)
					|| (pY == 16 && pX == 41)) { // 상점 y = 15, 16 x = 40, 41
					if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
						GotoXY(0, 0);
						system("cls");
						system("mode con cols=80 lines=32");
						while (true) {
							game_screen(6);
							GotoXY(1, 1);
							printf("money: %dGold", PlayerMoney);
							Sleep(16);
							if (GetAsyncKeyState('H') & 0x8000) {
								while (true) {
									game_screen(7);
									Sleep(16);
									if (GetAsyncKeyState('Y') & 0x8000) {
										if (PlayerMoney >= 15) {
											if (PlayerHP != PlayerMaxHP)
												PlayerMaxHP += 10;
											else {
												PlayerHP += 10;
												PlayerMaxHP += 10;
											}
											PlayerMoney -= 15;
											game_screen(8);
											Sleep(1500);
										}
										else {
											game_screen(9);
											Sleep(1500);
										}
										break;
									}
									else if (GetAsyncKeyState('N') & 0x8000) {
										break;
									}
								}
							}
							if (GetAsyncKeyState('J') & 0x8000) {
								while (true) {
									game_screen(7);
									Sleep(16);
									if (GetAsyncKeyState('Y') & 0x8000) {
										if (PlayerMoney >= 15) {
											game_screen(8);
											Sleep(1500);
											PlayerATK += 5;
											PlayerMoney -= 15;
										}
										else {
											game_screen(9);
											Sleep(1500);
										}
										break;
									}
									else if (GetAsyncKeyState('N') & 0x8000) {
										break;
									}
								}
							}
							if (GetAsyncKeyState('R') & 0x8000) {
								while (true) {
									game_screen(7);
									Sleep(16);
									if (GetAsyncKeyState('Y') & 0x8000) {
										if (PlayerHP > 0) {
											game_screen(12);
											Sleep(1500);
											break;
										}
										else {
											if (PlayerMoney >= 25) {
												game_screen(8);
												Sleep(1500);
												PlayerHP = PlayerMaxHP;
												PlayerMoney -= 25;
											}
											else {
												game_screen(9);
												Sleep(1500);
												game_screen(11);
												Sleep(1500);
												return 0;
											}
										}
										break;
									}
									else if (GetAsyncKeyState('N') & 0x8000) {
										break;
									}
								}
							}
							if (GetAsyncKeyState('B') & 0x8000) {
								break;
							}
						}
					}

				}
			}
		}
		else if (type1 == 2) {
			type2 = 1;
			while (type2) {
				GotoXY(0, 0);
				game_screen(2);
				type2 = getch() - '0';
				if (type2 == 1) {
					GotoXY(0, 0);
					type2 = 0;
				}
				else
					type2 = 1;
			}
		}
		else if (type1 == 3) {
			screen_reset();
			game_screen(3);
			type2 = getch() - '0';
			if (type2 == 1) {
				system("cls");
				type1 = 0;
			}
			else
				GotoXY(0, 0);
			continue;
		}
		else {
			GotoXY(0, 0);
			continue;
		}
	}
	return 0;
}
