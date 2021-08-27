#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

struct pokemon{
	char pokeName[100];	
};

void pokePlay(){
	
	struct pokemon pokedox[100];
	
	char word[100]; int i = -1;
	
	FILE *file;
	
	if((file = fopen("pokemon.txt","r+")) == NULL){
		printf("[File not found!]\n");
		return;
	}
	
	printf("Guess the Character");
	
	while(fscanf(file, "%s",word) != EOF){
		i++;
		strcpy(pokedox[i].pokeName,word);
	}
	
	fclose(file);

	int random_idx;
	
	srand(time(NULL));
	random_idx = (rand() % (i - 0 + 1)) + 0;
	
	char tempWord[100];
	strcpy(tempWord,pokedox[random_idx].pokeName);
	char string[100];
	
	for(int j = 0; j < strlen(tempWord); j++){
		string[j] = '_';
	}
	
	int finish = 0, tries = 10, error, check;
	char entry;
	
	do{
		error = 1;
		check = 0;
		
		printf("\n\n");
		
		for(int j = 0; j < strlen(tempWord); j++){
			printf("%c ",string[j]);
		}
		
		
		printf("\nEnter a character : ");
		entry = getche();
		
		for(int j = 0; j < strlen(tempWord); j++){
		
			char letter = tempWord[j];
			
			if(entry == letter){
		
				error = 0;
			
				for(int k = 0; k < strlen(string); k++){
					if(entry == string[k]){
		
						check = 1;
						break;
					}
				}
				
				if(check == 0){
					for(int k = 0; k < strlen(string); k++){
						if(entry == tempWord[k]){
		
							error = 0;
							string[k] =  entry;
							finish++;
						}
					}

					break;
				}
			}
		}
		
		printf("\n\n");
		
		if(error == 1){
			tries--;
			printf("==============================================================================\n");
			printf("|| That letter is not part of the mystery word. You have %d tries remaining ||\n",tries);
			printf("==============================================================================\n");
		}
		
		if(finish == strlen(tempWord)){
			printf("CONGRATULATIONS YOU WIN [%s]!\n",string);
		}
		else if(tries == 0){
			printf("=====================================\n");
			printf("  GAME OVER!!! YOU RAN OUT OF TRIES  \n");
			printf("=====================================\n");
			printf("         THE WORD IS [%s]\n",tempWord);
			printf("=====================================\n");
		}
	}
	while(finish != strlen(tempWord) && tries != 0);
}

void playerMenu(){
	
	int choose = 0;
	
	while(true){
		printf("\n");
		printf("============================================\n");
		printf("||              Welcome Player            ||\n");
		printf("||========================================||\n");
		printf("|| 1. Play                                ||\n");
		printf("|| 2. Back                                ||\n");
		printf("||========================================||\n");
		printf("   Choose : ");
		
		scanf("%d",&choose);
		printf("\n");
		
		if(choose == 1){ 
			pokePlay();
		}
		else if(choose == 2){
			printf("[Good Bye!]\n");
			break;
		}
		else{
			printf("[Not available!]\n");
		}
	}
}

void pokeAdd(){
	
	char name[100];
	FILE *file;
	
	if((file = fopen("pokemon.txt","w")) == NULL){
		printf("File not found\n");
		return;
	}
	
	printf("Enter new word : ");
	scanf("%s",&name);
	getchar();
	fprintf(file,"\n%s",name);
	
	fclose(file);
	
}

void pokeDisplay(){
	
	char fname[100],word;
	
	FILE *file;
	
	if((file = fopen("pokemon.txt","r+")) == NULL){
		printf("[File not found!]\n");
		return;
	}
	else{
		printf("File Content is :\n");
		word = fgetc(file);
		
		while(word != EOF){
			printf("%c", word);
			word = fgetc(file);
		}
		
	}
	
	fclose(file);
}

void adminMenu(){
	
	int choose = 0;
	
	while(true){
		printf("\n");
		printf("============================================\n");
		printf("||              Welcome Admin             ||\n");
		printf("||========================================||\n");
		printf("|| 1. Add new pokemon                     ||\n");
		printf("|| 2. Display pokemon                     ||\n");
		printf("|| 3. Back                                ||\n");
		printf("||========================================||\n");
		printf("   Choose : ");
		
		scanf("%d",&choose);
		printf("\n");
		printf("============================================\n");
		
		if(choose == 1){ 
			pokeAdd();
		}
		else if(choose == 2){
			pokeDisplay();
			printf("\n");
			printf("============================================\n");
		}
		else if(choose == 3){
			printf("[Good Bye!]\n");
			break;
		}
		else{
			printf("[Not available!, go create more!]\n");
		}
	}
}

int main(){
	
	int choose = 0;
	
	while(true){
		
		printf("\n");
		
		printf("============================================\n");
		printf("||         Welcome to TEBAK KARAKTER      ||\n");
		printf("||========================================||\n");
		printf("|| 1. Player                              ||\n");
		printf("|| 2. Admin                               ||\n");
		printf("|| 3. Exit                                ||\n");
		printf("||========================================||\n");
		printf("   Choose : ");
		
		scanf("%d",&choose);
		printf("\n");
		
		if(choose == 1){ 
			playerMenu();
		}
		else if(choose == 2){ 
			adminMenu();
		}
		else if(choose == 3){
			printf("[Good Bye!]\n");
			break;
		}
		else{
			printf("[Not Available!]\n");
		}
	}
	
	return 0;
}
