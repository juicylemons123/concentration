/**
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : <your name>
* Student ID : <your student ID>
* Class/Section : <your class/section>
* Date : <date>
*/


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
void PrintBoard(card *tboard, int tmode, int *tscore)
{
if (tmode!=2 || (tscore[0]+tscore[1]==52) || (Score[0]+Score[1]==0))
{
for (int i=0; i<4; i++)
 {
  for (int j=0; j<13; j++)
   {
    
    if (tboard[(i*13)+j].hidden==1) printf("XXX   ");//three empty spaces between each card
    else 
      {
        if (tboard[(i*13)+j].rank!='0') printf("%c%2c   ", tboard[(i*13)+j].color, tboard[(i*13)+j].rank);
	else printf("%c10   ", tboard[(i*13)+j].color);
      }
   }
  printf("\n");//new row of cards
 }
}
}
////////////////////////////////////////////////////////////////////////////////////////////
void ScoreStatistics(int tmode, int *tscore)
{
 if (tmode==1)
 { printf("Flipped Cards: %d; You: %d; Computer: %d\n", tscore[0]+tscore[1], tscore[0], tscore[1]);}
 else
 { printf("Flipped Cards: %d; Computer 1: %d; Computer 2: %d\n", tscore[0]+tscore[1], tscore[0], tscore[1]);}

}

