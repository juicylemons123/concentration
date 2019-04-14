#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tcard{
char rank;
char color;
int  hidden;
} card;

card *board;
int *Score, Player=0, Turns=0;// for var Player, 1=Computer and 0=Player in mode 1

////////////////////////////////////////////////////////////////////////////////////////////
void CardSwap (card* x, card*y)
{
 card temp;
 temp.rank=x->rank; temp.color=x->color; temp.hidden=x->hidden;
 x->rank=y->rank; x->color=y->color; x->hidden=y->hidden;
 y->rank=temp.rank; y->color=temp.color; y->hidden=temp.hidden;
}

////////////////////////////////////////////////////////////////////////////////////////////
void GameInit(card *tboard)
{
char rank[13]={'2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'J', 'K', 'Q'};
char color[4]={'C', 'D', 'S', 'H'};

for (int i=0; i<4; i++)
{
 for (int j=0; j<13; j++)
 {
  tboard[ (i*13)+j ].rank = rank[j];
  tboard[ (i*13)+j ].color= color[i];
  tboard[ (i*13)+j ].hidden=1;
 }
}

//shuffling
for (int i=0; i<(300); i++)
{
int t1, t2;
t1=rand()%52; t2=rand()%52;
CardSwap(&tboard[t1],&tboard[t2]);
}
}

////////////////////////////////////////////////////////////////////////////////////////////
void GameStart()
{
printf("**************************\n");
printf("*Welcome to Concentration*\n");
printf("**************************\n");
printf("Please choose a mode of the game:\n1. Human vs. Computer\n2. Computer vs. Computer\n0. Quit\n");
printf("Your choice: ");
GameInit(board);
}

////////////////////////////////////////////////////////////////////////////////////////////
void PrintBoard(card *tboard)
{
for (int i=0; i<4; i++)
 {
  for (int j=0; j<13; j++)
   {
    
    if (tboard->hidden==1) printf("XXX   ");//three empty spaces between each card
    else 
      {
        if (tboard->rank!='0') printf("%c%2c   ", tboard->color, tboard->rank);
	else printf("%c10   ", tboard->color);
      }
   }
  printf("\n");//new row of cards
 }
}

////////////////////////////////////////////////////////////////////////////////////////////
int ValidateInput(int x, int y, card *tboard)
{
 if (x==200||y==200) return 1;
 if (x<0||x>3)  {printf("Row must be between 0 and 3"); return 1;}
 if (y<1||y>13) {printf("Column must be between 1 and 13"); return 1;}
 if (tboard[x*13+y-1].hidden!=1) {printf("Already revealed, choose a different card!"); return 1;}
 return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void ReadInput(card *tboard, int *tplayer, int tmode, int *tscore, int *tturns)
{
int x1=200, x2=200, y1=200, y2=200;
card first, second;

while (ValidateInput(x1, y1,tboard))
{
 if (tmode==1 && *tplayer==0) scanf("Please input 1st card: %d%d", &x1, &y1);
 else 
 {
 while (x1==200||y1==200||x1<0||x1>3||y1<1||y1>13||tboard[x1*13+y1-1].hidden!=1) {x1=rand()%4; y1=rand()%13+1;}
 }
}

if (tboard[x1*13+(y1-1)].rank!='0') printf("Your first card is (%d, %d) and it is %c%2c", x1, y1, tboard[x1*13+(y1-1)].color, tboard[x1*13+(y1-1)].rank);
        else printf("Your first card is (%d, %d) and it is %c10", x2, y2, tboard[x1*13+(y1-1)].color);


while (ValidateInput(x2, y2, tboard))
{
 
 if (tmode==1 && *tplayer==0) scanf("Please input 1st card: %d%d", &x2, &y2);
 else
 {
 while (x2==200||y2==200||x2<0||x2>3||y2<1||y2>13||tboard[x2*13+y2-1].hidden!=1) {x2=rand()%4; y2=rand()%13+1;}
 }

}
if (tboard[x2*13+(y2-1)].rank!='0') printf("Your second card is (%d, %d) and it is %c%2c", x2, y2, tboard[x2*13+(y2-1)].color, tboard[x2*13+(y2-1)].rank);
        else printf("Your second card is (%d, %d) and it is %c10", x2, y2, tboard[x2*13+(y2-1)].color);
*tturns++;
if (tboard[x2*13+(y2-1)].rank==tboard[x1*13+(y1-1)].rank) tscore[*tplayer]++;

tboard[x1*13+(y1-1)].hidden=0; tboard[x2*13+(y2-1)].hidden=0;

if (*tplayer==0) *tplayer=1;
else {*tplayer=0;}
	
}

////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
printf("work pls");
srand(time(NULL));
int mode;
board=(card *)malloc(520*sizeof(card));
Score=(int *)malloc(2*sizeof(int)); Score[0]=0; Score[1]=0;
GameStart();
 while (1)
 {
 scanf("%d", &mode);
 printf("%d", mode);
 if (mode<0 || mode>2) printf("Rejected Value!\n");
 else break;
 }

//printf("work pls\n");
if (mode==0) {printf("That's all then!\n"); return 0;}
while (1)
 {
  PrintBoard(board);
  ReadInput(board, &Player, mode, Score, &Turns);
  if (Score[0]+Score[1]==52) {printf("The Game is Over!\n"); break;}
 }
 PrintBoard(board);
 if (Score[0]==Score[1]) printf("It's a tie!\n");
 if (Score[0]>Score[1] && mode==1) printf("You win!\n");
 if (Score[1]>Score[0] && mode==1) printf("Computer Wins!\n");
 if (mode==2) printf("Hail sentient AI!\n");
 free(board); free(Score);

}
