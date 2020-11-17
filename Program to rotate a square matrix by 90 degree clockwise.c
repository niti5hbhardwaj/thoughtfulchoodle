#include<stdio.h>
int main(void)
{
  int n=3;
  int arr[n][n]={{1,2,3},{4,5,6},{7,8,9}},temp;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<n/2;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      temp=arr[i][j];
      arr[i][j]=arr[n-1-j][i];
      arr[n-1-j][i]=arr[n-1-i][n-1-j];
      arr[n-1-i][n-1-j]=arr[j][n-1-i]; 
      arr[j][n-1-i]=temp;
    }
  }
  printf("\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}
