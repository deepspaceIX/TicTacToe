#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int WINARRAYSIZE = 24;
int WINCONDITIONS[] = {
  1, 2, 3,
  4, 5, 6,
  7, 8, 9,
  1, 4, 7,
  2, 5, 8,
  3, 6, 9,
  1, 5, 9,
  3, 5, 7
};

int checkWin(int gameTable[]) {
  int i;
  
  for (i = 0; i <= WINARRAYSIZE-1; i+=3) {
    int winA = WINCONDITIONS[i];
    int winB = WINCONDITIONS[i+1];
    int winC = WINCONDITIONS[i+2];

    wait(50);
    if (gameTable[winA] == gameTable[winB] && gameTable[winB] == gameTable[winC]) {
      if (gameTable[winA] == 0) {
        printf("\n");
        return 0;
      } else if(gameTable[winA] == 1) {
        printf("\n");
        return 1;
      }
    }
  }
}

int main(void) {
  int i;
  int gameTable[] = { 9, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  char gameTableChar[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
  int gameTurn = 0;
  int putOccupiedSquare = 0;
  for (i=0; i>-1; i++) {
    // 0 MEANS PLAYER1; 1 MEANS PLAYER2; 2 MEANS UNOCCUPIED
    system("clear");
    if (putOccupiedSquare == 1) {
      putOccupiedSquare = 0;
      printf("YOU PUT A MARKER IN A SQUARE ALREAY OCCUPIED\nPLEASE GO AGAIN\n");
    }
    
    int playerSelection;
    
    printf("--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n", gameTableChar[0], gameTableChar[1], gameTableChar[2], gameTableChar[3], gameTableChar[4], gameTableChar[5], gameTableChar[6], gameTableChar[7], gameTableChar[8]);

    if (checkWin(gameTable) == 0) {
      printf("\nPLAYER 1 WIN!\n");
      exit(0);
    } else if (checkWin(gameTable) == 1) {
      printf("\nPLAYER 2 WIN!\n");
      exit(0);
    } else {
      printf("\n");
    }

    if (gameTurn == 0) {
      printf("\n PLAYER 1 SELECT A SQUARE TO PUT YOUR MARKER! \n");
      scanf("%d", &playerSelection);

      if (gameTable[playerSelection] != 2) {
        putOccupiedSquare = 1;
      } else {
        gameTable[playerSelection] = 0;
        gameTableChar[playerSelection-1] = 'O';  
        gameTurn = 1;
      }
      
    } else if(gameTurn == 1) {
      printf("\n PLAYER 2 SELECT A SQUARE TO PUT YOUR MARKER! \n");
      scanf("%d", &playerSelection);
    
      if (gameTable[playerSelection] != 2) {
        putOccupiedSquare = 1;
      } else {
        gameTable[playerSelection] = 1;
        gameTableChar[playerSelection-1] = 'X';  
        gameTurn = 0;
      }
    }
  }
}