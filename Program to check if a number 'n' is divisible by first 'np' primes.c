#include<stdio.h>
int main(void)
{
  int n,np,c=0;
  printf("Enter the number: ");
  scanf("%d",&n);
  printf("Enter the number of primes: ");
  scanf("%d",&np);
  for(int i=2;c<np&&i<n;i++)
  { int p=1;
    for(int j=2;j<i;j++)
    {
      if(i%j==0)
      {
        p=0;
        break;
      }
    }
    if(p!=0)
    {
      if(n%i==0)
        c++;
    }
  }
  if(c==np)
    printf("True");
  else
    printf("False");
}
