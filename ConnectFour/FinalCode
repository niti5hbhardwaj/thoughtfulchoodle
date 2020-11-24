#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
char player1_name[25],player2_name[25],player1_symbol,player2_symbol;
char board[6][7];

//Functions to be used in the program
void gameinit();
void reset_board(char a[6][7]);
int check_empty(int);
void update_board(int,int);
void take_input(char board[6][7],int);
void print_board(char a[6][7]);
int switch_player(int *current_player);
int checkgame(int);

//function to input the name and symbol of the player
void gameinit()
{
  char c;
  printf("Player 1, What is your name?\n");
  scanf("%[^\n]%*c",player1_name);
  printf("Player 2, What is your name?\n");
  scanf("%[^\n]%*c",player2_name);
  //this loop input the symbol and check whether it is either O or X if not it
  //asks for the imput again
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
  fflush(stdin);
  printf("Press ENTER to continue.\n");
  getchar();
}

//this function assigns underscore to the board elements
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

//this function check if the passed column is empty or not
int check_empty(int c)
{
  if(board[0][c]=='_')
    return 1;
  else
    return 0;
}

//this function updates the board with the symbol of the player in the selected column
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

//this function takes the input of the player symbol and the column number
void take_input(char board[6][7], int current_player)
{
  char column[10],name[50],symbol,current_symbol;
  current_symbol=(current_player==1?player1_symbol:player2_symbol);
  int flag=0,i,c,nums[7]={'0','1','2','3','4','5','6'};
  //this loop keeps taking input till a valid symbol and column number is entered
  while(!flag)
  {
    fflush(stdin);
    printf("%s, Enter the symbol and slot number: ",current_player==1?player1_name:player2_name);
    scanf("%c %s",&symbol,&column);
    if(toupper(symbol)!=current_symbol)
      printf("ERROR: invalid player code : %c\n",symbol);
    else
    {
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
      printf("ERROR: invalid slot number : %s\n",column);
    }
  }
  //checks if the selected column is empty or not if it is then updates the board
  //if the column is not empty then it calls the take_input function(itself)
  if(check_empty(c))
    update_board(c,current_player);
  else
  {
    printf("ERROR: invalid slot number : %d\n",c);
    take_input(board,current_player);
  }
}

//this function clears the console screen and prints the board
void print_board(char a[6][7])
{
  system("cls");
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

//this function switches turns between the two players
int switch_player(int *current_player)
{
  if(*current_player==1)
    *current_player=2;
  else
    *current_player=1;
  return *current_player;
}

//this function checks if the player has met any of the winning conditions or not
int checkgame(int current_player)
{
  char s,n[50];
  if(current_player==1)
    s=player1_symbol;
  else
    s=player2_symbol;
  //this loop checks for the horizontal winning condition
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
  //this loop checks for the vertical winning condition
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
  //this loop checks for the winning condition in the left diagonals
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
  //this loop checks for the winning conditions in the right diagonals
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
    //this condition checks if the board is filled or not
    if(turns==42)
    {
      printf("Draw! No player has won!\n");
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
