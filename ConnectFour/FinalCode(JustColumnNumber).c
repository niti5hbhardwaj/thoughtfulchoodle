#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
char player1_name[25],player2_name[25],player1_symbol,player2_symbol;
char board[6][7];

void gameinit()
{
  char c;
  printf("Player 1, What is your name?\n");
  scanf("%[^\n]%*c",player1_name);
  printf("Player 2, What is your name?\n");
  scanf("%[^\n]%*c",player2_name);
  do
  {
    printf("%s, What symbol do you choose(X or O):",player1_name);
    scanf(" %c",&player1_symbol);
    player1_symbol=toupper(player1_symbol);
    if(player1_symbol!='X'&&player1_symbol!='O')
      printf("Invalid Choice!!. Enter again.\n");
  }while(player1_symbol!='X'&&player1_symbol!='O');
  if(player1_symbol=='X')
    player2_symbol='O';
  else
    player2_symbol='X';
  printf("%s is %c\n%s is %c\n",player1_name,player1_symbol,player2_name,player2_symbol);
  printf("Press ENTER to continue.\n");
  getchar();
}

void reset_board(char a[6][7])
{
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<7;j++)
    {
      a[i][j]='_';
    }
  }
}

int check_empty(int c)
{
  if(board[0][c]=='_')
    return 1;
  else
    return 0;
}

void update_board(int c, int current_player)
{
  int i;
  for(i=0;i<6;i++)
  {
    if(board[i][c]!='_')
      break;
  }
  if(current_player==1)
    board[i-1][c]=player1_symbol;
  else
    board[i-1][c]=player2_symbol;
}


void take_input(char board[6][7], int current_player)
{
  char column[10],name[50];
  int flag=0,i,c,nums[7]={'0','1','2','3','4','5','6'};
  while(!flag)
  {
    printf("%s, Enter the column number: ",current_player==1?player1_name:player2_name);
    scanf("%s",column);
    if(strlen(column)==1)
    {
      for(i=0;i<7;i++)
      {
        if(column[0]==nums[i])
        {
          flag=1;
          break;
        }
      }
    }
    if(flag)
      {
        c=i;
        break;
      }
    printf("Invalid Column.Enter a value between 0 and 6\n");
  }
  if(check_empty(c))
    update_board(c,current_player);
  else
  {
    printf("Selected Column not empty. Choose another one.\n");
    take_input(board,current_player);
  }
}


void print_board(char a[6][7])
{
  system("clear");
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<7;j++)
    {
      printf("|%c",a[i][j]);
    }
    printf("|\n");
  }
  printf(" 0 1 2 3 4 5 6\n");
}

int switch_player(int *current_player)
{
  if(*current_player==1)
    *current_player=2;
  else
    *current_player=1;
  return *current_player;
}

int checkgame(int current_player)
{
  char s,n[50];
  if(current_player==1)
      s=player1_symbol;
  else
      s=player2_symbol;
  for(int i=5;i>=0;i--)
  {
    for(int j=0;j<4;j++)
    {
      if((board[i][j]==s)&&(board[i][j+1])==s&&(board[i][j+2]==s)&&(board[i][j+3]==s))
      {
        return 1;
      }
    }
  }
  for(int j=0;j<7;j++)
  {
    for(int i=5;i>=3;i--)
    {
      if((board[i][j]==s)&&(board[i-1][j])==s&&(board[i-2][j]==s)&&(board[i-3][j]==s))
      {
        return 1;
      }
    }
  }
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<4;j++)
    {
      if((board[i][j]==s)&&(board[i+1][j+1]==s)&&(board[i+2][j+2]==s)&&(board[i+3][j+3]==s))
      {
        return 1;
      }
    }
  }
  for(int i=5;i>=3;--i)
  {
    for(int j=0;j<=3;++j)
    {
      if((board[i][j]==s)&&(board[i-1][j+1]==s)&&(board[i-2][j+2]==s)&&(board[i-3][j+3]==s))
      {
        return 1;
      }
    }
  }
  return 0;
}


int main(void)
{
  gameinit();
  reset_board(board);
  int current_player=1,turns=0;
  while(1)
  {
    print_board(board);
    if(turns==42)
    {
      printf("The game has tied.");
      break;
    }
    take_input(board,current_player);
    turns++;
    if(checkgame(current_player))
    {
      print_board(board);
      printf("\nVictory! %s has won.\n",current_player==1?player1_name:player2_name);
      break;
    }
    switch_player(&current_player);
  }
}
