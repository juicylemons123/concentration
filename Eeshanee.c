#include <stdio.h>

typedef struct tcard{
char rank;
char color;
int  hidden=1;
}card;

card board[52];

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
