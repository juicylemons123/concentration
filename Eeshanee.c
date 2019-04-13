#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tcard{
char rank;
char color;
int  hidden=1;
} card;

card *board;
int Score[]={0,0}, Player, Turns=0;// for var Player, 1=Computer and 0=Player in mode 1

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
char rank[13]={'2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'J', 'K', 'Q'}
char color[4]={'C', 'D', 'S', 'H'}

for (int i=0; i<4; i++)
{
 for (int j=0; j<13; j++)
 {
  *tboard[ (i*13)+j ].rank = rank[j];
  *tboard[ (i*13)+j ].color= color[i];
 }
}

//shuffling
for (int i=0, i<(rand()%100 +100); i++)
{
int t1, t2;
t1=rand()%52; t2=rand()%52;
CardSwap(tboard[t1],tboard[t2]);
}
}

////////////////////////////////////////////////////////////////////////////////////////////
void GameStart(int *tmode)
{
board=(card *)(520*sizeof(card));
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
void PrintBoard(card *tboard)
{
card ctemp;
for (int i=0; i<4; i++)
 {
  for (int j=0; j<13; j++)
   {
    ctemp=*tboard[ (i*13)+j ];
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
void ValidateInput(int x, int y, card *tboard)
{
 if (x==200||y==200) return 1;
 if (x<0||x>3)  {printf("Row must be between 0 and 3"); return 1;}
 if (y<1||y>13) {printf("Column must be between 1 and 13"); return 1;}
 if (*tboard[x*13+y-1].hidden!=1) {printf("Already revealed, choose a different card!"); return 1;}
 return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void ReadInput(card *tboard, int *tplayer, int tmode, int *tscore, int *tturns)
{
int x1=200, x2=200, y1=200, y2=200;
card first, second;

while (ValidateInput(x1, y1,tboard))
{
 if (mode==1 && *tplayer==0) scanf("Please input 1st card: %d%d", x1, y1);
 else 
 {
 while (x1==200||y1==200||x1<0||x1>3||y1<1||y1>13||*tboard[x1*13+y1-1].hidden!=1) {x1=rand()%4; y1=rand()%13+1}
 }
}

if (*tboard[x1*13+(y1-1)].rank!='0') printf("Your first card is (%d, %d) and it is %c%2c", x1, y1, *tboard[x1*13+(y1-1)].color, *tboard[x1*13+(y1-1)].rank);
        else printf("Your first card is (%d, %d) and it is %c10", x2, y2, *tboard[x1*13+(y1-1)].color);


while (ValidateInput(x2, y2, tboard))
{
 
 if (mode==1 && *tplayer==0) scanf("Please input 1st card: %d%d", x2, y2);
 else
 {
 while (x2==200||y2==200||x2<0||x2>3||y2<1||y2>13||*tboard[x2*13+y2-1].hidden!=1) {x2=rand()%4; y2=rand()%13+1}
 }

}
if (*tboard[x2*13+(y2-1)].rank!='0') printf("Your second card is (%d, %d) and it is %c%2c", x2, y2, *tboard[x2*13+(y2-1)].color, *tboard[x2*13+(y2-1)].rank);
        else printf("Your second card is (%d, %d) and it is %c10", x2, y2, *tboard[x2*13+(y2-1)].color);
*tturns++;
if (*tboard[x2*13+(y2-1)].rank==*tboard[x1*13+(y1-1)].rank) *tscore[tplayer]++;

if (*tplayer==0) *tplayer=1;
else {*tplayer=0;}
	
}

////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
srand(time(NULL));
int mode;
GameStart(&mode);
if (mode==0) {printf("That's all then!"); return 0;}
while (1)
 {
  PrintBoard();
  ReadInput();
  if (score[0]+score[1]==52) {printf("The Game is Over!"); break;}
 }
 PrintBoard();
 if (score[0]==score[1]) printf("It's a tie!");
 if (score[0]>score[1] && mode==1) printf("You win!");
 if (score[1]>score[0] && mode==1) printf("Computer Wins!");
 if (mode==2) printf("Hail sentient AI!");
}
