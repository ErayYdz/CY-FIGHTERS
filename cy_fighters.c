#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#define MAX_BUFFER_SFZE 30

void segfunc(int signal, siginfo_t *si, void *arg){
	printf("Caught segfault address %p\n", si->si_addr);
	exit (0);
}

void presentation(){
	FILE * fp;
	fp = fopen("presentation.txt", "r");
	if(fp == NULL){
		printf("Error loading file.\n");
		exit (1);
	}
	char c;
	while ((c = fgetc(fp)) != EOF){
		putchar(c);
	}
	fclose(fp);
	printf("\n\n");
}

void displayFighters(){
	FILE * displayAllFighters;
	char c;
	displayAllFighters = fopen("fighters.txt", "r");
	if(displayAllFighters == NULL){
		printf("Error loading file.\n");
		exit (1);
	}
	while ((c = fgetc(displayAllFighters)) != EOF){
		putchar(c);
	}
	fclose(displayAllFighters);
}

void clear(){
	system("@cls||clear");
}

void clearScreen(){
	printf(" Enter 1 to clear the screen.\t");
	int pressedNum;
	scanf("%d", &pressedNum);
	switch(pressedNum){
		case 1:clear();
		break;
	}
}

void startPresentation(){
	FILE * fps;
	fps = fopen("startPresentation.txt", "r");
	if(fps == NULL){
		printf("Error loading file.\n");
		exit (1);
	}
	char c;
	while ((c = fgetc(fps)) != EOF){
		putchar(c);
	}
	fclose(fps);
	printf("\n\n");
}

