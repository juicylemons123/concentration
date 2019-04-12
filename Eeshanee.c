#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tcard{
char rank;
char color;
int  hidden=1;
} card;

card *board;
////////////////////////////////////////////////////////////////////////////////////////////
void CardSwap (card* x, card*y)
{
 card temp;
 temp.rank=*x.rank; temp.color=*x.color;
 *x.rank=*y.rank; *x.color=*y.color;
 *y.rank=temp.rank; *y.color=temp.color;
}

////////////////////////////////////////////////////////////////////////////////////////////
void GameInit(card *tboard)
{
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

//shuffling
for (int i=0, i<(rand()%100); i++)
{
int t1, t2;
t1=rand()%52; t2=rand()%52;
CardSwap(&tboard[t1],&tboard[t2]);
}
}

////////////////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////////////////
void PrintBoard(card board[])
{
card ctemp;
for (int i=0; i<=4; i++)
 {
  for (int j=1; j<=13; j++)
   {
    ctemp=board[ (i*13)+(j-1) ];
    if (ctemp.hidden==1) printf("XXX   ");//three empty spaces between each card
    else 
      {
        if (ctemp.rank!='0') printf("%c%2c   ", ctemp.color, ctemp.rank);
	else printf("%c10   ", ctemp.color);
      }
   }
  printf("\n");//new row of cards
 }
}

////////////////////////////////////////////////////////////////////////////////////////////
void ValidateInput(int x, int y, card tboard)
{
 if (x==200||y==200) return 1;
 if (x<0||x>3)  {printf("Row must be between 0 and 3"); return 1;}
 if (y<1||y>13) {printf("Column must be between 1 and 13"); return 1;}
 if 
 return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void ReadInputFromHuman(card tboard)
{
int x1=200, x2=200, y1=200, y2=200;
card first, second;

while (ValidateInput(x1, y1))
{
 scanf("Please input 1st card: %d%d", x1, y1);
}

if (tboard[x1*13+(y1-1)].rank!='0') printf("Your first card is (%d, %d) and it is %c%2c", x1, y1, tboard[x1*13+(y1-1)].color, tboard[x1*13+(y1-1)].rank);
        else printf("Your first card is (%d, %d) and it is %c10", x2, y2, tboard[x1*13+(y1-1)].color);


while (ValidateInput(x2, y2))
{
 scanf("Please input 1st card: %d%d", x2, y2);
}
if (tboard[x2*13+(y2-1)].rank!='0') printf("Your second card is (%d, %d) and it is %c%2c", x2, y2, tboard[x2*13+(y2-1)].color, tboard[x2*13+(y2-1)].rank);
        else printf("Your second card is (%d, %d) and it is %c10", x2, y2, tboard[x2*13+(y2-1)].color);


	
}

////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
srand(time(NULL));
int mode;
GameStart(&mode);
if (mode==0) {printf("That's all then!"); return 0;}
if (mode==1)
{

}
}
