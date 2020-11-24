#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Global Variable
int day_one_of_month;

//Functions to be used
int is_leap_year(int);
int days_in_month(int,int);
int first_day_of_month(int,int);
char* month_name(int);
void print_calendar(int,int);
char* day_name(int);
void day_of_the_week(int,int,int);
int check_validity(int,int,int);

//this function checks if the year is leap year or not
int is_leap_year(int y)
{
  if(y%4==0)
  {
    if(y%100==0)
    {
      if(y%400==0)
        return 1;
      else
        return 0;
    }
    else
      return 1;
  }
  return 0;
}

//this function return the number of days in the month
int days_in_month(int y,int m)
{
  int month_days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  //checks if the year is leap year or not if it is not a leap year then returns
  //the value from the array if it is a leap year then it return 29 for m=2
  if(is_leap_year(y)==0)
    return month_days[m];
  else
    {
      if(m==2)
        return 29;
      else
        return month_days[m];
    }
}

//this function finds the first day of the given month
int first_day_of_month(int y,int m)
{
  int day=0;
  for(int i=1589;i<=y;i++)
  {
    //checks the value of i against the entered year. if i is not equal to year
    //adds the days of all months of the year i
    if(i!=y)
      {
        for(int j=1;j<13;j++)
        {
          day+=days_in_month(i,j);
        }
      }
    //if i=y then adds the days of months before the entered month
    else
      {
        for(int j=1;j<m;j++)
        {
          day+=days_in_month(i,j);
        }
      }
  }
  day%=7;
  return day;

}

//This function takes the month number and returns the month name
char* month_name(int m)
{
  char *name[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};
  return name[m];
}

//this function prints the calendar the given month and year
void print_calendar(int year,int month)
{
  int n=strlen(month_name(month))+5;
  //prints the '=' sign before the month name in the calendar header
  for(int i=0;i<(20-n)/2;i++)
    printf("=");
  //prints the month name and the year in the calendar header
  printf("%s %d",month_name(month),year);
  //prints the '=' sign after the year in the calendar header
  for(int i=0;i<(20-n)/2;i++)
    printf("=");
  printf("\nSu Mo Tu We Th Fr Sa\n");
  //this t variable is for printing a newline after every 7 days
  int t=1;
  for(int i=1;i<=days_in_month(year,month);i++)
  {
    if(i==1)
    {
      //for printing spaces before the first date of the month
      for(int j=0;j<day_one_of_month;j++)
      {
        printf("   ");
        t++;
      }
    }
    printf("%-3d",i);
    t++;
    if(t==8)
    {
      printf("\n");
      t=1;
    }
  }
}

//This function takes the day number, and return the day name
char* day_name(int day)
{
  char* name[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  return name[day];
}

//this function finds the day on the entered date
void day_of_the_week(int y,int m,int d)
{
  day_one_of_month = first_day_of_month(y,m);
  int day=day_one_of_month;
  //this loop adds the days to the day_one_of_month to get the day on the given date
  for(int i=1;i<d;i++)
  {
    day+=1;
  }
  day%=7;
  printf("\nThe day on %d/%d/%d is %s\n\n",d,m,y,day_name(day));
  print_calendar(y,m);
}

/*This function checks the validity of the given date,month,year*/
int check_validity(int d,int m,int y)
{
  //checks if the month,day and year are in the given range
  if((m>=1&&m<=12)&&(d>0&&d<32&&y>1589))
  {
    if(m==2&&is_leap_year(y))
    {
      if(d<=29)
        return 1;
      else
        return 0;
    }
    else if(m==2)
    {
      if(d<=28)
        return 1;
      else
        return 0;
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
      if(d<=31)
        return 1;
      else
        return 0;
    }
    else
    {
      if(d<=30)
        return 1;
      else
        return 0;
    }
  }
  else
    return 0;
}


int main(void)
{
  int year,month,date;
  printf("Enter the date: ");
  scanf("%d",&date);
  system("cls");
  printf("Enter the month: ");
  scanf("%d",&month);
  system("cls");
  printf("Enter the year: ");
  scanf("%d",&year);
  system("cls");
  //if the date exists then proceed with the functions otherwise exit
  if(check_validity(date,month,year))
  {
    day_of_the_week(year,month,date);
  }
  else
    printf("Entered date does not exist.");
  printf("\n");
}