int main(int argc, char * argv[]){
	
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = segfunc;
	sigaction(SIGSEGV, &sa, NULL);
	
	int pf1, pf2, pf3, cf1, cf2, cf3;
	int score;
	
	presentation();
	
	int diff;
	printf(" Choose the difficulty : (type the difficulty's number)\n\n");
	printf(" 1. Noob\t\t\t 2. Easy\t\t\t 3. Medium\t\t\t 4. Hard\n\n");
	printf(" Your difficulty ?\t");
	scanf("%d", &diff);
	
	displayFighters();
	srand(time(NULL));
	printf("\n\n Choose your 1st fighter : (type the fighter's number)\n\n");
	
	printf(" Your choice ?\t");
	scanf("%d",&pf1);
	if(pf1 < 1 || pf1 > 6){ //0
		printf(" Error.\n");
		exit(1);
	}
	else{
		printf(" You chose the fighter N° %d as your 1st fighter\n\n", pf1);
		do{
			cf1 = (rand()%6)+1;
		} while(cf1 == pf1); //1
		printf(" The Computer chose the fighter N° %d as its 1st fighter\n", cf1);
		printf("\n\n Choose your 2nd fighter : (type the fighter's number)\n\n");
		
		printf(" Your choice ?\t");
		scanf("%d",&pf2);
		if(pf2 < 1 || pf2 > 6 || pf2 == pf1 || pf2 == cf1){ //2
			printf(" Error.\n");
			exit(1);
		}
		else{
			printf(" You chose the fighter N° %d as your 2nd fighter\n\n", pf2);
			do{
				cf2 = (rand()%6)+1;
			} while(cf2 == pf1 || cf2 == pf2 || cf2 == cf1); //3
			printf(" The Computer chose the fighter N° %d as its 2nd fighter\n", cf2);
			printf("\n\n Choose your 3rd fighter : (type the fighter's number)\n\n");
			
			printf(" Your choice ?\t");
			scanf("%d",&pf3);
			if(pf3 < 1 || pf3 > 6 || pf3 == pf1 || pf3 == pf2 || pf3 == cf1 || pf3 == cf2){ //4
				printf(" Error.\n");
				exit(1);
			}
			else{
				printf(" You chose the fighter N° %d as your 3rd fighter\n\n", pf3);
				do{
					cf3 = (rand()%6)+1;
				} while(cf3 == pf1 || cf3 == pf2 || cf3 == pf3 || cf3 == cf1 || cf3 == cf2); //5
				printf(" The Computer chose the fighter N° %d as its 3rd fighter\n", cf3);
				printf("\n\n The teams are complete !\n\n");
			}
		}
	}
	
	FILE * Mediumpf1Name;
	FILE * Mediumpf1Hp;
	FILE * Mediumpf1HpMax;
	FILE * Mediumpf1Attack;
	FILE * Mediumpf1Defense;
	FILE * Mediumpf1Agility;
	FILE * Mediumpf1Speed;
	
	FILE * Mediumpf2Name;
	FILE * Mediumpf2Hp;
	FILE * Mediumpf2HpMax;
	FILE * Mediumpf2Attack;
	FILE * Mediumpf2Defense;
	FILE * Mediumpf2Agility;
	FILE * Mediumpf2Speed;
	
	FILE * Mediumpf3Name;
	FILE * Mediumpf3Hp;
	FILE * Mediumpf3HpMax;
	FILE * Mediumpf3Attack;
	FILE * Mediumpf3Defense;
	FILE * Mediumpf3Agility;
	FILE * Mediumpf3Speed;
	
	
	
	FILE * Noobcf1Name;
	FILE * Noobcf1Hp;
	FILE * Noobcf1HpMax;
	FILE * Noobcf1Attack;
	FILE * Noobcf1Defense;
	FILE * Noobcf1Agility;
	FILE * Noobcf1Speed;
	
	FILE * Noobcf2Name;
	FILE * Noobcf2Hp;
	FILE * Noobcf2HpMax;
	FILE * Noobcf2Attack;
	FILE * Noobcf2Defense;
	FILE * Noobcf2Agility;
	FILE * Noobcf2Speed;
	
	FILE * Noobcf3Name;
	FILE * Noobcf3Hp;
	FILE * Noobcf3HpMax;
	FILE * Noobcf3Attack;
	FILE * Noobcf3Defense;
	FILE * Noobcf3Agility;
	FILE * Noobcf3Speed;
	
	
	
	FILE * Easycf1Name;
	FILE * Easycf1Hp;
	FILE * Easycf1HpMax;
	FILE * Easycf1Attack;
	FILE * Easycf1Defense;
	FILE * Easycf1Agility;
	FILE * Easycf1Speed;
	
	FILE * Easycf2Name;
	FILE * Easycf2Hp;
	FILE * Easycf2HpMax;
	FILE * Easycf2Attack;
	FILE * Easycf2Defense;
	FILE * Easycf2Agility;
	FILE * Easycf2Speed;
	
	FILE * Easycf3Name;
	FILE * Easycf3Hp;
	FILE * Easycf3HpMax;
	FILE * Easycf3Attack;
	FILE * Easycf3Defense;
	FILE * Easycf3Agility;
	FILE * Easycf3Speed;
	
	
	
	FILE * Mediumcf1Name;
	FILE * Mediumcf1Hp;
	FILE * Mediumcf1HpMax;
	FILE * Mediumcf1Attack;
	FILE * Mediumcf1Defense;
	FILE * Mediumcf1Agility;
	FILE * Mediumcf1Speed;
	
	FILE * Mediumcf2Name;
	FILE * Mediumcf2Hp;
	FILE * Mediumcf2HpMax;
	FILE * Mediumcf2Attack;
	FILE * Mediumcf2Defense;
	FILE * Mediumcf2Agility;
	FILE * Mediumcf2Speed;
	
	FILE * Mediumcf3Name;
	FILE * Mediumcf3Hp;
	FILE * Mediumcf3HpMax;
	FILE * Mediumcf3Attack;
	FILE * Mediumcf3Defense;
	FILE * Mediumcf3Agility;
	FILE * Mediumcf3Speed;
	
	
	
	FILE * Hardcf1Name;
	FILE * Hardcf1Hp;
	FILE * Hardcf1HpMax;
	FILE * Hardcf1Attack;
	FILE * Hardcf1Defense;
	FILE * Hardcf1Agility;
	FILE * Hardcf1Speed;
	
	FILE * Hardcf2Name;
	FILE * Hardcf2Hp;
	FILE * Hardcf2HpMax;
	FILE * Hardcf2Attack;
	FILE * Hardcf2Defense;
	FILE * Hardcf2Agility;
	FILE * Hardcf2Speed;
	
	FILE * Hardcf3Name;
	FILE * Hardcf3Hp;
	FILE * Hardcf3HpMax;
	FILE * Hardcf3Attack;
	FILE * Hardcf3Defense;
	FILE * Hardcf3Agility;
	FILE * Hardcf3Speed;
	
	
	
	
	
	
	
	
	char SMediumpf1Name[MAX_BUFFER_SFZE];
	char SMediumpf1Hp[MAX_BUFFER_SFZE];
	float FMediumpf1Hp;
	char SMediumpf1HpMax[MAX_BUFFER_SFZE];
	float FMediumpf1HpMax;
	char SMediumpf1Attack[MAX_BUFFER_SFZE];
	float FMediumpf1Attack;
	char SMediumpf1Defense[MAX_BUFFER_SFZE];
	float FMediumpf1Defense;
	char SMediumpf1Agility[MAX_BUFFER_SFZE];
	float FMediumpf1Agility;
	char SMediumpf1Speed[MAX_BUFFER_SFZE];
	float FMediumpf1Speed;
	
	char SMediumpf2Name[MAX_BUFFER_SFZE];
	char SMediumpf2Hp[MAX_BUFFER_SFZE];
	float FMediumpf2Hp;
	char SMediumpf2HpMax[MAX_BUFFER_SFZE];
	float FMediumpf2HpMax;
	char SMediumpf2Attack[MAX_BUFFER_SFZE];
	float FMediumpf2Attack;
	char SMediumpf2Defense[MAX_BUFFER_SFZE];
	float FMediumpf2Defense;
	char SMediumpf2Agility[MAX_BUFFER_SFZE];
	float FMediumpf2Agility;
	char SMediumpf2Speed[MAX_BUFFER_SFZE];
	float FMediumpf2Speed;
	
	char SMediumpf3Name[MAX_BUFFER_SFZE];
	char SMediumpf3Hp[MAX_BUFFER_SFZE];
	float FMediumpf3Hp;
	char SMediumpf3HpMax[MAX_BUFFER_SFZE];
	float FMediumpf3HpMax;
	char SMediumpf3Attack[MAX_BUFFER_SFZE];
	float FMediumpf3Attack;
	char SMediumpf3Defense[MAX_BUFFER_SFZE];
	float FMediumpf3Defense;
	char SMediumpf3Agility[MAX_BUFFER_SFZE];
	float FMediumpf3Agility;
	char SMediumpf3Speed[MAX_BUFFER_SFZE];
	float FMediumpf3Speed;
	
	char SMediumpf4Name[MAX_BUFFER_SFZE];
	char SMediumpf4Hp[MAX_BUFFER_SFZE];
	float FMediumpf4Hp;
	char SMediumpf4HpMax[MAX_BUFFER_SFZE];
	float FMediumpf4HpMax;
	char SMediumpf4Attack[MAX_BUFFER_SFZE];
	float FMediumpf4Attack;
	char SMediumpf4Defense[MAX_BUFFER_SFZE];
	float FMediumpf4Defense;
	char SMediumpf4Agility[MAX_BUFFER_SFZE];
	float FMediumpf4Agility;
	char SMediumpf4Speed[MAX_BUFFER_SFZE];
	float FMediumpf4Speed;
	
	char SMediumpf5Name[MAX_BUFFER_SFZE];
	char SMediumpf5Hp[MAX_BUFFER_SFZE];
	float FMediumpf5Hp;
	char SMediumpf5HpMax[MAX_BUFFER_SFZE];
	float FMediumpf5HpMax;
	char SMediumpf5Attack[MAX_BUFFER_SFZE];
	float FMediumpf5Attack;
	char SMediumpf5Defense[MAX_BUFFER_SFZE];
	float FMediumpf5Defense;
	char SMediumpf5Agility[MAX_BUFFER_SFZE];
	float FMediumpf5Agility;
	char SMediumpf5Speed[MAX_BUFFER_SFZE];
	float FMediumpf5Speed;
	
	char SMediumpf6Name[MAX_BUFFER_SFZE];
	char SMediumpf6Hp[MAX_BUFFER_SFZE];
	float FMediumpf6Hp;
	char SMediumpf6HpMax[MAX_BUFFER_SFZE];
	float FMediumpf6HpMax;
	char SMediumpf6Attack[MAX_BUFFER_SFZE];
	float FMediumpf6Attack;
	char SMediumpf6Defense[MAX_BUFFER_SFZE];
	float FMediumpf6Defense;
	char SMediumpf6Agility[MAX_BUFFER_SFZE];
	float FMediumpf6Agility;
	char SMediumpf6Speed[MAX_BUFFER_SFZE];
	float FMediumpf6Speed;
	
	
	
	char SNoobcf1Name[MAX_BUFFER_SFZE];
	char SNoobcf1Hp[MAX_BUFFER_SFZE];
	float FNoobcf1Hp;
	char SNoobcf1HpMax[MAX_BUFFER_SFZE];
	float FNoobcf1HpMax;
	char SNoobcf1Attack[MAX_BUFFER_SFZE];
	float FNoobcf1Attack;
	char SNoobcf1Defense[MAX_BUFFER_SFZE];
	float FNoobcf1Defense;
	char SNoobcf1Agility[MAX_BUFFER_SFZE];
	float FNoobcf1Agility;
	char SNoobcf1Speed[MAX_BUFFER_SFZE];
	float FNoobcf1Speed;
	
	char SNoobcf2Name[MAX_BUFFER_SFZE];
	char SNoobcf2Hp[MAX_BUFFER_SFZE];
	float FNoobcf2Hp;
	char SNoobcf2HpMax[MAX_BUFFER_SFZE];
	float FNoobcf2HpMax;
	char SNoobcf2Attack[MAX_BUFFER_SFZE];
	float FNoobcf2Attack;
	char SNoobcf2Defense[MAX_BUFFER_SFZE];
	float FNoobcf2Defense;
	char SNoobcf2Agility[MAX_BUFFER_SFZE];
	float FNoobcf2Agility;
	char SNoobcf2Speed[MAX_BUFFER_SFZE];
	float FNoobcf2Speed;
	
	char SNoobcf3Name[MAX_BUFFER_SFZE];
	char SNoobcf3Hp[MAX_BUFFER_SFZE];
	float FNoobcf3Hp;
	char SNoobcf3HpMax[MAX_BUFFER_SFZE];
	float FNoobcf3HpMax;
	char SNoobcf3Attack[MAX_BUFFER_SFZE];
	float FNoobcf3Attack;
	char SNoobcf3Defense[MAX_BUFFER_SFZE];
	float FNoobcf3Defense;
	char SNoobcf3Agility[MAX_BUFFER_SFZE];
	float FNoobcf3Agility;
	char SNoobcf3Speed[MAX_BUFFER_SFZE];
	float FNoobcf3Speed;
	
	char SNoobcf4Name[MAX_BUFFER_SFZE];
	char SNoobcf4Hp[MAX_BUFFER_SFZE];
	float FNoobcf4Hp;
	char SNoobcf4HpMax[MAX_BUFFER_SFZE];
	float FNoobcf4HpMax;
	char SNoobcf4Attack[MAX_BUFFER_SFZE];
	float FNoobcf4Attack;
	char SNoobcf4Defense[MAX_BUFFER_SFZE];
	float FNoobcf4Defense;
	char SNoobcf4Agility[MAX_BUFFER_SFZE];
	float FNoobcf4Agility;
	char SNoobcf4Speed[MAX_BUFFER_SFZE];
	float FNoobcf4Speed;
	
	char SNoobcf5Name[MAX_BUFFER_SFZE];
	char SNoobcf5Hp[MAX_BUFFER_SFZE];
	float FNoobcf5Hp;
	char SNoobcf5HpMax[MAX_BUFFER_SFZE];
	float FNoobcf5HpMax;
	char SNoobcf5Attack[MAX_BUFFER_SFZE];
	float FNoobcf5Attack;
	char SNoobcf5Defense[MAX_BUFFER_SFZE];
	float FNoobcf5Defense;
	char SNoobcf5Agility[MAX_BUFFER_SFZE];
	float FNoobcf5Agility;
	char SNoobcf5Speed[MAX_BUFFER_SFZE];
	float FNoobcf5Speed;
	
	char SNoobcf6Name[MAX_BUFFER_SFZE];
	char SNoobcf6Hp[MAX_BUFFER_SFZE];
	float FNoobcf6Hp;
	char SNoobcf6HpMax[MAX_BUFFER_SFZE];
	float FNoobcf6HpMax;
	char SNoobcf6Attack[MAX_BUFFER_SFZE];
	float FNoobcf6Attack;
	char SNoobcf6Defense[MAX_BUFFER_SFZE];
	float FNoobcf6Defense;
	char SNoobcf6Agility[MAX_BUFFER_SFZE];
	float FNoobcf6Agility;
	char SNoobcf6Speed[MAX_BUFFER_SFZE];
	float FNoobcf6Speed;
	
	
	
	char SEasycf1Name[MAX_BUFFER_SFZE];
	char SEasycf1Hp[MAX_BUFFER_SFZE];
	float FEasycf1Hp;
	char SEasycf1HpMax[MAX_BUFFER_SFZE];
	float FEasycf1HpMax;
	char SEasycf1Attack[MAX_BUFFER_SFZE];
	float FEasycf1Attack;
	char SEasycf1Defense[MAX_BUFFER_SFZE];
	float FEasycf1Defense;
	char SEasycf1Agility[MAX_BUFFER_SFZE];
	float FEasycf1Agility;
	char SEasycf1Speed[MAX_BUFFER_SFZE];
	float FEasycf1Speed;
	
	char SEasycf2Name[MAX_BUFFER_SFZE];
	char SEasycf2Hp[MAX_BUFFER_SFZE];
	float FEasycf2Hp;
	char SEasycf2HpMax[MAX_BUFFER_SFZE];
	float FEasycf2HpMax;
	char SEasycf2Attack[MAX_BUFFER_SFZE];
	float FEasycf2Attack;
	char SEasycf2Defense[MAX_BUFFER_SFZE];
	float FEasycf2Defense;
	char SEasycf2Agility[MAX_BUFFER_SFZE];
	float FEasycf2Agility;
	char SEasycf2Speed[MAX_BUFFER_SFZE];
	float FEasycf2Speed;
	
	char SEasycf3Name[MAX_BUFFER_SFZE];
	char SEasycf3Hp[MAX_BUFFER_SFZE];
	float FEasycf3Hp;
	char SEasycf3HpMax[MAX_BUFFER_SFZE];
	float FEasycf3HpMax;
	char SEasycf3Attack[MAX_BUFFER_SFZE];
	float FEasycf3Attack;
	char SEasycf3Defense[MAX_BUFFER_SFZE];
	float FEasycf3Defense;
	char SEasycf3Agility[MAX_BUFFER_SFZE];
	float FEasycf3Agility;
	char SEasycf3Speed[MAX_BUFFER_SFZE];
	float FEasycf3Speed;
	
	char SEasycf4Name[MAX_BUFFER_SFZE];
	char SEasycf4Hp[MAX_BUFFER_SFZE];
	float FEasycf4Hp;
	char SEasycf4HpMax[MAX_BUFFER_SFZE];
	float FEasycf4HpMax;
	char SEasycf4Attack[MAX_BUFFER_SFZE];
	float FEasycf4Attack;
	char SEasycf4Defense[MAX_BUFFER_SFZE];
	float FEasycf4Defense;
	char SEasycf4Agility[MAX_BUFFER_SFZE];
	float FEasycf4Agility;
	char SEasycf4Speed[MAX_BUFFER_SFZE];
	float FEasycf4Speed;
	
	char SEasycf5Name[MAX_BUFFER_SFZE];
	char SEasycf5Hp[MAX_BUFFER_SFZE];
	float FEasycf5Hp;
	char SEasycf5HpMax[MAX_BUFFER_SFZE];
	float FEasycf5HpMax;
	char SEasycf5Attack[MAX_BUFFER_SFZE];
	float FEasycf5Attack;
	char SEasycf5Defense[MAX_BUFFER_SFZE];
	float FEasycf5Defense;
	char SEasycf5Agility[MAX_BUFFER_SFZE];
	float FEasycf5Agility;
	char SEasycf5Speed[MAX_BUFFER_SFZE];
	float FEasycf5Speed;
	
	char SEasycf6Name[MAX_BUFFER_SFZE];
	char SEasycf6Hp[MAX_BUFFER_SFZE];
	float FEasycf6Hp;
	char SEasycf6HpMax[MAX_BUFFER_SFZE];
	float FEasycf6HpMax;
	char SEasycf6Attack[MAX_BUFFER_SFZE];
	float FEasycf6Attack;
	char SEasycf6Defense[MAX_BUFFER_SFZE];
	float FEasycf6Defense;
	char SEasycf6Agility[MAX_BUFFER_SFZE];
	float FEasycf6Agility;
	char SEasycf6Speed[MAX_BUFFER_SFZE];
	float FEasycf6Speed;
	
	
	
	
	char SMediumcf1Name[MAX_BUFFER_SFZE];
	char SMediumcf1Hp[MAX_BUFFER_SFZE];
	float FMediumcf1Hp;
	char SMediumcf1HpMax[MAX_BUFFER_SFZE];
	float FMediumcf1HpMax;
	char SMediumcf1Attack[MAX_BUFFER_SFZE];
	float FMediumcf1Attack;
	char SMediumcf1Defense[MAX_BUFFER_SFZE];
	float FMediumcf1Defense;
	char SMediumcf1Agility[MAX_BUFFER_SFZE];
	float FMediumcf1Agility;
	char SMediumcf1Speed[MAX_BUFFER_SFZE];
	float FMediumcf1Speed;
	
	char SMediumcf2Name[MAX_BUFFER_SFZE];
	char SMediumcf2Hp[MAX_BUFFER_SFZE];
	float FMediumcf2Hp;
	char SMediumcf2HpMax[MAX_BUFFER_SFZE];
	float FMediumcf2HpMax;
	char SMediumcf2Attack[MAX_BUFFER_SFZE];
	float FMediumcf2Attack;
	char SMediumcf2Defense[MAX_BUFFER_SFZE];
	float FMediumcf2Defense;
	char SMediumcf2Agility[MAX_BUFFER_SFZE];
	float FMediumcf2Agility;
	char SMediumcf2Speed[MAX_BUFFER_SFZE];
	float FMediumcf2Speed;
	
	char SMediumcf3Name[MAX_BUFFER_SFZE];
	char SMediumcf3Hp[MAX_BUFFER_SFZE];
	float FMediumcf3Hp;
	char SMediumcf3HpMax[MAX_BUFFER_SFZE];
	float FMediumcf3HpMax;
	char SMediumcf3Attack[MAX_BUFFER_SFZE];
	float FMediumcf3Attack;
	char SMediumcf3Defense[MAX_BUFFER_SFZE];
	float FMediumcf3Defense;
	char SMediumcf3Agility[MAX_BUFFER_SFZE];
	float FMediumcf3Agility;
	char SMediumcf3Speed[MAX_BUFFER_SFZE];
	float FMediumcf3Speed;
	
	char SMediumcf4Name[MAX_BUFFER_SFZE];
	char SMediumcf4Hp[MAX_BUFFER_SFZE];
	float FMediumcf4Hp;
	char SMediumcf4HpMax[MAX_BUFFER_SFZE];
	float FMediumcf4HpMax;
	char SMediumcf4Attack[MAX_BUFFER_SFZE];
	float FMediumcf4Attack;
	char SMediumcf4Defense[MAX_BUFFER_SFZE];
	float FMediumcf4Defense;
	char SMediumcf4Agility[MAX_BUFFER_SFZE];
	float FMediumcf4Agility;
	char SMediumcf4Speed[MAX_BUFFER_SFZE];
	float FMediumcf4Speed;
	
	char SMediumcf5Name[MAX_BUFFER_SFZE];
	char SMediumcf5Hp[MAX_BUFFER_SFZE];
	float FMediumcf5Hp;
	char SMediumcf5HpMax[MAX_BUFFER_SFZE];
	float FMediumcf5HpMax;
	char SMediumcf5Attack[MAX_BUFFER_SFZE];
	float FMediumcf5Attack;
	char SMediumcf5Defense[MAX_BUFFER_SFZE];
	float FMediumcf5Defense;
	char SMediumcf5Agility[MAX_BUFFER_SFZE];
	float FMediumcf5Agility;
	char SMediumcf5Speed[MAX_BUFFER_SFZE];
	float FMediumcf5Speed;
	
	char SMediumcf6Name[MAX_BUFFER_SFZE];
	char SMediumcf6Hp[MAX_BUFFER_SFZE];
	float FMediumcf6Hp;
	char SMediumcf6HpMax[MAX_BUFFER_SFZE];
	float FMediumcf6HpMax;
	char SMediumcf6Attack[MAX_BUFFER_SFZE];
	float FMediumcf6Attack;
	char SMediumcf6Defense[MAX_BUFFER_SFZE];
	float FMediumcf6Defense;
	char SMediumcf6Agility[MAX_BUFFER_SFZE];
	float FMediumcf6Agility;
	char SMediumcf6Speed[MAX_BUFFER_SFZE];
	float FMediumcf6Speed;
	
	
	
	
	char SHardcf1Name[MAX_BUFFER_SFZE];
	char SHardcf1Hp[MAX_BUFFER_SFZE];
	float FHardcf1Hp;
	char SHardcf1HpMax[MAX_BUFFER_SFZE];
	float FHardcf1HpMax;
	char SHardcf1Attack[MAX_BUFFER_SFZE];
	float FHardcf1Attack;
	char SHardcf1Defense[MAX_BUFFER_SFZE];
	float FHardcf1Defense;
	char SHardcf1Agility[MAX_BUFFER_SFZE];
	float FHardcf1Agility;
	char SHardcf1Speed[MAX_BUFFER_SFZE];
	float FHardcf1Speed;
	
	char SHardcf2Name[MAX_BUFFER_SFZE];
	char SHardcf2Hp[MAX_BUFFER_SFZE];
	float FHardcf2Hp;
	char SHardcf2HpMax[MAX_BUFFER_SFZE];
	float FHardcf2HpMax;
	char SHardcf2Attack[MAX_BUFFER_SFZE];
	float FHardcf2Attack;
	char SHardcf2Defense[MAX_BUFFER_SFZE];
	float FHardcf2Defense;
	char SHardcf2Agility[MAX_BUFFER_SFZE];
	float FHardcf2Agility;
	char SHardcf2Speed[MAX_BUFFER_SFZE];
	float FHardcf2Speed;
	
	char SHardcf3Name[MAX_BUFFER_SFZE];
	char SHardcf3Hp[MAX_BUFFER_SFZE];
	float FHardcf3Hp;
	char SHardcf3HpMax[MAX_BUFFER_SFZE];
	float FHardcf3HpMax;
	char SHardcf3Attack[MAX_BUFFER_SFZE];
	float FHardcf3Attack;
	char SHardcf3Defense[MAX_BUFFER_SFZE];
	float FHardcf3Defense;
	char SHardcf3Agility[MAX_BUFFER_SFZE];
	float FHardcf3Agility;
	char SHardcf3Speed[MAX_BUFFER_SFZE];
	float FHardcf3Speed;
	
	char SHardcf4Name[MAX_BUFFER_SFZE];
	char SHardcf4Hp[MAX_BUFFER_SFZE];
	float FHardcf4Hp;
	char SHardcf4HpMax[MAX_BUFFER_SFZE];
	float FHardcf4HpMax;
	char SHardcf4Attack[MAX_BUFFER_SFZE];
	float FHardcf4Attack;
	char SHardcf4Defense[MAX_BUFFER_SFZE];
	float FHardcf4Defense;
	char SHardcf4Agility[MAX_BUFFER_SFZE];
	float FHardcf4Agility;
	char SHardcf4Speed[MAX_BUFFER_SFZE];
	float FHardcf4Speed;
	
	char SHardcf5Name[MAX_BUFFER_SFZE];
	char SHardcf5Hp[MAX_BUFFER_SFZE];
	float FHardcf5Hp;
	char SHardcf5HpMax[MAX_BUFFER_SFZE];
	float FHardcf5HpMax;
	char SHardcf5Attack[MAX_BUFFER_SFZE];
	float FHardcf5Attack;
	char SHardcf5Defense[MAX_BUFFER_SFZE];
	float FHardcf5Defense;
	char SHardcf5Agility[MAX_BUFFER_SFZE];
	float FHardcf5Agility;
	char SHardcf5Speed[MAX_BUFFER_SFZE];
	float FHardcf5Speed;
	
	char SHardcf6Name[MAX_BUFFER_SFZE];
	char SHardcf6Hp[MAX_BUFFER_SFZE];
	float FHardcf6Hp;
	char SHardcf6HpMax[MAX_BUFFER_SFZE];
	float FHardcf6HpMax;
	char SHardcf6Attack[MAX_BUFFER_SFZE];
	float FHardcf6Attack;
	char SHardcf6Defense[MAX_BUFFER_SFZE];
	float FHardcf6Defense;
	char SHardcf6Agility[MAX_BUFFER_SFZE];
	float FHardcf6Agility;
	char SHardcf6Speed[MAX_BUFFER_SFZE];
	float FHardcf6Speed;
	
	
	
	if(pf1 == 1){
		Mediumpf1Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	if(pf1 == 2){
		Mediumpf1Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	if(pf1 == 3){
		Mediumpf1Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	if(pf1 == 4){
		Mediumpf1Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	if(pf1 == 5){
		Mediumpf1Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	if(pf1 == 6){
		Mediumpf1Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumpf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Name, MAX_BUFFER_SFZE, Mediumpf1Name) != NULL){
		}
		free(Mediumpf1Name);
		Mediumpf1Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumpf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Hp, MAX_BUFFER_SFZE, Mediumpf1Hp) != NULL){
			FMediumpf1Hp = atoi(SMediumpf1Hp);
		}
		free(Mediumpf1Hp);
		Mediumpf1HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumpf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1HpMax, MAX_BUFFER_SFZE, Mediumpf1HpMax) != NULL){
			FMediumpf1HpMax = atoi(SMediumpf1HpMax);
		}
		free(Mediumpf1HpMax);
		Mediumpf1Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumpf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Attack, MAX_BUFFER_SFZE, Mediumpf1Attack) != NULL){
			FMediumpf1Attack = atoi(SMediumpf1Attack);
		}
		free(Mediumpf1Attack);
		Mediumpf1Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumpf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Defense, MAX_BUFFER_SFZE, Mediumpf1Defense) != NULL){
			FMediumpf1Defense = atoi(SMediumpf1Defense);
		}
		free(Mediumpf1Defense);
		Mediumpf1Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumpf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Agility, MAX_BUFFER_SFZE, Mediumpf1Agility) != NULL){
			FMediumpf1Agility = atoi(SMediumpf1Agility);
		}
		free(Mediumpf1Agility);
		Mediumpf1Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumpf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf1Speed, MAX_BUFFER_SFZE, Mediumpf1Speed) != NULL){
			FMediumpf1Speed = atoi(SMediumpf1Speed);
		}
		free(Mediumpf1Speed);
	}
	
	
	
	
	if(pf2 == 1){
		Mediumpf2Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	if(pf2 == 2){
		Mediumpf2Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	if(pf2 == 3){
		Mediumpf2Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	if(pf2 == 4){
		Mediumpf2Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	if(pf2 == 5){
		Mediumpf2Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	if(pf2 == 6){
		Mediumpf2Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumpf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Name, MAX_BUFFER_SFZE, Mediumpf2Name) != NULL){
		}
		free(Mediumpf2Name);
		Mediumpf2Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumpf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Hp, MAX_BUFFER_SFZE, Mediumpf2Hp) != NULL){
			FMediumpf2Hp = atoi(SMediumpf2Hp);
		}
		free(Mediumpf2Hp);
		Mediumpf2HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumpf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2HpMax, MAX_BUFFER_SFZE, Mediumpf2HpMax) != NULL){
			FMediumpf2HpMax = atoi(SMediumpf2HpMax);
		}
		free(Mediumpf2HpMax);
		Mediumpf2Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumpf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Attack, MAX_BUFFER_SFZE, Mediumpf2Attack) != NULL){
			FMediumpf2Attack = atoi(SMediumpf2Attack);
		}
		free(Mediumpf2Attack);
		Mediumpf2Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumpf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Defense, MAX_BUFFER_SFZE, Mediumpf2Defense) != NULL){
			FMediumpf2Defense = atoi(SMediumpf2Defense);
		}
		free(Mediumpf2Defense);
		Mediumpf2Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumpf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Agility, MAX_BUFFER_SFZE, Mediumpf2Agility) != NULL){
			FMediumpf2Agility = atoi(SMediumpf2Agility);
		}
		free(Mediumpf2Agility);
		Mediumpf2Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumpf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf2Speed, MAX_BUFFER_SFZE, Mediumpf2Speed) != NULL){
			FMediumpf2Speed = atoi(SMediumpf2Speed);
		}
		free(Mediumpf2Speed);
	}
	
	
	
	
	if(pf3 == 1){
		Mediumpf3Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	if(pf3 == 2){
		Mediumpf3Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	if(pf3 == 3){
		Mediumpf3Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	if(pf3 == 4){
		Mediumpf3Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	if(pf3 == 5){
		Mediumpf3Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	if(pf3 == 6){
		Mediumpf3Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumpf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Name, MAX_BUFFER_SFZE, Mediumpf3Name) != NULL){
		}
		free(Mediumpf3Name);
		Mediumpf3Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumpf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Hp, MAX_BUFFER_SFZE, Mediumpf3Hp) != NULL){
			FMediumpf3Hp = atoi(SMediumpf3Hp);
		}
		free(Mediumpf3Hp);
		Mediumpf3HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumpf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3HpMax, MAX_BUFFER_SFZE, Mediumpf3HpMax) != NULL){
			FMediumpf3HpMax = atoi(SMediumpf3HpMax);
		}
		free(Mediumpf3HpMax);
		Mediumpf3Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumpf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Attack, MAX_BUFFER_SFZE, Mediumpf3Attack) != NULL){
			FMediumpf3Attack = atoi(SMediumpf3Attack);
		}
		free(Mediumpf3Attack);
		Mediumpf3Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumpf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Defense, MAX_BUFFER_SFZE, Mediumpf3Defense) != NULL){
			FMediumpf3Defense = atoi(SMediumpf3Defense);
		}
		free(Mediumpf3Defense);
		Mediumpf3Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumpf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Agility, MAX_BUFFER_SFZE, Mediumpf3Agility) != NULL){
			FMediumpf3Agility = atoi(SMediumpf3Agility);
		}
		free(Mediumpf3Agility);
		Mediumpf3Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumpf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumpf3Speed, MAX_BUFFER_SFZE, Mediumpf3Speed) != NULL){
			FMediumpf3Speed = atoi(SMediumpf3Speed);
		}
		free(Mediumpf3Speed);
	}
	
	
	
	if(diff == 1){
		if(cf1 == 1){
		Noobcf1Name = fopen("noob_stats/Khabib.N/NoobKhabibName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Khabib.N/NoobKhabibHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Khabib.N/NoobKhabibHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Khabib.N/NoobKhabibAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Khabib.N/NoobKhabibDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Khabib.N/NoobKhabibAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Khabib.N/NoobKhabibSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	if(cf1 == 2){
		Noobcf1Name = fopen("noob_stats/Conor.M/NoobConorName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Conor.M/NoobConorHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Conor.M/NoobConorHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Conor.M/NoobConorAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Conor.M/NoobConorDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Conor.M/NoobConorAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Conor.M/NoobConorSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	if(cf1 == 3){
		Noobcf1Name = fopen("noob_stats/Charles.O/NoobCharlesName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Charles.O/NoobCharlesHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Charles.O/NoobCharlesHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Charles.O/NoobCharlesAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Charles.O/NoobCharlesDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Charles.O/NoobCharlesAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Charles.O/NoobCharlesSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	if(cf1 == 4){
		Noobcf1Name = fopen("noob_stats/Khamzat.C/NoobKhamzatName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Khamzat.C/NoobKhamzatHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Khamzat.C/NoobKhamzatHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Khamzat.C/NoobKhamzatAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Khamzat.C/NoobKhamzatDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Khamzat.C/NoobKhamzatAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Khamzat.C/NoobKhamzatSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	if(cf1 == 5){
		Noobcf1Name = fopen("noob_stats/Ciryl.G/NoobCirylName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Ciryl.G/NoobCirylHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Ciryl.G/NoobCirylHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Ciryl.G/NoobCirylAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Ciryl.G/NoobCirylDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Ciryl.G/NoobCirylAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Ciryl.G/NoobCirylSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	if(cf1 == 6){
		Noobcf1Name = fopen("noob_stats/Francis.N/NoobFrancisName.txt", "r");
		if(Noobcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Name, MAX_BUFFER_SFZE, Noobcf1Name) != NULL){
		}
		free(Noobcf1Name);
		Noobcf1Hp = fopen("noob_stats/Francis.N/NoobFrancisHp.txt", "r");
		if(Noobcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Hp, MAX_BUFFER_SFZE, Noobcf1Hp) != NULL){
			FNoobcf1Hp = atoi(SNoobcf1Hp);
		}
		free(Noobcf1Hp);
		Noobcf1HpMax = fopen("noob_stats/Francis.N/NoobFrancisHpMax.txt", "r");
		if(Noobcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1HpMax, MAX_BUFFER_SFZE, Noobcf1HpMax) != NULL){
			FNoobcf1HpMax = atoi(SNoobcf1HpMax);
		}
		free(Noobcf1HpMax);
		Noobcf1Attack = fopen("noob_stats/Francis.N/NoobFrancisAttack.txt", "r");
		if(Noobcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Attack, MAX_BUFFER_SFZE, Noobcf1Attack) != NULL){
			FNoobcf1Attack = atoi(SNoobcf1Attack);
		}
		free(Noobcf1Attack);
		Noobcf1Defense = fopen("noob_stats/Francis.N/NoobFrancisDefense.txt", "r");
		if(Noobcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Defense, MAX_BUFFER_SFZE, Noobcf1Defense) != NULL){
			FNoobcf1Defense = atoi(SNoobcf1Defense);
		}
		free(Noobcf1Defense);
		Noobcf1Agility = fopen("noob_stats/Francis.N/NoobFrancisAgility.txt", "r");
		if(Noobcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Agility, MAX_BUFFER_SFZE, Noobcf1Agility) != NULL){
			FNoobcf1Agility = atoi(SNoobcf1Agility);
		}
		free(Noobcf1Agility);
		Noobcf1Speed = fopen("noob_stats/Francis.N/NoobFrancisSpeed.txt", "r");
		if(Noobcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf1Speed, MAX_BUFFER_SFZE, Noobcf1Speed) != NULL){
			FNoobcf1Speed = atoi(SNoobcf1Speed);
		}
		free(Noobcf1Speed);
	}
	
	
	
	
	if(cf2 == 1){
		Noobcf2Name = fopen("noob_stats/Khabib.N/NoobKhabibName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Khabib.N/NoobKhabibHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Khabib.N/NoobKhabibHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Khabib.N/NoobKhabibAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Khabib.N/NoobKhabibDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Khabib.N/NoobKhabibAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Khabib.N/NoobKhabibSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	if(cf2 == 2){
		Noobcf2Name = fopen("noob_stats/Conor.M/NoobConorName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Conor.M/NoobConorHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Conor.M/NoobConorHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Conor.M/NoobConorAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Conor.M/NoobConorDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Conor.M/NoobConorAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Conor.M/NoobConorSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	if(cf2 == 3){
		Noobcf2Name = fopen("noob_stats/Charles.O/NoobCharlesName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Charles.O/NoobCharlesHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Charles.O/NoobCharlesHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Charles.O/NoobCharlesAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Charles.O/NoobCharlesDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Charles.O/NoobCharlesAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Charles.O/NoobCharlesSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	if(cf2 == 4){
		Noobcf2Name = fopen("noob_stats/Khamzat.C/NoobKhamzatName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Khamzat.C/NoobKhamzatHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Khamzat.C/NoobKhamzatHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Khamzat.C/NoobKhamzatAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Khamzat.C/NoobKhamzatDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Khamzat.C/NoobKhamzatAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Khamzat.C/NoobKhamzatSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	if(cf2 == 5){
		Noobcf2Name = fopen("noob_stats/Ciryl.G/NoobCirylName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Ciryl.G/NoobCirylHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Ciryl.G/NoobCirylHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Ciryl.G/NoobCirylAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Ciryl.G/NoobCirylDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Ciryl.G/NoobCirylAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Ciryl.G/NoobCirylSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	if(cf2 == 6){
		Noobcf2Name = fopen("noob_stats/Francis.N/NoobFrancisName.txt", "r");
		if(Noobcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Name, MAX_BUFFER_SFZE, Noobcf2Name) != NULL){
		}
		free(Noobcf2Name);
		Noobcf2Hp = fopen("noob_stats/Francis.N/NoobFrancisHp.txt", "r");
		if(Noobcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Hp, MAX_BUFFER_SFZE, Noobcf2Hp) != NULL){
			FNoobcf2Hp = atoi(SNoobcf2Hp);
		}
		free(Noobcf2Hp);
		Noobcf2HpMax = fopen("noob_stats/Francis.N/NoobFrancisHpMax.txt", "r");
		if(Noobcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2HpMax, MAX_BUFFER_SFZE, Noobcf2HpMax) != NULL){
			FNoobcf2HpMax = atoi(SNoobcf2HpMax);
		}
		free(Noobcf2HpMax);
		Noobcf2Attack = fopen("noob_stats/Francis.N/NoobFrancisAttack.txt", "r");
		if(Noobcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Attack, MAX_BUFFER_SFZE, Noobcf2Attack) != NULL){
			FNoobcf2Attack = atoi(SNoobcf2Attack);
		}
		free(Noobcf2Attack);
		Noobcf2Defense = fopen("noob_stats/Francis.N/NoobFrancisDefense.txt", "r");
		if(Noobcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Defense, MAX_BUFFER_SFZE, Noobcf2Defense) != NULL){
			FNoobcf2Defense = atoi(SNoobcf2Defense);
		}
		free(Noobcf2Defense);
		Noobcf2Agility = fopen("noob_stats/Francis.N/NoobFrancisAgility.txt", "r");
		if(Noobcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Agility, MAX_BUFFER_SFZE, Noobcf2Agility) != NULL){
			FNoobcf2Agility = atoi(SNoobcf2Agility);
		}
		free(Noobcf2Agility);
		Noobcf2Speed = fopen("noob_stats/Francis.N/NoobFrancisSpeed.txt", "r");
		if(Noobcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf2Speed, MAX_BUFFER_SFZE, Noobcf2Speed) != NULL){
			FNoobcf2Speed = atoi(SNoobcf2Speed);
		}
		free(Noobcf2Speed);
	}
	
	
	
	
	if(cf3 == 1){
		Noobcf3Name = fopen("noob_stats/Khabib.N/NoobKhabibName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Khabib.N/NoobKhabibHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Khabib.N/NoobKhabibHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Khabib.N/NoobKhabibAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Khabib.N/NoobKhabibDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Khabib.N/NoobKhabibAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Khabib.N/NoobKhabibSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	if(cf3 == 2){
		Noobcf3Name = fopen("noob_stats/Conor.M/NoobConorName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Conor.M/NoobConorHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Conor.M/NoobConorHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Conor.M/NoobConorAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Conor.M/NoobConorDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Conor.M/NoobConorAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Conor.M/NoobConorSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	if(cf3 == 3){
		Noobcf3Name = fopen("noob_stats/Charles.O/NoobCharlesName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Charles.O/NoobCharlesHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Charles.O/NoobCharlesHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Charles.O/NoobCharlesAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Charles.O/NoobCharlesDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Charles.O/NoobCharlesAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Charles.O/NoobCharlesSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	if(cf3 == 4){
		Noobcf3Name = fopen("noob_stats/Khamzat.C/NoobKhamzatName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Khamzat.C/NoobKhamzatHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Khamzat.C/NoobKhamzatHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Khamzat.C/NoobKhamzatAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Khamzat.C/NoobKhamzatDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Khamzat.C/NoobKhamzatAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Khamzat.C/NoobKhamzatSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	if(cf3 == 5){
		Noobcf3Name = fopen("noob_stats/Ciryl.G/NoobCirylName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Ciryl.G/NoobCirylHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Ciryl.G/NoobCirylHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Ciryl.G/NoobCirylAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Ciryl.G/NoobCirylDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Ciryl.G/NoobCirylAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Ciryl.G/NoobCirylSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	if(cf3 == 6){
		Noobcf3Name = fopen("noob_stats/Francis.N/NoobFrancisName.txt", "r");
		if(Noobcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Name, MAX_BUFFER_SFZE, Noobcf3Name) != NULL){
		}
		free(Noobcf3Name);
		Noobcf3Hp = fopen("noob_stats/Francis.N/NoobFrancisHp.txt", "r");
		if(Noobcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Hp, MAX_BUFFER_SFZE, Noobcf3Hp) != NULL){
			FNoobcf3Hp = atoi(SNoobcf3Hp);
		}
		free(Noobcf3Hp);
		Noobcf3HpMax = fopen("noob_stats/Francis.N/NoobFrancisHpMax.txt", "r");
		if(Noobcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3HpMax, MAX_BUFFER_SFZE, Noobcf3HpMax) != NULL){
			FNoobcf3HpMax = atoi(SNoobcf3HpMax);
		}
		free(Noobcf3HpMax);
		Noobcf3Attack = fopen("noob_stats/Francis.N/NoobFrancisAttack.txt", "r");
		if(Noobcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Attack, MAX_BUFFER_SFZE, Noobcf3Attack) != NULL){
			FNoobcf3Attack = atoi(SNoobcf3Attack);
		}
		free(Noobcf3Attack);
		Noobcf3Defense = fopen("noob_stats/Francis.N/NoobFrancisDefense.txt", "r");
		if(Noobcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Defense, MAX_BUFFER_SFZE, Noobcf3Defense) != NULL){
			FNoobcf3Defense = atoi(SNoobcf3Defense);
		}
		free(Noobcf3Defense);
		Noobcf3Agility = fopen("noob_stats/Francis.N/NoobFrancisAgility.txt", "r");
		if(Noobcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Agility, MAX_BUFFER_SFZE, Noobcf3Agility) != NULL){
			FNoobcf3Agility = atoi(SNoobcf3Agility);
		}
		free(Noobcf3Agility);
		Noobcf3Speed = fopen("noob_stats/Francis.N/NoobFrancisSpeed.txt", "r");
		if(Noobcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SNoobcf3Speed, MAX_BUFFER_SFZE, Noobcf3Speed) != NULL){
			FNoobcf3Speed = atoi(SNoobcf3Speed);
		}
		free(Noobcf3Speed);
	}
	}
	if(diff == 2){
		if(cf1 == 1){
		Easycf1Name = fopen("easy_stats/Khabib.N/EasyKhabibName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Khabib.N/EasyKhabibHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Khabib.N/EasyKhabibHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Khabib.N/EasyKhabibAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Khabib.N/EasyKhabibDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Khabib.N/EasyKhabibAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Khabib.N/EasyKhabibSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	if(cf1 == 2){
		Easycf1Name = fopen("easy_stats/Conor.M/EasyConorName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Conor.M/EasyConorHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Conor.M/EasyConorHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Conor.M/EasyConorAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Conor.M/EasyConorDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Conor.M/EasyConorAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Conor.M/EasyConorSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	if(cf1 == 3){
		Easycf1Name = fopen("easy_stats/Charles.O/EasyCharlesName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Charles.O/EasyCharlesHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Charles.O/EasyCharlesHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Charles.O/EasyCharlesAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Charles.O/EasyCharlesDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Charles.O/EasyCharlesAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Charles.O/EasyCharlesSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	if(cf1 == 4){
		Easycf1Name = fopen("easy_stats/Khamzat.C/EasyKhamzatName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Khamzat.C/EasyKhamzatHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Khamzat.C/EasyKhamzatHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Khamzat.C/EasyKhamzatAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Khamzat.C/EasyKhamzatDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Khamzat.C/EasyKhamzatAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Khamzat.C/EasyKhamzatSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	if(cf1 == 5){
		Easycf1Name = fopen("easy_stats/Ciryl.G/EasyCirylName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Ciryl.G/EasyCirylHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Ciryl.G/EasyCirylHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Ciryl.G/EasyCirylAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Ciryl.G/EasyCirylDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Ciryl.G/EasyCirylAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Ciryl.G/EasyCirylSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	if(cf1 == 6){
		Easycf1Name = fopen("easy_stats/Francis.N/EasyFrancisName.txt", "r");
		if(Easycf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Name, MAX_BUFFER_SFZE, Easycf1Name) != NULL){
		}
		free(Easycf1Name);
		Easycf1Hp = fopen("easy_stats/Francis.N/EasyFrancisHp.txt", "r");
		if(Easycf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Hp, MAX_BUFFER_SFZE, Easycf1Hp) != NULL){
			FEasycf1Hp = atoi(SEasycf1Hp);
		}
		free(Easycf1Hp);
		Easycf1HpMax = fopen("easy_stats/Francis.N/EasyFrancisHpMax.txt", "r");
		if(Easycf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1HpMax, MAX_BUFFER_SFZE, Easycf1HpMax) != NULL){
			FEasycf1HpMax = atoi(SEasycf1HpMax);
		}
		free(Easycf1HpMax);
		Easycf1Attack = fopen("easy_stats/Francis.N/EasyFrancisAttack.txt", "r");
		if(Easycf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Attack, MAX_BUFFER_SFZE, Easycf1Attack) != NULL){
			FEasycf1Attack = atoi(SEasycf1Attack);
		}
		free(Easycf1Attack);
		Easycf1Defense = fopen("easy_stats/Francis.N/EasyFrancisDefense.txt", "r");
		if(Easycf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Defense, MAX_BUFFER_SFZE, Easycf1Defense) != NULL){
			FEasycf1Defense = atoi(SEasycf1Defense);
		}
		free(Easycf1Defense);
		Easycf1Agility = fopen("easy_stats/Francis.N/EasyFrancisAgility.txt", "r");
		if(Easycf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Agility, MAX_BUFFER_SFZE, Easycf1Agility) != NULL){
			FEasycf1Agility = atoi(SEasycf1Agility);
		}
		free(Easycf1Agility);
		Easycf1Speed = fopen("easy_stats/Francis.N/EasyFrancisSpeed.txt", "r");
		if(Easycf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf1Speed, MAX_BUFFER_SFZE, Easycf1Speed) != NULL){
			FEasycf1Speed = atoi(SEasycf1Speed);
		}
		free(Easycf1Speed);
	}
	
	
	
	
	if(cf2 == 1){
		Easycf2Name = fopen("easy_stats/Khabib.N/EasyKhabibName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Khabib.N/EasyKhabibHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Khabib.N/EasyKhabibHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Khabib.N/EasyKhabibAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Khabib.N/EasyKhabibDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Khabib.N/EasyKhabibAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Khabib.N/EasyKhabibSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	if(cf2 == 2){
		Easycf2Name = fopen("easy_stats/Conor.M/EasyConorName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Conor.M/EasyConorHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Conor.M/EasyConorHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Conor.M/EasyConorAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Conor.M/EasyConorDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Conor.M/EasyConorAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Conor.M/EasyConorSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	if(cf2 == 3){
		Easycf2Name = fopen("easy_stats/Charles.O/EasyCharlesName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Charles.O/EasyCharlesHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Charles.O/EasyCharlesHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Charles.O/EasyCharlesAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Charles.O/EasyCharlesDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Charles.O/EasyCharlesAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Charles.O/EasyCharlesSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	if(cf2 == 4){
		Easycf2Name = fopen("easy_stats/Khamzat.C/EasyKhamzatName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Khamzat.C/EasyKhamzatHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Khamzat.C/EasyKhamzatHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Khamzat.C/EasyKhamzatAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Khamzat.C/EasyKhamzatDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Khamzat.C/EasyKhamzatAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Khamzat.C/EasyKhamzatSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	if(cf2 == 5){
		Easycf2Name = fopen("easy_stats/Ciryl.G/EasyCirylName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Ciryl.G/EasyCirylHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Ciryl.G/EasyCirylHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Ciryl.G/EasyCirylAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Ciryl.G/EasyCirylDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Ciryl.G/EasyCirylAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Ciryl.G/EasyCirylSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	if(cf2 == 6){
		Easycf2Name = fopen("easy_stats/Francis.N/EasyFrancisName.txt", "r");
		if(Easycf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Name, MAX_BUFFER_SFZE, Easycf2Name) != NULL){
		}
		free(Easycf2Name);
		Easycf2Hp = fopen("easy_stats/Francis.N/EasyFrancisHp.txt", "r");
		if(Easycf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Hp, MAX_BUFFER_SFZE, Easycf2Hp) != NULL){
			FEasycf2Hp = atoi(SEasycf2Hp);
		}
		free(Easycf2Hp);
		Easycf2HpMax = fopen("easy_stats/Francis.N/EasyFrancisHpMax.txt", "r");
		if(Easycf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2HpMax, MAX_BUFFER_SFZE, Easycf2HpMax) != NULL){
			FEasycf2HpMax = atoi(SEasycf2HpMax);
		}
		free(Easycf2HpMax);
		Easycf2Attack = fopen("easy_stats/Francis.N/EasyFrancisAttack.txt", "r");
		if(Easycf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Attack, MAX_BUFFER_SFZE, Easycf2Attack) != NULL){
			FEasycf2Attack = atoi(SEasycf2Attack);
		}
		free(Easycf2Attack);
		Easycf2Defense = fopen("easy_stats/Francis.N/EasyFrancisDefense.txt", "r");
		if(Easycf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Defense, MAX_BUFFER_SFZE, Easycf2Defense) != NULL){
			FEasycf2Defense = atoi(SEasycf2Defense);
		}
		free(Easycf2Defense);
		Easycf2Agility = fopen("easy_stats/Francis.N/EasyFrancisAgility.txt", "r");
		if(Easycf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Agility, MAX_BUFFER_SFZE, Easycf2Agility) != NULL){
			FEasycf2Agility = atoi(SEasycf2Agility);
		}
		free(Easycf2Agility);
		Easycf2Speed = fopen("easy_stats/Francis.N/EasyFrancisSpeed.txt", "r");
		if(Easycf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf2Speed, MAX_BUFFER_SFZE, Easycf2Speed) != NULL){
			FEasycf2Speed = atoi(SEasycf2Speed);
		}
		free(Easycf2Speed);
	}
	
	
	
	
	if(cf3 == 1){
		Easycf3Name = fopen("easy_stats/Khabib.N/EasyKhabibName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Khabib.N/EasyKhabibHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Khabib.N/EasyKhabibHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Khabib.N/EasyKhabibAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Khabib.N/EasyKhabibDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Khabib.N/EasyKhabibAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Khabib.N/EasyKhabibSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	if(cf3 == 2){
		Easycf3Name = fopen("easy_stats/Conor.M/EasyConorName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Conor.M/EasyConorHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Conor.M/EasyConorHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Conor.M/EasyConorAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Conor.M/EasyConorDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Conor.M/EasyConorAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Conor.M/EasyConorSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	if(cf3 == 3){
		Easycf3Name = fopen("easy_stats/Charles.O/EasyCharlesName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Charles.O/EasyCharlesHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Charles.O/EasyCharlesHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Charles.O/EasyCharlesAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Charles.O/EasyCharlesDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Charles.O/EasyCharlesAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Charles.O/EasyCharlesSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	if(cf3 == 4){
		Easycf3Name = fopen("easy_stats/Khamzat.C/EasyKhamzatName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Khamzat.C/EasyKhamzatHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Khamzat.C/EasyKhamzatHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Khamzat.C/EasyKhamzatAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Khamzat.C/EasyKhamzatDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Khamzat.C/EasyKhamzatAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Khamzat.C/EasyKhamzatSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	if(cf3 == 5){
		Easycf3Name = fopen("easy_stats/Ciryl.G/EasyCirylName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Ciryl.G/EasyCirylHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Ciryl.G/EasyCirylHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Ciryl.G/EasyCirylAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Ciryl.G/EasyCirylDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Ciryl.G/EasyCirylAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Ciryl.G/EasyCirylSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	if(cf3 == 6){
		Easycf3Name = fopen("easy_stats/Francis.N/EasyFrancisName.txt", "r");
		if(Easycf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Name, MAX_BUFFER_SFZE, Easycf3Name) != NULL){
		}
		free(Easycf3Name);
		Easycf3Hp = fopen("easy_stats/Francis.N/EasyFrancisHp.txt", "r");
		if(Easycf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Hp, MAX_BUFFER_SFZE, Easycf3Hp) != NULL){
			FEasycf3Hp = atoi(SEasycf3Hp);
		}
		free(Easycf3Hp);
		Easycf3HpMax = fopen("easy_stats/Francis.N/EasyFrancisHpMax.txt", "r");
		if(Easycf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3HpMax, MAX_BUFFER_SFZE, Easycf3HpMax) != NULL){
			FEasycf3HpMax = atoi(SEasycf3HpMax);
		}
		free(Easycf3HpMax);
		Easycf3Attack = fopen("easy_stats/Francis.N/EasyFrancisAttack.txt", "r");
		if(Easycf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Attack, MAX_BUFFER_SFZE, Easycf3Attack) != NULL){
			FEasycf3Attack = atoi(SEasycf3Attack);
		}
		free(Easycf3Attack);
		Easycf3Defense = fopen("easy_stats/Francis.N/EasyFrancisDefense.txt", "r");
		if(Easycf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Defense, MAX_BUFFER_SFZE, Easycf3Defense) != NULL){
			FEasycf3Defense = atoi(SEasycf3Defense);
		}
		free(Easycf3Defense);
		Easycf3Agility = fopen("easy_stats/Francis.N/EasyFrancisAgility.txt", "r");
		if(Easycf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Agility, MAX_BUFFER_SFZE, Easycf3Agility) != NULL){
			FEasycf3Agility = atoi(SEasycf3Agility);
		}
		free(Easycf3Agility);
		Easycf3Speed = fopen("easy_stats/Francis.N/EasyFrancisSpeed.txt", "r");
		if(Easycf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SEasycf3Speed, MAX_BUFFER_SFZE, Easycf3Speed) != NULL){
			FEasycf3Speed = atoi(SEasycf3Speed);
		}
		free(Easycf3Speed);
	}
	}
	if(diff == 3){
		if(cf1 == 1){
		Mediumcf1Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	if(cf1 == 2){
		Mediumcf1Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	if(cf1 == 3){
		Mediumcf1Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	if(cf1 == 4){
		Mediumcf1Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	if(cf1 == 5){
		Mediumcf1Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	if(cf1 == 6){
		Mediumcf1Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Name, MAX_BUFFER_SFZE, Mediumcf1Name) != NULL){
		}
		free(Mediumcf1Name);
		Mediumcf1Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Hp, MAX_BUFFER_SFZE, Mediumcf1Hp) != NULL){
			FMediumcf1Hp = atoi(SMediumcf1Hp);
		}
		free(Mediumcf1Hp);
		Mediumcf1HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1HpMax, MAX_BUFFER_SFZE, Mediumcf1HpMax) != NULL){
			FMediumcf1HpMax = atoi(SMediumcf1HpMax);
		}
		free(Mediumcf1HpMax);
		Mediumcf1Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Attack, MAX_BUFFER_SFZE, Mediumcf1Attack) != NULL){
			FMediumcf1Attack = atoi(SMediumcf1Attack);
		}
		free(Mediumcf1Attack);
		Mediumcf1Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Defense, MAX_BUFFER_SFZE, Mediumcf1Defense) != NULL){
			FMediumcf1Defense = atoi(SMediumcf1Defense);
		}
		free(Mediumcf1Defense);
		Mediumcf1Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Agility, MAX_BUFFER_SFZE, Mediumcf1Agility) != NULL){
			FMediumcf1Agility = atoi(SMediumcf1Agility);
		}
		free(Mediumcf1Agility);
		Mediumcf1Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf1Speed, MAX_BUFFER_SFZE, Mediumcf1Speed) != NULL){
			FMediumcf1Speed = atoi(SMediumcf1Speed);
		}
		free(Mediumcf1Speed);
	}
	
	
	
	
	if(cf2 == 1){
		Mediumcf2Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	if(cf2 == 2){
		Mediumcf2Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	if(cf2 == 3){
		Mediumcf2Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	if(cf2 == 4){
		Mediumcf2Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	if(cf2 == 5){
		Mediumcf2Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	if(cf2 == 6){
		Mediumcf2Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Name, MAX_BUFFER_SFZE, Mediumcf2Name) != NULL){
		}
		free(Mediumcf2Name);
		Mediumcf2Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Hp, MAX_BUFFER_SFZE, Mediumcf2Hp) != NULL){
			FMediumcf2Hp = atoi(SMediumcf2Hp);
		}
		free(Mediumcf2Hp);
		Mediumcf2HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2HpMax, MAX_BUFFER_SFZE, Mediumcf2HpMax) != NULL){
			FMediumcf2HpMax = atoi(SMediumcf2HpMax);
		}
		free(Mediumcf2HpMax);
		Mediumcf2Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Attack, MAX_BUFFER_SFZE, Mediumcf2Attack) != NULL){
			FMediumcf2Attack = atoi(SMediumcf2Attack);
		}
		free(Mediumcf2Attack);
		Mediumcf2Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Defense, MAX_BUFFER_SFZE, Mediumcf2Defense) != NULL){
			FMediumcf2Defense = atoi(SMediumcf2Defense);
		}
		free(Mediumcf2Defense);
		Mediumcf2Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Agility, MAX_BUFFER_SFZE, Mediumcf2Agility) != NULL){
			FMediumcf2Agility = atoi(SMediumcf2Agility);
		}
		free(Mediumcf2Agility);
		Mediumcf2Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf2Speed, MAX_BUFFER_SFZE, Mediumcf2Speed) != NULL){
			FMediumcf2Speed = atoi(SMediumcf2Speed);
		}
		free(Mediumcf2Speed);
	}
	
	
	
	
	if(cf3 == 1){
		Mediumcf3Name = fopen("medium_stats/Khabib.N/MediumKhabibName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Khabib.N/MediumKhabibHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Khabib.N/MediumKhabibHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Khabib.N/MediumKhabibAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Khabib.N/MediumKhabibDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Khabib.N/MediumKhabibAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Khabib.N/MediumKhabibSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	if(cf3 == 2){
		Mediumcf3Name = fopen("medium_stats/Conor.M/MediumConorName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Conor.M/MediumConorHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Conor.M/MediumConorHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Conor.M/MediumConorAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Conor.M/MediumConorDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Conor.M/MediumConorAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Conor.M/MediumConorSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	if(cf3 == 3){
		Mediumcf3Name = fopen("medium_stats/Charles.O/MediumCharlesName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Charles.O/MediumCharlesHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Charles.O/MediumCharlesHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Charles.O/MediumCharlesAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Charles.O/MediumCharlesDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Charles.O/MediumCharlesAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Charles.O/MediumCharlesSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	if(cf3 == 4){
		Mediumcf3Name = fopen("medium_stats/Khamzat.C/MediumKhamzatName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Khamzat.C/MediumKhamzatHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Khamzat.C/MediumKhamzatHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Khamzat.C/MediumKhamzatAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Khamzat.C/MediumKhamzatDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Khamzat.C/MediumKhamzatAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Khamzat.C/MediumKhamzatSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	if(cf3 == 5){
		Mediumcf3Name = fopen("medium_stats/Ciryl.G/MediumCirylName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Ciryl.G/MediumCirylHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Ciryl.G/MediumCirylHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Ciryl.G/MediumCirylAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Ciryl.G/MediumCirylDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Ciryl.G/MediumCirylAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Ciryl.G/MediumCirylSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	if(cf3 == 6){
		Mediumcf3Name = fopen("medium_stats/Francis.N/MediumFrancisName.txt", "r");
		if(Mediumcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Name, MAX_BUFFER_SFZE, Mediumcf3Name) != NULL){
		}
		free(Mediumcf3Name);
		Mediumcf3Hp = fopen("medium_stats/Francis.N/MediumFrancisHp.txt", "r");
		if(Mediumcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Hp, MAX_BUFFER_SFZE, Mediumcf3Hp) != NULL){
			FMediumcf3Hp = atoi(SMediumcf3Hp);
		}
		free(Mediumcf3Hp);
		Mediumcf3HpMax = fopen("medium_stats/Francis.N/MediumFrancisHpMax.txt", "r");
		if(Mediumcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3HpMax, MAX_BUFFER_SFZE, Mediumcf3HpMax) != NULL){
			FMediumcf3HpMax = atoi(SMediumcf3HpMax);
		}
		free(Mediumcf3HpMax);
		Mediumcf3Attack = fopen("medium_stats/Francis.N/MediumFrancisAttack.txt", "r");
		if(Mediumcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Attack, MAX_BUFFER_SFZE, Mediumcf3Attack) != NULL){
			FMediumcf3Attack = atoi(SMediumcf3Attack);
		}
		free(Mediumcf3Attack);
		Mediumcf3Defense = fopen("medium_stats/Francis.N/MediumFrancisDefense.txt", "r");
		if(Mediumcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Defense, MAX_BUFFER_SFZE, Mediumcf3Defense) != NULL){
			FMediumcf3Defense = atoi(SMediumcf3Defense);
		}
		free(Mediumcf3Defense);
		Mediumcf3Agility = fopen("medium_stats/Francis.N/MediumFrancisAgility.txt", "r");
		if(Mediumcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Agility, MAX_BUFFER_SFZE, Mediumcf3Agility) != NULL){
			FMediumcf3Agility = atoi(SMediumcf3Agility);
		}
		free(Mediumcf3Agility);
		Mediumcf3Speed = fopen("medium_stats/Francis.N/MediumFrancisSpeed.txt", "r");
		if(Mediumcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SMediumcf3Speed, MAX_BUFFER_SFZE, Mediumcf3Speed) != NULL){
			FMediumcf3Speed = atoi(SMediumcf3Speed);
		}
		free(Mediumcf3Speed);
	}
	}
	if(diff == 4){
		if(cf1 == 1){
		Hardcf1Name = fopen("hard_stats/Khabib.N/HardKhabibName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Khabib.N/HardKhabibHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Khabib.N/HardKhabibHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Khabib.N/HardKhabibAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Khabib.N/HardKhabibDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Khabib.N/HardKhabibAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Khabib.N/HardKhabibSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	if(cf1 == 2){
		Hardcf1Name = fopen("hard_stats/Conor.M/HardConorName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Conor.M/HardConorHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Conor.M/HardConorHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Conor.M/HardConorAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Conor.M/HardConorDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Conor.M/HardConorAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Conor.M/HardConorSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	if(cf1 == 3){
		Hardcf1Name = fopen("hard_stats/Charles.O/HardCharlesName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Charles.O/HardCharlesHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Charles.O/HardCharlesHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Charles.O/HardCharlesAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Charles.O/HardCharlesDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Charles.O/HardCharlesAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Charles.O/HardCharlesSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	if(cf1 == 4){
		Hardcf1Name = fopen("hard_stats/Khamzat.C/HardKhamzatName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Khamzat.C/HardKhamzatHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Khamzat.C/HardKhamzatHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Khamzat.C/HardKhamzatAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Khamzat.C/HardKhamzatDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Khamzat.C/HardKhamzatAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Khamzat.C/HardKhamzatSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	if(cf1 == 5){
		Hardcf1Name = fopen("hard_stats/Ciryl.G/HardCirylName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Ciryl.G/HardCirylHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Ciryl.G/HardCirylHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Ciryl.G/HardCirylAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Ciryl.G/HardCirylDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Ciryl.G/HardCirylAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Ciryl.G/HardCirylSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	if(cf1 == 6){
		Hardcf1Name = fopen("hard_stats/Francis.N/HardFrancisName.txt", "r");
		if(Hardcf1Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Name, MAX_BUFFER_SFZE, Hardcf1Name) != NULL){
		}
		free(Hardcf1Name);
		Hardcf1Hp = fopen("hard_stats/Francis.N/HardFrancisHp.txt", "r");
		if(Hardcf1Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Hp, MAX_BUFFER_SFZE, Hardcf1Hp) != NULL){
			FHardcf1Hp = atoi(SHardcf1Hp);
		}
		free(Hardcf1Hp);
		Hardcf1HpMax = fopen("hard_stats/Francis.N/HardFrancisHpMax.txt", "r");
		if(Hardcf1HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1HpMax, MAX_BUFFER_SFZE, Hardcf1HpMax) != NULL){
			FHardcf1HpMax = atoi(SHardcf1HpMax);
		}
		free(Hardcf1HpMax);
		Hardcf1Attack = fopen("hard_stats/Francis.N/HardFrancisAttack.txt", "r");
		if(Hardcf1Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Attack, MAX_BUFFER_SFZE, Hardcf1Attack) != NULL){
			FHardcf1Attack = atoi(SHardcf1Attack);
		}
		free(Hardcf1Attack);
		Hardcf1Defense = fopen("hard_stats/Francis.N/HardFrancisDefense.txt", "r");
		if(Hardcf1Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Defense, MAX_BUFFER_SFZE, Hardcf1Defense) != NULL){
			FHardcf1Defense = atoi(SHardcf1Defense);
		}
		free(Hardcf1Defense);
		Hardcf1Agility = fopen("hard_stats/Francis.N/HardFrancisAgility.txt", "r");
		if(Hardcf1Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Agility, MAX_BUFFER_SFZE, Hardcf1Agility) != NULL){
			FHardcf1Agility = atoi(SHardcf1Agility);
		}
		free(Hardcf1Agility);
		Hardcf1Speed = fopen("hard_stats/Francis.N/HardFrancisSpeed.txt", "r");
		if(Hardcf1Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf1Speed, MAX_BUFFER_SFZE, Hardcf1Speed) != NULL){
			FHardcf1Speed = atoi(SHardcf1Speed);
		}
		free(Hardcf1Speed);
	}
	
	
	
	
	if(cf2 == 1){
		Hardcf2Name = fopen("hard_stats/Khabib.N/HardKhabibName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Khabib.N/HardKhabibHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Khabib.N/HardKhabibHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Khabib.N/HardKhabibAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Khabib.N/HardKhabibDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Khabib.N/HardKhabibAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Khabib.N/HardKhabibSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	if(cf2 == 2){
		Hardcf2Name = fopen("hard_stats/Conor.M/HardConorName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Conor.M/HardConorHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Conor.M/HardConorHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Conor.M/HardConorAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Conor.M/HardConorDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Conor.M/HardConorAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Conor.M/HardConorSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	if(cf2 == 3){
		Hardcf2Name = fopen("hard_stats/Charles.O/HardCharlesName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Charles.O/HardCharlesHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Charles.O/HardCharlesHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Charles.O/HardCharlesAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Charles.O/HardCharlesDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Charles.O/HardCharlesAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Charles.O/HardCharlesSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	if(cf2 == 4){
		Hardcf2Name = fopen("hard_stats/Khamzat.C/HardKhamzatName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Khamzat.C/HardKhamzatHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Khamzat.C/HardKhamzatHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Khamzat.C/HardKhamzatAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Khamzat.C/HardKhamzatDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Khamzat.C/HardKhamzatAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Khamzat.C/HardKhamzatSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	if(cf2 == 5){
		Hardcf2Name = fopen("hard_stats/Ciryl.G/HardCirylName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Ciryl.G/HardCirylHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Ciryl.G/HardCirylHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Ciryl.G/HardCirylAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Ciryl.G/HardCirylDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Ciryl.G/HardCirylAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Ciryl.G/HardCirylSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	if(cf2 == 6){
		Hardcf2Name = fopen("hard_stats/Francis.N/HardFrancisName.txt", "r");
		if(Hardcf2Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Name, MAX_BUFFER_SFZE, Hardcf2Name) != NULL){
		}
		free(Hardcf2Name);
		Hardcf2Hp = fopen("hard_stats/Francis.N/HardFrancisHp.txt", "r");
		if(Hardcf2Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Hp, MAX_BUFFER_SFZE, Hardcf2Hp) != NULL){
			FHardcf2Hp = atoi(SHardcf2Hp);
		}
		free(Hardcf2Hp);
		Hardcf2HpMax = fopen("hard_stats/Francis.N/HardFrancisHpMax.txt", "r");
		if(Hardcf2HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2HpMax, MAX_BUFFER_SFZE, Hardcf2HpMax) != NULL){
			FHardcf2HpMax = atoi(SHardcf2HpMax);
		}
		free(Hardcf2HpMax);
		Hardcf2Attack = fopen("hard_stats/Francis.N/HardFrancisAttack.txt", "r");
		if(Hardcf2Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Attack, MAX_BUFFER_SFZE, Hardcf2Attack) != NULL){
			FHardcf2Attack = atoi(SHardcf2Attack);
		}
		free(Hardcf2Attack);
		Hardcf2Defense = fopen("hard_stats/Francis.N/HardFrancisDefense.txt", "r");
		if(Hardcf2Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Defense, MAX_BUFFER_SFZE, Hardcf2Defense) != NULL){
			FHardcf2Defense = atoi(SHardcf2Defense);
		}
		free(Hardcf2Defense);
		Hardcf2Agility = fopen("hard_stats/Francis.N/HardFrancisAgility.txt", "r");
		if(Hardcf2Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Agility, MAX_BUFFER_SFZE, Hardcf2Agility) != NULL){
			FHardcf2Agility = atoi(SHardcf2Agility);
		}
		free(Hardcf2Agility);
		Hardcf2Speed = fopen("hard_stats/Francis.N/HardFrancisSpeed.txt", "r");
		if(Hardcf2Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf2Speed, MAX_BUFFER_SFZE, Hardcf2Speed) != NULL){
			FHardcf2Speed = atoi(SHardcf2Speed);
		}
		free(Hardcf2Speed);
	}
	
	
	
	
	if(cf3 == 1){
		Hardcf3Name = fopen("hard_stats/Khabib.N/HardKhabibName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Khabib.N/HardKhabibHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Khabib.N/HardKhabibHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Khabib.N/HardKhabibAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Khabib.N/HardKhabibDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Khabib.N/HardKhabibAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Khabib.N/HardKhabibSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	if(cf3 == 2){
		Hardcf3Name = fopen("hard_stats/Conor.M/HardConorName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Conor.M/HardConorHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Conor.M/HardConorHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Conor.M/HardConorAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Conor.M/HardConorDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Conor.M/HardConorAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Conor.M/HardConorSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	if(cf3 == 3){
		Hardcf3Name = fopen("hard_stats/Charles.O/HardCharlesName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Charles.O/HardCharlesHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Charles.O/HardCharlesHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Charles.O/HardCharlesAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Charles.O/HardCharlesDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Charles.O/HardCharlesAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Charles.O/HardCharlesSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	if(cf3 == 4){
		Hardcf3Name = fopen("hard_stats/Khamzat.C/HardKhamzatName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Khamzat.C/HardKhamzatHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Khamzat.C/HardKhamzatHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Khamzat.C/HardKhamzatAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Khamzat.C/HardKhamzatDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Khamzat.C/HardKhamzatAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Khamzat.C/HardKhamzatSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	if(cf3 == 5){
		Hardcf3Name = fopen("hard_stats/Ciryl.G/HardCirylName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Ciryl.G/HardCirylHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Ciryl.G/HardCirylHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Ciryl.G/HardCirylAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Ciryl.G/HardCirylDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Ciryl.G/HardCirylAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Ciryl.G/HardCirylSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	if(cf3 == 6){
		Hardcf3Name = fopen("hard_stats/Francis.N/HardFrancisName.txt", "r");
		if(Hardcf3Name == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Name, MAX_BUFFER_SFZE, Hardcf3Name) != NULL){
		}
		free(Hardcf3Name);
		Hardcf3Hp = fopen("hard_stats/Francis.N/HardFrancisHp.txt", "r");
		if(Hardcf3Hp == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Hp, MAX_BUFFER_SFZE, Hardcf3Hp) != NULL){
			FHardcf3Hp = atoi(SHardcf3Hp);
		}
		free(Hardcf3Hp);
		Hardcf3HpMax = fopen("hard_stats/Francis.N/HardFrancisHpMax.txt", "r");
		if(Hardcf3HpMax == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3HpMax, MAX_BUFFER_SFZE, Hardcf3HpMax) != NULL){
			FHardcf3HpMax = atoi(SHardcf3HpMax);
		}
		free(Hardcf3HpMax);
		Hardcf3Attack = fopen("hard_stats/Francis.N/HardFrancisAttack.txt", "r");
		if(Hardcf3Attack == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Attack, MAX_BUFFER_SFZE, Hardcf3Attack) != NULL){
			FHardcf3Attack = atoi(SHardcf3Attack);
		}
		free(Hardcf3Attack);
		Hardcf3Defense = fopen("hard_stats/Francis.N/HardFrancisDefense.txt", "r");
		if(Hardcf3Defense == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Defense, MAX_BUFFER_SFZE, Hardcf3Defense) != NULL){
			FHardcf3Defense = atoi(SHardcf3Defense);
		}
		free(Hardcf3Defense);
		Hardcf3Agility = fopen("hard_stats/Francis.N/HardFrancisAgility.txt", "r");
		if(Hardcf3Agility == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Agility, MAX_BUFFER_SFZE, Hardcf3Agility) != NULL){
			FHardcf3Agility = atoi(SHardcf3Agility);
		}
		free(Hardcf3Agility);
		Hardcf3Speed = fopen("hard_stats/Francis.N/HardFrancisSpeed.txt", "r");
		if(Hardcf3Speed == NULL){
			printf("Error loading file.\n");
			exit (1);
		}
		while (fgets(SHardcf3Speed, MAX_BUFFER_SFZE, Hardcf3Speed) != NULL){
			FHardcf3Speed = atoi(SHardcf3Speed);
		}
		free(Hardcf3Speed);
	}
	}
	
	clearScreen();
	startPresentation();
	
	int fChoice;
	int oChoice;
	int wtdo;
	if(diff == 1){
	
		printf("                The teams are :\n\n");
		printf(" The Team N° 1 : (Your Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SMediumpf1Name);
		printf(" Hp : %f\n", FMediumpf1Hp);
		printf(" HpMax : %f\n", FMediumpf1HpMax);
		printf(" Attack : %f\n", FMediumpf1Attack);
		printf(" Defense : %f\n", FMediumpf1Defense);
		printf(" Agility : %f\n", FMediumpf1Agility);
		printf(" Speed : %f\n", FMediumpf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SMediumpf2Name);
		printf(" Hp : %f\n", FMediumpf2Hp);
		printf(" HpMax : %f\n", FMediumpf2HpMax);
		printf(" Attack : %f\n", FMediumpf2Attack);
		printf(" Defense : %f\n", FMediumpf2Defense);
		printf(" Agility : %f\n", FMediumpf2Agility);
		printf(" Speed : %f\n", FMediumpf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SMediumpf3Name);
		printf(" Hp : %f\n", FMediumpf3Hp);
		printf(" HpMax : %f\n", FMediumpf3HpMax);
		printf(" Attack : %f\n", FMediumpf3Attack);
		printf(" Defense : %f\n", FMediumpf3Defense);
		printf(" Agility : %f\n", FMediumpf3Agility);
		printf(" Speed : %f\n", FMediumpf3Speed);
		printf("\n\n");
		
		
		
		printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SNoobcf1Name);
		printf(" Hp : %f\n", FNoobcf1Hp);
		printf(" HpMax : %f\n", FNoobcf1HpMax);
		printf(" Attack : %f\n", FNoobcf1Attack);
		printf(" Defense : %f\n", FNoobcf1Defense);
		printf(" Agility : %f\n", FNoobcf1Agility);
		printf(" Speed : %f\n", FNoobcf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SNoobcf2Name);
		printf(" Hp : %f\n", FNoobcf2Hp);
		printf(" HpMax : %f\n", FNoobcf2HpMax);
		printf(" Attack : %f\n", FNoobcf2Attack);
		printf(" Defense : %f\n", FNoobcf2Defense);
		printf(" Agility : %f\n", FNoobcf2Agility);
		printf(" Speed : %f\n", FNoobcf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SNoobcf3Name);
		printf(" Hp : %f\n", FNoobcf3Hp);
		printf(" HpMax : %f\n", FNoobcf3HpMax);
		printf(" Attack : %f\n", FNoobcf3Attack);
		printf(" Defense : %f\n", FNoobcf3Defense);
		printf(" Agility : %f\n", FNoobcf3Agility);
		printf(" Speed : %f\n", FNoobcf3Speed);
		printf("\n\n\n");
		
		
		while(((FMediumpf1Hp > 0) || (FMediumpf2Hp > 0) || (FMediumpf3Hp > 0)) || ((FNoobcf1Hp > 0) || (FNoobcf2Hp > 0) || (FNoobcf3Hp > 0))){
			
			
			
			printf(" Which of your fighters do you want to fight with ?\n\n");
			printf(" 1. %s 2. %s 3. %s\n", SMediumpf1Name, SMediumpf2Name, SMediumpf3Name);
			printf(" Your fighter ? (type your fighter's number)\t");
			scanf("%d", &fChoice);
			printf("\n\n\n");
			
			
			printf(" What do you want to do ?\n\n");
			printf(" 1. Attack\t\t\t 2. Have more Hp\n\n");
			printf(" Your choice ? (type your choice's number)\t");
			scanf("%d", &wtdo);
			printf("\n\n\n");
			
			if(wtdo == 1){
				printf(" Which of the computer's fighters do you want to fight with ?\n\n");
				printf(" 1. %s 2. %s 3. %s\n", SNoobcf1Name, SNoobcf2Name, SNoobcf3Name);
				printf(" Your opponent ? (type your opponent's number)\t");
				scanf("%d", &oChoice);
				printf("\n\n\n");
			}
			
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FNoobcf1Hp -= 15 * FMediumpf1Attack * ((100 - FNoobcf1Defense)/100);
					}
					if(oChoice == 2){
						FNoobcf2Hp -= 15 * FMediumpf1Attack * ((100 - FNoobcf2Defense)/100);
					}
					if(oChoice == 3){
						FNoobcf3Hp -= 15 * FMediumpf1Attack * ((100 - FNoobcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FNoobcf1Hp -= 15 * FMediumpf2Attack * ((100 - FNoobcf1Defense)/100);
					}
					if(oChoice == 2){
						FNoobcf2Hp -= 15 * FMediumpf2Attack * ((100 - FNoobcf2Defense)/100);
					}
					if(oChoice == 3){
						FNoobcf3Hp -= 15 * FMediumpf2Attack * ((100 - FNoobcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FNoobcf1Hp -= 15 * FMediumpf3Attack * ((100 - FNoobcf1Defense)/100);
					}
					if(oChoice == 2){
						FNoobcf2Hp -= 15 * FMediumpf3Attack * ((100 - FNoobcf2Defense)/100);
					}
					if(oChoice == 3){
						FNoobcf3Hp -= 15 * FMediumpf3Attack * ((100 - FNoobcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf3Hp += (rand()%10)+5;
				}
			}
			
			fChoice = (rand()%3)+1;
			wtdo = (rand()%2)+1;
			oChoice = (rand()%3)+1;
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 15 * FNoobcf1Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 15 * FNoobcf1Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 15 * FNoobcf1Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FNoobcf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 15 * FNoobcf2Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 15 * FNoobcf2Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 15 * FNoobcf2Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FNoobcf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 15 * FNoobcf3Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 15 * FNoobcf3Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 15 * FNoobcf3Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FNoobcf3Hp += (rand()%10)+5;
				}
			}
			
			printf("                The current teams are :\n\n");
			printf(" The Team N° 1 : (Your Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SMediumpf1Name);
			printf(" Hp : %f\n", FMediumpf1Hp);
			printf(" HpMax : %f\n", FMediumpf1HpMax);
			printf(" Attack : %f\n", FMediumpf1Attack);
			printf(" Defense : %f\n", FMediumpf1Defense);
			printf(" Agility : %f\n", FMediumpf1Agility);
			printf(" Speed : %f\n", FMediumpf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SMediumpf2Name);
			printf(" Hp : %f\n", FMediumpf2Hp);
			printf(" HpMax : %f\n", FMediumpf2HpMax);
			printf(" Attack : %f\n", FMediumpf2Attack);
			printf(" Defense : %f\n", FMediumpf2Defense);
			printf(" Agility : %f\n", FMediumpf2Agility);
			printf(" Speed : %f\n", FMediumpf2Speed);
			printf("\n\n");
		
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SMediumpf3Name);
			printf(" Hp : %f\n", FMediumpf3Hp);
			printf(" HpMax : %f\n", FMediumpf3HpMax);
			printf(" Attack : %f\n", FMediumpf3Attack);
			printf(" Defense : %f\n", FMediumpf3Defense);
			printf(" Agility : %f\n", FMediumpf3Agility);
			printf(" Speed : %f\n", FMediumpf3Speed);
			printf("\n\n");
		
		
		
			printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SNoobcf1Name);
			printf(" Hp : %f\n", FNoobcf1Hp);
			printf(" HpMax : %f\n", FNoobcf1HpMax);
			printf(" Attack : %f\n", FNoobcf1Attack);
			printf(" Defense : %f\n", FNoobcf1Defense);
			printf(" Agility : %f\n", FNoobcf1Agility);
			printf(" Speed : %f\n", FNoobcf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SNoobcf2Name);
			printf(" Hp : %f\n", FNoobcf2Hp);
			printf(" HpMax : %f\n", FNoobcf2HpMax);
			printf(" Attack : %f\n", FNoobcf2Attack);
			printf(" Defense : %f\n", FNoobcf2Defense);
			printf(" Agility : %f\n", FNoobcf2Agility);
			printf(" Speed : %f\n", FNoobcf2Speed);
			printf("\n\n");
			
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SNoobcf3Name);
			printf(" Hp : %f\n", FNoobcf3Hp);
			printf(" HpMax : %f\n", FNoobcf3HpMax);
			printf(" Attack : %f\n", FNoobcf3Attack);
			printf(" Defense : %f\n", FNoobcf3Defense);
			printf(" Agility : %f\n", FNoobcf3Agility);
			printf(" Speed : %f\n", FNoobcf3Speed);
			printf("\n\n");
			
			
			if((FMediumpf1Hp <= 0) && (FMediumpf2Hp <= 0) && (FMediumpf3Hp <= 0)){
				printf("You lose !!!");
			}
			if((FNoobcf1Hp <= 0) && (FNoobcf2Hp <= 0) && (FNoobcf3Hp <= 0)){
				printf("You won !!!");
			}
		}
	}
	
	if(diff == 2){
	
		printf("                The teams are :\n\n");
		printf(" The Team N° 1 : (Your Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SMediumpf1Name);
		printf(" Hp : %f\n", FMediumpf1Hp);
		printf(" HpMax : %f\n", FMediumpf1HpMax);
		printf(" Attack : %f\n", FMediumpf1Attack);
		printf(" Defense : %f\n", FMediumpf1Defense);
		printf(" Agility : %f\n", FMediumpf1Agility);
		printf(" Speed : %f\n", FMediumpf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SMediumpf2Name);
		printf(" Hp : %f\n", FMediumpf2Hp);
		printf(" HpMax : %f\n", FMediumpf2HpMax);
		printf(" Attack : %f\n", FMediumpf2Attack);
		printf(" Defense : %f\n", FMediumpf2Defense);
		printf(" Agility : %f\n", FMediumpf2Agility);
		printf(" Speed : %f\n", FMediumpf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SMediumpf3Name);
		printf(" Hp : %f\n", FMediumpf3Hp);
		printf(" HpMax : %f\n", FMediumpf3HpMax);
		printf(" Attack : %f\n", FMediumpf3Attack);
		printf(" Defense : %f\n", FMediumpf3Defense);
		printf(" Agility : %f\n", FMediumpf3Agility);
		printf(" Speed : %f\n", FMediumpf3Speed);
		printf("\n\n");
		
		
		
		printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SEasycf1Name);
		printf(" Hp : %f\n", FEasycf1Hp);
		printf(" HpMax : %f\n", FEasycf1HpMax);
		printf(" Attack : %f\n", FEasycf1Attack);
		printf(" Defense : %f\n", FEasycf1Defense);
		printf(" Agility : %f\n", FEasycf1Agility);
		printf(" Speed : %f\n", FEasycf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SEasycf2Name);
		printf(" Hp : %f\n", FEasycf2Hp);
		printf(" HpMax : %f\n", FEasycf2HpMax);
		printf(" Attack : %f\n", FEasycf2Attack);
		printf(" Defense : %f\n", FEasycf2Defense);
		printf(" Agility : %f\n", FEasycf2Agility);
		printf(" Speed : %f\n", FEasycf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SEasycf3Name);
		printf(" Hp : %f\n", FEasycf3Hp);
		printf(" HpMax : %f\n", FEasycf3HpMax);
		printf(" Attack : %f\n", FEasycf3Attack);
		printf(" Defense : %f\n", FEasycf3Defense);
		printf(" Agility : %f\n", FEasycf3Agility);
		printf(" Speed : %f\n", FEasycf3Speed);
		printf("\n\n\n");
		
		
		while(((FMediumpf1Hp > 0) || (FMediumpf2Hp > 0) || (FMediumpf3Hp > 0)) || ((FEasycf1Hp > 0) || (FEasycf2Hp > 0) || (FEasycf3Hp > 0))){
			
			
			
			printf(" Which of your fighters do you want to fight with ?\n\n");
			printf(" 1. %s 2. %s 3. %s\n", SMediumpf1Name, SMediumpf2Name, SMediumpf3Name);
			printf(" Your fighter ? (type your fighter's number)\t");
			scanf("%d", &fChoice);
			printf("\n\n\n");
			
			
			printf(" What do you want to do ?\n\n");
			printf(" 1. Attack\t\t\t 2. Have more Hp\n\n");
			printf(" Your choice ? (type your choice's number)\t");
			scanf("%d", &wtdo);
			printf("\n\n\n");
			
			if(wtdo == 1){
				printf(" Which of the computer's fighters do you want to fight with ?\n\n");
				printf(" 1. %s 2. %s 3. %s\n", SEasycf1Name, SEasycf2Name, SEasycf3Name);
				printf(" Your opponent ? (type your opponent's number)\t");
				scanf("%d", &oChoice);
				printf("\n\n\n");
			}
			
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FEasycf1Hp -= 12 * FMediumpf1Attack * ((100 - FEasycf1Defense)/100);
					}
					if(oChoice == 2){
						FEasycf2Hp -= 12 * FMediumpf1Attack * ((100 - FEasycf2Defense)/100);
					}
					if(oChoice == 3){
						FEasycf3Hp -= 12 * FMediumpf1Attack * ((100 - FEasycf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FEasycf1Hp -= 12 * FMediumpf2Attack * ((100 - FEasycf1Defense)/100);
					}
					if(oChoice == 2){
						FEasycf2Hp -= 12 * FMediumpf2Attack * ((100 - FEasycf2Defense)/100);
					}
					if(oChoice == 3){
						FEasycf3Hp -= 12 * FMediumpf2Attack * ((100 - FEasycf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FEasycf1Hp -= 12 * FMediumpf3Attack * ((100 - FEasycf1Defense)/100);
					}
					if(oChoice == 2){
						FEasycf2Hp -= 12 * FMediumpf3Attack * ((100 - FEasycf2Defense)/100);
					}
					if(oChoice == 3){
						FEasycf3Hp -= 12 * FMediumpf3Attack * ((100 - FEasycf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf3Hp += (rand()%10)+5;
				}
			}
			
			fChoice = (rand()%3)+1;
			wtdo = (rand()%2)+1;
			oChoice = (rand()%3)+1;
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 12 * FEasycf1Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 12 * FEasycf1Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 12 * FEasycf1Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FEasycf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 12 * FEasycf2Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 12 * FEasycf2Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 12 * FEasycf2Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FEasycf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 12 * FEasycf3Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 12 * FEasycf3Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 12 * FEasycf3Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FEasycf3Hp += (rand()%10)+5;
				}
			}
			
			printf("                The current teams are :\n\n");
			printf(" The Team N° 1 : (Your Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SMediumpf1Name);
			printf(" Hp : %f\n", FMediumpf1Hp);
			printf(" HpMax : %f\n", FMediumpf1HpMax);
			printf(" Attack : %f\n", FMediumpf1Attack);
			printf(" Defense : %f\n", FMediumpf1Defense);
			printf(" Agility : %f\n", FMediumpf1Agility);
			printf(" Speed : %f\n", FMediumpf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SMediumpf2Name);
			printf(" Hp : %f\n", FMediumpf2Hp);
			printf(" HpMax : %f\n", FMediumpf2HpMax);
			printf(" Attack : %f\n", FMediumpf2Attack);
			printf(" Defense : %f\n", FMediumpf2Defense);
			printf(" Agility : %f\n", FMediumpf2Agility);
			printf(" Speed : %f\n", FMediumpf2Speed);
			printf("\n\n");
		
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SMediumpf3Name);
			printf(" Hp : %f\n", FMediumpf3Hp);
			printf(" HpMax : %f\n", FMediumpf3HpMax);
			printf(" Attack : %f\n", FMediumpf3Attack);
			printf(" Defense : %f\n", FMediumpf3Defense);
			printf(" Agility : %f\n", FMediumpf3Agility);
			printf(" Speed : %f\n", FMediumpf3Speed);
			printf("\n\n");
		
		
		
			printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SEasycf1Name);
			printf(" Hp : %f\n", FEasycf1Hp);
			printf(" HpMax : %f\n", FEasycf1HpMax);
			printf(" Attack : %f\n", FEasycf1Attack);
			printf(" Defense : %f\n", FEasycf1Defense);
			printf(" Agility : %f\n", FEasycf1Agility);
			printf(" Speed : %f\n", FEasycf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SEasycf2Name);
			printf(" Hp : %f\n", FEasycf2Hp);
			printf(" HpMax : %f\n", FEasycf2HpMax);
			printf(" Attack : %f\n", FEasycf2Attack);
			printf(" Defense : %f\n", FEasycf2Defense);
			printf(" Agility : %f\n", FEasycf2Agility);
			printf(" Speed : %f\n", FEasycf2Speed);
			printf("\n\n");
			
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SEasycf3Name);
			printf(" Hp : %f\n", FEasycf3Hp);
			printf(" HpMax : %f\n", FEasycf3HpMax);
			printf(" Attack : %f\n", FEasycf3Attack);
			printf(" Defense : %f\n", FEasycf3Defense);
			printf(" Agility : %f\n", FEasycf3Agility);
			printf(" Speed : %f\n", FEasycf3Speed);
			printf("\n\n");
			
			
			if((FMediumpf1Hp <= 0) && (FMediumpf2Hp <= 0) && (FMediumpf3Hp <= 0)){
				printf("You lose !!!");
			}
			if((FEasycf1Hp <= 0) && (FEasycf2Hp <= 0) && (FEasycf3Hp <= 0)){
				printf("You won !!!");
			}
		}
	}
	
	if(diff == 3){
	
		printf("                The teams are :\n\n");
		printf(" The Team N° 1 : (Your Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SMediumpf1Name);
		printf(" Hp : %f\n", FMediumpf1Hp);
		printf(" HpMax : %f\n", FMediumpf1HpMax);
		printf(" Attack : %f\n", FMediumpf1Attack);
		printf(" Defense : %f\n", FMediumpf1Defense);
		printf(" Agility : %f\n", FMediumpf1Agility);
		printf(" Speed : %f\n", FMediumpf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SMediumpf2Name);
		printf(" Hp : %f\n", FMediumpf2Hp);
		printf(" HpMax : %f\n", FMediumpf2HpMax);
		printf(" Attack : %f\n", FMediumpf2Attack);
		printf(" Defense : %f\n", FMediumpf2Defense);
		printf(" Agility : %f\n", FMediumpf2Agility);
		printf(" Speed : %f\n", FMediumpf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SMediumpf3Name);
		printf(" Hp : %f\n", FMediumpf3Hp);
		printf(" HpMax : %f\n", FMediumpf3HpMax);
		printf(" Attack : %f\n", FMediumpf3Attack);
		printf(" Defense : %f\n", FMediumpf3Defense);
		printf(" Agility : %f\n", FMediumpf3Agility);
		printf(" Speed : %f\n", FMediumpf3Speed);
		printf("\n\n");
		
		
		
		printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SMediumcf1Name);
		printf(" Hp : %f\n", FMediumcf1Hp);
		printf(" HpMax : %f\n", FMediumcf1HpMax);
		printf(" Attack : %f\n", FMediumcf1Attack);
		printf(" Defense : %f\n", FMediumcf1Defense);
		printf(" Agility : %f\n", FMediumcf1Agility);
		printf(" Speed : %f\n", FMediumcf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SMediumcf2Name);
		printf(" Hp : %f\n", FMediumcf2Hp);
		printf(" HpMax : %f\n", FMediumcf2HpMax);
		printf(" Attack : %f\n", FMediumcf2Attack);
		printf(" Defense : %f\n", FMediumcf2Defense);
		printf(" Agility : %f\n", FMediumcf2Agility);
		printf(" Speed : %f\n", FMediumcf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SMediumcf3Name);
		printf(" Hp : %f\n", FMediumcf3Hp);
		printf(" HpMax : %f\n", FMediumcf3HpMax);
		printf(" Attack : %f\n", FMediumcf3Attack);
		printf(" Defense : %f\n", FMediumcf3Defense);
		printf(" Agility : %f\n", FMediumcf3Agility);
		printf(" Speed : %f\n", FMediumcf3Speed);
		printf("\n\n\n");
		
		
		while(((FMediumpf1Hp > 0) || (FMediumpf2Hp > 0) || (FMediumpf3Hp > 0)) || ((FMediumcf1Hp > 0) || (FMediumcf2Hp > 0) || (FMediumcf3Hp > 0))){
			
			
			
			printf(" Which of your fighters do you want to fight with ?\n\n");
			printf(" 1. %s 2. %s 3. %s\n", SMediumpf1Name, SMediumpf2Name, SMediumpf3Name);
			printf(" Your fighter ? (type your fighter's number)\t");
			scanf("%d", &fChoice);
			printf("\n\n\n");
			
			
			printf(" What do you want to do ?\n\n");
			printf(" 1. Attack\t\t\t 2. Have more Hp\n\n");
			printf(" Your choice ? (type your choice's number)\t");
			scanf("%d", &wtdo);
			printf("\n\n\n");
			
			if(wtdo == 1){
				printf(" Which of the computer's fighters do you want to fight with ?\n\n");
				printf(" 1. %s 2. %s 3. %s\n", SMediumcf1Name, SMediumcf2Name, SMediumcf3Name);
				printf(" Your opponent ? (type your opponent's number)\t");
				scanf("%d", &oChoice);
				printf("\n\n\n");
			}
			
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumcf1Hp -= 10 * FMediumpf1Attack * ((100 - FMediumcf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumcf2Hp -= 10 * FMediumpf1Attack * ((100 - FMediumcf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumcf3Hp -= 10 * FMediumpf1Attack * ((100 - FMediumcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumcf1Hp -= 10 * FMediumpf2Attack * ((100 - FMediumcf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumcf2Hp -= 10 * FMediumpf2Attack * ((100 - FMediumcf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumcf3Hp -= 10 * FMediumpf2Attack * ((100 - FMediumcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumcf1Hp -= 10 * FMediumpf3Attack * ((100 - FMediumcf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumcf2Hp -= 10 * FMediumpf3Attack * ((100 - FMediumcf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumcf3Hp -= 10 * FMediumpf3Attack * ((100 - FMediumcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf3Hp += (rand()%10)+5;
				}
			}
			
			fChoice = (rand()%3)+1;
			wtdo = (rand()%2)+1;
			oChoice = (rand()%3)+1;
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 10 * FMediumcf1Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 10 * FMediumcf1Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 10 * FMediumcf1Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumcf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 10 * FMediumcf2Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 10 * FMediumcf2Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 10 * FMediumcf2Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumcf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 10 * FMediumcf3Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 10 * FMediumcf3Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 10 * FMediumcf3Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumcf3Hp += (rand()%10)+5;
				}
			}
			
			printf("                The current teams are :\n\n");
			printf(" The Team N° 1 : (Your Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SMediumpf1Name);
			printf(" Hp : %f\n", FMediumpf1Hp);
			printf(" HpMax : %f\n", FMediumpf1HpMax);
			printf(" Attack : %f\n", FMediumpf1Attack);
			printf(" Defense : %f\n", FMediumpf1Defense);
			printf(" Agility : %f\n", FMediumpf1Agility);
			printf(" Speed : %f\n", FMediumpf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SMediumpf2Name);
			printf(" Hp : %f\n", FMediumpf2Hp);
			printf(" HpMax : %f\n", FMediumpf2HpMax);
			printf(" Attack : %f\n", FMediumpf2Attack);
			printf(" Defense : %f\n", FMediumpf2Defense);
			printf(" Agility : %f\n", FMediumpf2Agility);
			printf(" Speed : %f\n", FMediumpf2Speed);
			printf("\n\n");
		
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SMediumpf3Name);
			printf(" Hp : %f\n", FMediumpf3Hp);
			printf(" HpMax : %f\n", FMediumpf3HpMax);
			printf(" Attack : %f\n", FMediumpf3Attack);
			printf(" Defense : %f\n", FMediumpf3Defense);
			printf(" Agility : %f\n", FMediumpf3Agility);
			printf(" Speed : %f\n", FMediumpf3Speed);
			printf("\n\n");
		
		
		
			printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SMediumcf1Name);
			printf(" Hp : %f\n", FMediumcf1Hp);
			printf(" HpMax : %f\n", FMediumcf1HpMax);
			printf(" Attack : %f\n", FMediumcf1Attack);
			printf(" Defense : %f\n", FMediumcf1Defense);
			printf(" Agility : %f\n", FMediumcf1Agility);
			printf(" Speed : %f\n", FMediumcf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SMediumcf2Name);
			printf(" Hp : %f\n", FMediumcf2Hp);
			printf(" HpMax : %f\n", FMediumcf2HpMax);
			printf(" Attack : %f\n", FMediumcf2Attack);
			printf(" Defense : %f\n", FMediumcf2Defense);
			printf(" Agility : %f\n", FMediumcf2Agility);
			printf(" Speed : %f\n", FMediumcf2Speed);
			printf("\n\n");
			
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SMediumcf3Name);
			printf(" Hp : %f\n", FMediumcf3Hp);
			printf(" HpMax : %f\n", FMediumcf3HpMax);
			printf(" Attack : %f\n", FMediumcf3Attack);
			printf(" Defense : %f\n", FMediumcf3Defense);
			printf(" Agility : %f\n", FMediumcf3Agility);
			printf(" Speed : %f\n", FMediumcf3Speed);
			printf("\n\n");
			
			
			if((FMediumpf1Hp <= 0) && (FMediumpf2Hp <= 0) && (FMediumpf3Hp <= 0)){
				printf("You lose !!!");
			}
			if((FMediumcf1Hp <= 0) && (FMediumcf2Hp <= 0) && (FMediumcf3Hp <= 0)){
				printf("You won !!!");
			}
		}
	}
	
	if(diff == 4){
	
		printf("                The teams are :\n\n");
		printf(" The Team N° 1 : (Your Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SMediumpf1Name);
		printf(" Hp : %f\n", FMediumpf1Hp);
		printf(" HpMax : %f\n", FMediumpf1HpMax);
		printf(" Attack : %f\n", FMediumpf1Attack);
		printf(" Defense : %f\n", FMediumpf1Defense);
		printf(" Agility : %f\n", FMediumpf1Agility);
		printf(" Speed : %f\n", FMediumpf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SMediumpf2Name);
		printf(" Hp : %f\n", FMediumpf2Hp);
		printf(" HpMax : %f\n", FMediumpf2HpMax);
		printf(" Attack : %f\n", FMediumpf2Attack);
		printf(" Defense : %f\n", FMediumpf2Defense);
		printf(" Agility : %f\n", FMediumpf2Agility);
		printf(" Speed : %f\n", FMediumpf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SMediumpf3Name);
		printf(" Hp : %f\n", FMediumpf3Hp);
		printf(" HpMax : %f\n", FMediumpf3HpMax);
		printf(" Attack : %f\n", FMediumpf3Attack);
		printf(" Defense : %f\n", FMediumpf3Defense);
		printf(" Agility : %f\n", FMediumpf3Agility);
		printf(" Speed : %f\n", FMediumpf3Speed);
		printf("\n\n");
		
		
		
		printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
		printf(" Fighter N° 1 :\n\n");
		printf(" Name : %s", SHardcf1Name);
		printf(" Hp : %f\n", FHardcf1Hp);
		printf(" HpMax : %f\n", FHardcf1HpMax);
		printf(" Attack : %f\n", FHardcf1Attack);
		printf(" Defense : %f\n", FHardcf1Defense);
		printf(" Agility : %f\n", FHardcf1Agility);
		printf(" Speed : %f\n", FHardcf1Speed);
		printf("\n\n");
		
		printf(" Fighter N° 2 :\n\n");
		printf(" Name : %s", SHardcf2Name);
		printf(" Hp : %f\n", FHardcf2Hp);
		printf(" HpMax : %f\n", FHardcf2HpMax);
		printf(" Attack : %f\n", FHardcf2Attack);
		printf(" Defense : %f\n", FHardcf2Defense);
		printf(" Agility : %f\n", FHardcf2Agility);
		printf(" Speed : %f\n", FHardcf2Speed);
		printf("\n\n");
		
		printf(" Fighter N° 3 :\n\n");
		printf(" Name : %s", SHardcf3Name);
		printf(" Hp : %f\n", FHardcf3Hp);
		printf(" HpMax : %f\n", FHardcf3HpMax);
		printf(" Attack : %f\n", FHardcf3Attack);
		printf(" Defense : %f\n", FHardcf3Defense);
		printf(" Agility : %f\n", FHardcf3Agility);
		printf(" Speed : %f\n", FHardcf3Speed);
		printf("\n\n\n");
		
		
		while(((FMediumpf1Hp > 0) || (FMediumpf2Hp > 0) || (FMediumpf3Hp > 0)) || ((FHardcf1Hp > 0) || (FHardcf2Hp > 0) || (FHardcf3Hp > 0))){
			
			
			
			printf(" Which of your fighters do you want to fight with ?\n\n");
			printf(" 1. %s 2. %s 3. %s\n", SMediumpf1Name, SMediumpf2Name, SMediumpf3Name);
			printf(" Your fighter ? (type your fighter's number)\t");
			scanf("%d", &fChoice);
			printf("\n\n\n");
			
			
			printf(" What do you want to do ?\n\n");
			printf(" 1. Attack\t\t\t 2. Have more Hp\n\n");
			printf(" Your choice ? (type your choice's number)\t");
			scanf("%d", &wtdo);
			printf("\n\n\n");
			
			if(wtdo == 1){
				printf(" Which of the computer's fighters do you want to fight with ?\n\n");
				printf(" 1. %s 2. %s 3. %s\n", SHardcf1Name, SHardcf2Name, SHardcf3Name);
				printf(" Your opponent ? (type your opponent's number)\t");
				scanf("%d", &oChoice);
				printf("\n\n\n");
			}
			
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FHardcf1Hp -= 5 * FMediumpf1Attack * ((100 - FHardcf1Defense)/100);
					}
					if(oChoice == 2){
						FHardcf2Hp -= 5 * FMediumpf1Attack * ((100 - FHardcf2Defense)/100);
					}
					if(oChoice == 3){
						FHardcf3Hp -= 5 * FMediumpf1Attack * ((100 - FHardcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FHardcf1Hp -= 5 * FMediumpf2Attack * ((100 - FHardcf1Defense)/100);
					}
					if(oChoice == 2){
						FHardcf2Hp -= 5 * FMediumpf2Attack * ((100 - FHardcf2Defense)/100);
					}
					if(oChoice == 3){
						FHardcf3Hp -= 5 * FMediumpf2Attack * ((100 - FHardcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FHardcf1Hp -= 5 * FMediumpf3Attack * ((100 - FHardcf1Defense)/100);
					}
					if(oChoice == 2){
						FHardcf2Hp -= 5 * FMediumpf3Attack * ((100 - FHardcf2Defense)/100);
					}
					if(oChoice == 3){
						FHardcf3Hp -= 5 * FMediumpf3Attack * ((100 - FHardcf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FMediumpf3Hp += (rand()%10)+5;
				}
			}
			
			fChoice = (rand()%3)+1;
			wtdo = (rand()%2)+1;
			oChoice = (rand()%3)+1;
			
			if(fChoice == 1){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 5 * FHardcf1Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 5 * FHardcf1Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 5 * FHardcf1Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FHardcf1Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 2){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 5 * FHardcf2Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 5 * FHardcf2Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 5 * FHardcf2Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FHardcf2Hp += (rand()%10)+5;
				}
			}
			if(fChoice == 3){
				if(wtdo == 1){
					if(oChoice == 1){
						FMediumpf1Hp -= 5 * FHardcf3Attack * ((100 - FMediumpf1Defense)/100);
					}
					if(oChoice == 2){
						FMediumpf2Hp -= 5 * FHardcf3Attack * ((100 - FMediumpf2Defense)/100);
					}
					if(oChoice == 3){
						FMediumpf3Hp -= 5 * FHardcf3Attack * ((100 - FMediumpf3Defense)/100);
					}
				}
				if(wtdo == 2){
					FHardcf3Hp += (rand()%10)+5;
				}
			}
			
			printf("                The current teams are :\n\n");
			printf(" The Team N° 1 : (Your Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SMediumpf1Name);
			printf(" Hp : %f\n", FMediumpf1Hp);
			printf(" HpMax : %f\n", FMediumpf1HpMax);
			printf(" Attack : %f\n", FMediumpf1Attack);
			printf(" Defense : %f\n", FMediumpf1Defense);
			printf(" Agility : %f\n", FMediumpf1Agility);
			printf(" Speed : %f\n", FMediumpf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SMediumpf2Name);
			printf(" Hp : %f\n", FMediumpf2Hp);
			printf(" HpMax : %f\n", FMediumpf2HpMax);
			printf(" Attack : %f\n", FMediumpf2Attack);
			printf(" Defense : %f\n", FMediumpf2Defense);
			printf(" Agility : %f\n", FMediumpf2Agility);
			printf(" Speed : %f\n", FMediumpf2Speed);
			printf("\n\n");
		
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SMediumpf3Name);
			printf(" Hp : %f\n", FMediumpf3Hp);
			printf(" HpMax : %f\n", FMediumpf3HpMax);
			printf(" Attack : %f\n", FMediumpf3Attack);
			printf(" Defense : %f\n", FMediumpf3Defense);
			printf(" Agility : %f\n", FMediumpf3Agility);
			printf(" Speed : %f\n", FMediumpf3Speed);
			printf("\n\n");
		
		
		
			printf(" The Team N° 2 : (Your Opponent's Team !)\n\n");
			printf(" Fighter N° 1 :\n\n");
			printf(" Name : %s", SHardcf1Name);
			printf(" Hp : %f\n", FHardcf1Hp);
			printf(" HpMax : %f\n", FHardcf1HpMax);
			printf(" Attack : %f\n", FHardcf1Attack);
			printf(" Defense : %f\n", FHardcf1Defense);
			printf(" Agility : %f\n", FHardcf1Agility);
			printf(" Speed : %f\n", FHardcf1Speed);
			printf("\n\n");
			
			printf(" Fighter N° 2 :\n\n");
			printf(" Name : %s", SHardcf2Name);
			printf(" Hp : %f\n", FHardcf2Hp);
			printf(" HpMax : %f\n", FHardcf2HpMax);
			printf(" Attack : %f\n", FHardcf2Attack);
			printf(" Defense : %f\n", FHardcf2Defense);
			printf(" Agility : %f\n", FHardcf2Agility);
			printf(" Speed : %f\n", FHardcf2Speed);
			printf("\n\n");
			
			printf(" Fighter N° 3 :\n\n");
			printf(" Name : %s", SHardcf3Name);
			printf(" Hp : %f\n", FHardcf3Hp);
			printf(" HpMax : %f\n", FHardcf3HpMax);
			printf(" Attack : %f\n", FHardcf3Attack);
			printf(" Defense : %f\n", FHardcf3Defense);
			printf(" Agility : %f\n", FHardcf3Agility);
			printf(" Speed : %f\n", FHardcf3Speed);
			printf("\n\n");
			
			
			if((FMediumpf1Hp <= 0) && (FMediumpf2Hp <= 0) && (FMediumpf3Hp <= 0)){
				printf("You lose !!!");
				exit(1);
			}
			if((FHardcf1Hp <= 0) && (FHardcf2Hp <= 0) && (FHardcf3Hp <= 0)){
				printf("You won !!!");
				exit(1);
			}
		}
		if((FMediumpf1Hp <= 0) && (FMediumpf2Hp <= 0) && (FMediumpf3Hp <= 0)){
			printf("You lose !!!");
			exit(1);
		}
		if((FHardcf1Hp <= 0) && (FHardcf2Hp <= 0) && (FHardcf3Hp <= 0)){
			printf("You won !!!");
			exit(1);
		}
	}
	
	
	return 0;
}
