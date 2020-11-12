#include<stdio.h>
int main(void)
{
  int n;
  printf("Enter the length of one arm: ");
  scanf("%d",&n);
  for(int i=1;i<=2*n-1;i++)
  {
    for(int j=1;j<=2*n-1;j++)
    {
      if(i<n)
      {
        if(j==1)
          printf("*\t");
        else if(j==n)
          printf("*\t");
        else if(j>n&&i==1)
          printf("*\t");          
        else
          printf("\t");
      }
      if(i==n)
      {
        printf("*\t");
      }
      if(i>n)
      {
        if(j==2*n-1)
          printf("*");
        else if(j==n)
          printf("*\t");
        else if(j<n&&i==2*n-1)
          printf("*\t");
        else
          printf("\t");
      }
    }
    printf("\n");
  }
}
