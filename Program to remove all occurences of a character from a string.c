#include<stdio.h>
#include<string.h>
int main(void)
{
  char str[50],c;
  int i=0;
  printf("Enter a string: ");
  scanf("%[^\n]%*c",str);
  printf("Enter the character you want to remove: ");
  scanf("%c",&c);
  while(str[i]!='\0')
  {
    if(str[i]==c)
    {
      for(int j=i;j<strlen(str);j++)
      {
        if(j<strlen(str)-1)
          str[j]=str[j+1];
        else
          str[j]='\0';
      }
    }
    else
      i++;
  }
  printf("The updated string is: %s",str);
}
