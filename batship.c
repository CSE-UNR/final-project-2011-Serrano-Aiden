//Aiden Serrano 
//Final Project
//07/26/24

#include <stdio.h>
#include <stdbool.h>
#define FILE_NAME "easy.txt"
#define DIM 10

void loadboard(FILE* fp, char board[DIM][DIM]);
void displayboard(char board[DIM][DIM]);
void initboard(char board[][DIM]);
int rowtoIndex(int row);
int coltoIndex(char col);
bool isHit(char board[DIM][DIM], int row, int col);

int main (){

	char gameboard[DIM][DIM], ships[DIM][DIM], display;
	int row, count = 0, countX = 0;
	char col;
	_Bool gameOver = false;
	
	FILE* fp = fopen(FILE_NAME, "r");
	if(fp == NULL){
		printf("Can not open file");
		return 0;
	}
	
	printf("\n*****LET'S PLAY BATTLESHIP*****\n\n");
	
	
	initboard(gameboard);
	loadboard(fp, ships);
	displayboard(gameboard);
	
	while(gameOver != true){
		
		printf("        FIRE AWAY!\n");
		printf("(enter a spot in the grid like A1) ");
		scanf(" %c%d", &col, &row);
		count++;
		if(col < 'A' || col > 'J' || row < 1 || row >10){
			printf("\nInvalid row number. Try again!\n");
		} 
		else{
		row = rowtoIndex(row);
		col = coltoIndex(col);
		
		if(isHit(ships, row, col)){
			gameboard[row][col] = 'X';
			countX++;
			
		}
		else{
			gameboard[row][col] = 'O';
		}

		
		displayboard(gameboard);
		}
		
		if(countX == 31){
			gameOver == true;
		}
		
		
	
		
	}
		int score = 100 - count;
		printf("Congratulations it took you %d amount of times.\n", count);
		printf ("Your score is %d.\n", score);
	fclose(fp);
	
	
	
	return 0;
}

void loadboard(FILE* fp, char ships[DIM][DIM]){
		
	for(int rowIndex = 0; rowIndex < DIM; rowIndex++){
		for(int colIndex = 0; colIndex < DIM; colIndex++){
            		fscanf(fp, "%c", &ships[rowIndex][colIndex]);
            		}
            	}
            
           

            
             
         
        
}
           

void displayboard(char board[DIM][DIM]){
	
	printf("   ");
	for(char letters = 'A'; letters <= 'J'; letters++){
		printf("%c ", letters);
		
	}
	printf("\n");
	for(int i = 0; i < DIM; i++){
		
		printf("%d ", i +1);
		if(i + 1 != 10){
			printf(" ");
		}
		for(int j = 0; j < DIM; j++){
			printf("%c ", board[i][j]);
			}
		
		printf("\n");
	}
}



void initboard(char board[][DIM]){
	for(int rowIndex = 0; rowIndex < DIM; rowIndex++){
		for(int colIndex = 0; colIndex < DIM; colIndex++){
			board[rowIndex][colIndex] = ' ';
			}
		}
	}
	
int rowtoIndex(int row){
	return row - 1;
}

int coltoIndex(char col){
	return col - 'A';

}

bool isHit(char board[DIM][DIM], int row, int col){
	return board[row][col] == 'S';
}







