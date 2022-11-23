#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "rlutil.h"

int main(){
	srand(time(NULL));
	int bot1,bot2,bot1aux,bot2aux;
	char letter;

	bot1 = 10 + rand()%(10-20+1);
	bot2 = 10 + rand()%(10-20+1);

	printf("*********************\n");
	printf("       WAR GAMES     \n");
	printf("   by maese xgarcia  \n");
	printf("*********************\n");

	do		//! Input de usuario
	{
		if (letter == 'n' || letter == 'N'){
			printf("Good Bye My Friend!\n");
			break;  
		}
		printf("Vols iniciar la simualcio? (y/n) ");
		scanf("%c",&letter);
		while(getchar()!='\n');
	} while (letter != 'Y' && letter != 'y');
	
	if (letter == 'Y' || letter == 'y')
	{
		printf("Bot 1: localizacion %d\n",bot1);
		printf("Bot 2: localizacion %d\n",bot2);
		for (int i = 1; i < 6; i++)
		{
			setColor(GREEN);													//? Color Bot 1
			printf("[ROUND %d] El bot 1 ataca en la posicion x%d\n",i,bot1);	//! Ronda del Bot 1
			if (bot1 == bot2)
			{
				printf("[ROUND %d] Bot 1 ha destruido a Bot 2\n",i);
				bot1 = 1;
				break;
			}else{
				printf("[ROUND %d] Bot 1 ha fallado\n",i);
				bot1aux = bot1;
				bot1 = 10 + rand()%(10-20+1);
				while (bot1aux == bot1)
				{
					bot1 = 10 + rand()%(10-20+1);
				}
			}
			
			setColor(RED);														//? Color Bot 2
			printf("[ROUND %d] El bot 2 ataca en la posicion x%d\n",i,bot2);	//! Ronda Bot 2
			if (bot1 == bot2)
			{
				printf("[ROUND %d] Bot 2 ha destruido a Bot 1\n",i);
				bot2 = 2;
				break;
			}else{
				printf("[ROUND %d] Bot 2 ha fallado\n",i);
				bot2aux = bot2;
				bot2 = 10 + rand()%(10-20+1);
				while (bot2aux == bot2)
				{
					bot2 = 10 + rand()%(10-20+1);
				}
			}
		}
		setColor(WHITE);
		if (bot1 == 1)			//? Resultados 
		{
			printf("Bot 1 ha gando!\n");
		}else if(bot2 == 2)
		{
			printf("Bot 2 ha gando!\n");
		}else{
			printf("The only winning move is not to play\n");
		}
		printf("Good Bye My Friend!\n");
	}
	getch();
	return 0;
}


