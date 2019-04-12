#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tcard{
char rank;
char color;
int  hidden=1;
}card;

card *board;

void CardSwap (card* x, card*y)
{
 card temp;
 temp.rank=*x.rank; temp.color=*x.color;
 *x.rank=*y.rank; *x.color=*y.color;
 *y.rank=temp.rank; *y.color=temp.color;
}

void GameInit(card *tboard)
{
srand(time(NULL));
char rank[13]=['2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'J', 'K', 'Q']
char color[4]=['C', 'D', 'S', 'H']

for (int i=0; i<4; i++)
{
 for (int j=0; j<13; j++)
 {
  *tboard[ (i*13)+j ].rank = rank[j];
  *tboard[ (i*13)+j ].color= color[i];
 }
}

for (int i=0, i


}

void GameStart(int *tmode)
{
board=(card *)(52*sizeof(card));
printf("**************************\n");
printf("*Welcome to Concentration*\n");
printf("**************************\n");
printf("Please choose a mode of the game:\n1. Human vs. Computer\n2. Computer vs. Computer\n0. Quit")
 while (*tmode!=0 || *tmode!=1 || *tmode!=2)
 {
 scanf("Your choice: %d\n", tmode);
 if (*tmode!=0 || *tmode!=1 || *tmode!=2) printf("Rejected, Enter a valid number!\n")
 }
GameInit(board);
}

void PrintBoard(card board[])
{
card temp;
for (int i=0; i<=4; i++)
 {
  for (int j=1; j<=13; j++)
   {
    temp=board[ (i*13)+(j-1) ];
    if (temp.hidden==1) printf("XXX   ");//three empty spaces between each card
    else printf("%c%2c   ", temp.color, temp.rank)
   }
  printf("\n");//new row of cards
 }
}




int main()
