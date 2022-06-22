#include<stdio.h>

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

    printf("(%d, %d, %d) ", winA, winB, winC);
    printf(" || %d, %d, %d || ", gameTable[winA], gameTable[winB], gameTable[winC]);
    if (gameTable[winA] == gameTable[winB] && gameTable[winB] == gameTable[winC]) {
      if (gameTable[winA] == 0) {
        printf("\n\nasdf\n\n");
        return 0;
      } else if(gameTable[winA] == 1) {
        printf("\n\nasdf2\n\n");
        return 1;
      }
    }
  }
}

int main(void) {
  int i;
  int gameTable[] = { 9, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  char gameTableChar[] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
  for (i=0; i<9; i++) {
    // 0 MEANS PLAYER; 1 MEANS CPU; 2 MEANS UNOCCUPIED

    int gameTurn = 0;
    int playerSelection;
    
    printf("--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n||		||		||		||\n||	%c	||	%c	||	%c	||\n||		||		||		||\n--------------------------\n", gameTableChar[0], gameTableChar[1], gameTableChar[2], gameTableChar[3], gameTableChar[4], gameTableChar[5], gameTableChar[6], gameTableChar[7], gameTableChar[8]);
  
    printf("\n getselection \n");
    scanf("%d", &playerSelection);
  
    gameTable[playerSelection] = 1;
    gameTableChar[playerSelection-1] = 'X';  
    
    if (checkWin(gameTable) == 0) {
      printf("\nPLAYER WIN!\n");
    } else if (checkWin(gameTable) == 1) {
      printf("\nCPU WIN!\n");
    } else {
      printf("\nINVALID\n");
    }
  }
}