////////////////////////////////////////////////////////////////////////////////////////////
int ValidateInput(int x, int y, card *tboard, int tx, int ty)
{
 if ((x==tx && y==ty) && (tx!=-100 && ty!=-100)) {printf("Try again, your first and second cards are the same\n"); return 1;}
 if (x==200||y==200) return 1;
 if (x<0||x>3)  {printf("Row must be between 0 and 3\n"); return 1;}
 if (y<1||y>13) {printf("Column must be between 1 and 13\n"); return 1;}
 if (tboard[x*13+y-1].hidden!=1) {printf("Already revealed, choose a different card!\n"); return 1;}
 return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void ReadInput(card *tboard, int *tplayer, int tmode, int *tscore, int *tturns)
{
int x1=200, x2=200, y1=200, y2=200;

while (ValidateInput(x1, y1,tboard,-100,-100))
{
 if (tmode==1 && *tplayer==0) 
 { printf("Please input 1st card: ");scanf("%d%d", &x1, &y1);}
 else 
 {
 while (x1==200||y1==200||x1<0||x1>3||y1<1||y1>13||tboard[x1*13+y1-1].hidden!=1) 
 { x1=rand()%4; y1=rand()%13+1;}
 }
}

if (tboard[x1*13+(y1-1)].rank!='0' && tmode==1 && *tplayer==0)
{ printf("Your 1st card is (%d, %d) and it is %c%2c\n", x1, y1, tboard[x1*13+(y1-1)].color, tboard[x1*13+(y1-1)].rank);}
else if (tboard[x1*13+(y1-1)].rank=='0' && tmode==1 && *tplayer==0)
{ printf("Your 1st card is (%d, %d) and it is %c10\n", x2, y2, tboard[x1*13+(y1-1)].color);}

if (tboard[x1*13+(y1-1)].rank!='0' && tmode==1 && *tplayer==1)
{ printf("Computer chosen 1st card is (%d, %d) and it is %c%2c\n", x1, y1, tboard[x1*13+(y1-1)].color, tboard[x1*13+(y1-1)].rank);}
else if (tboard[x1*13+(y1-1)].rank=='0' && tmode==1 && *tplayer==1)
{ printf("Computer chosen 1st card is (%d, %d) and it is %c10\n", x2, y2, tboard[x1*13+(y1-1)].color);}

if (tboard[x1*13+(y1-1)].rank!='0' && tmode==2)
{ printf("Computer %d chosen 1st card is (%d, %d) and it is %c%2c\n", *tplayer+1,  x1, y1, tboard[x1*13+(y1-1)].color, tboard[x1*13+(y1-1)].rank);}
else if (tboard[x1*13+(y1-1)].rank=='0' && tmode==2)
{ printf("Computer %d  chosen 1st card is (%d, %d) and it is %c10\n", *tplayer+1, x2, y2, tboard[x1*13+(y1-1)].color);}



while (ValidateInput(x2, y2, tboard, x1, y1))
{
 
 if (tmode==1 && *tplayer==0) {printf("Please input 2nd card: "); scanf("%d%d", &x2, &y2); printf("\n");}
 else
 {
 while ((x1==x2 && y1==y2)||x2==200||y2==200||x2<0||x2>3||y2<1||y2>13||tboard[x2*13+y2-1].hidden!=1) {x2=rand()%4; y2=rand()%13+1;}
 }

}

if (tboard[x2*13+(y2-1)].rank!='0' && tmode==1 && *tplayer==0) 
{ printf("Your 2nd card is (%d, %d) and it is %c%2c\n", x2, y2, tboard[x2*13+(y2-1)].color, tboard[x2*13+(y2-1)].rank);}
else if (tboard[x2*13+(y2-1)].rank=='0' && tmode==1 && *tplayer==0) 
{ printf("Your 2nd card is (%d, %d) and it is %c10\n", x2, y2, tboard[x2*13+(y2-1)].color);}

if (tboard[x2*13+(y2-1)].rank!='0' && tmode==1 && *tplayer==1)
{ printf("Computer chosen 2nd card is (%d, %d) and it is %c%2c\n", x2, y2, tboard[x2*13+(y2-1)].color, tboard[x2*13+(y2-1)].rank);}
else if (tboard[x2*13+(y2-1)].rank=='0' && tmode==1 && *tplayer==1)
{ printf("Computer chosen 2nd card is (%d, %d) and it is %c10\n", x2, y2, tboard[x2*13+(y2-1)].color);}

if (tboard[x1*13+(y1-1)].rank!='0' && tmode==2)
{ printf("Computer %d chosen 1st card is (%d, %d) and it is %c%2c\n", *tplayer+1,  x2, y2, tboard[x2*13+(y2-1)].color, tboard[x2*13+(y2-1)].rank);}
else if (tboard[x1*13+(y1-1)].rank=='0' && tmode==2)
{ printf("Computer %d  chosen 1st card is (%d, %d) and it is %c10\n", *tplayer+1, x2, y2, tboard[x2*13+(y2-1)].color);}

*tturns+=2;

if (tboard[x2*13+(y2-1)].rank==tboard[x1*13+(y1-1)].rank) 
{printf("It's a matched pair!\n"); tscore[*tplayer]+=2; tboard[x2*13+(y2-1)].hidden=0; tboard[x1*13+(y1-1)].hidden=0;}

if (*tplayer==0) *tplayer=1;
else {*tplayer=0;}
	
}

////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//printf("work pls");
srand(time(NULL));
int mode;
board=(card *)malloc(520*sizeof(card));
Score=(int *)malloc(2*sizeof(int)); Score[0]=0; Score[1]=0;

GameStart();
 
while (1)
 {
 scanf("%d", &mode);
 if (mode<0 || mode>2) printf("Rejected Value!\n");
 else break;
 }
printf("\n");

//printf("work pls\n");

if (mode==0) {printf("That's all then!\n"); return 0;}

while (1)
{
  PrintBoard(board, mode, Score);
  ReadInput(board, &Player, mode, Score, &Turns);
  ScoreStatistics(mode, Score);
  if (Score[0]+Score[1]==52) {printf("The Game is Over!\n"); break;}
 }

PrintBoard(board, mode, Score);
printf("Turns Played: %d\n", Turns);
if (Score[0]==Score[1]) printf("It's a tie!\n");
if (Score[0]>Score[1] && mode==1) printf("You win!\n");
if (Score[1]>Score[0] && mode==1) printf("Computer Wins!\n");
if (mode==2) printf("Hail sentient AI!\n");

free(board); free(Score);

}
