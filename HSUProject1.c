#include "stdio.h"

#define DAY_DEFAULT 1
#define MONTH_DEFAULT 1
#define YEAR_DEFAULT 1
#define DAY_OF_NORMAL_YEAR 365


enum days //asign number for the seven days of week for easier tracking
{
    monday = 1,
    tuesday = 2,
    wednesday = 3,
    thursday = 4,
    friday = 5,
    saturday = 6,
    sunday = 0
};

typedef enum //self-made boolean type
{
    false,
    true
}bool;

bool checkLeapYear(int year) //check whether the year is leap or not
{
    if (((year % 4 == 0) && (year % 100 != 10)) || year % 400 == 0)
    {
        return true;
    }
    return false;
}


int calculateTotalDayInYear(int day, int month, int year) //version 1
{
    int totalDayDiff = day, daysInFeb = 28;

    if(checkLeapYear(year) == true )
    {
        daysInFeb = 29;
    }
    switch(month)
    {
        case 2:
         {
            totalDayDiff += 31;
            break;
         }
        case 3:
         {
            totalDayDiff += 31 + daysInFeb;
            break;
         }
        case 4:
         {
            totalDayDiff += 31 + daysInFeb + 31;
            break;
         }
        case 5:
         {
            totalDayDiff += 31 + daysInFeb +31 + 30;
            break;
         }
        case 6:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31;
            break;
         }
        case 7:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31 + 30;
            break;
         }            
        case 8:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31;
            break;
         }
        case 9:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31;
            break;
         }
        case 10:
         {
             totalDayDiff += 31 + daysInFeb + 31 + 30 +31 +30 + 31 +31 +30;   
             break;
         }
        case 11:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;           
            break;
         }
        case 12:
         {
            totalDayDiff += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;            
            break;
         }
    }
   return totalDayDiff;
}


int calculateTheTotalDateDiff(int day, int month, int year) 
{
    int totalDateDiff = 0;//the total day of the the gap between 1/1/1 and the date your entered 
    int countLeapYear = 0;
    for (int i = YEAR_DEFAULT; i < year; i++)
    {
        if(checkLeapYear(i) == true)
        {
            countLeapYear++; //count how many leap years are there in the gap between 1/1/1 and the date your entered
        }
    }
    totalDateDiff = (((year - 1) * DAY_OF_NORMAL_YEAR) + countLeapYear) + calculateTotalDayInYear(day ,month ,year) - 15 ;
    return totalDateDiff; //why you subtract 15 ???? 
}


int findTheSevenDayOfWeek(int day, int month, int year)
{
    int totalDateDiff = calculateTheTotalDateDiff(day,month,year); //total number of day betwwen 1/1/1 and the date you entered
    int sevenDayOfWeek = totalDateDiff % 7; 
    switch(sevenDayOfWeek)
    {
        case 1:
        {
            return monday;
            break;
        }
        case 2:
        {
            return tuesday;
            break;
        }
        case 3:
        {
             return wednesday;
             break;
        }
        case 4:
        {
             return thursday;
             break;
        }
        case 5:
        {
             return friday;
             break;
        }
        case 6:
        {
             return saturday;
             break;
        }
        case 0:
        {
             return sunday;
             break;
        }
        default:
        {
             printf("Oof It looks like something went wrong.");
             return -1;
        }
    }
}
void printfDayTable()
{
    printf("\n*---------------*\n");
    printf("|Day       | Ref|\n");
    printf("|Sunday    |  0 |\n");
    printf("|Monday    |  1 |\n");
    printf("|Tuesday   |  2 |\n");
    printf("|Wednesday |  3 |\n");
    printf("|Thursday  |  4 |\n");
    printf("|Friday    |  5 |\n");
    printf("|Saturday  |  6 |\n");
    printf("*---------------*\n");
}

int main()
{
    int day, month, year;
    printf("Please enter your day: ");
    scanf("%d",&day);
    printf("Please enter you month: ");
    scanf("%d",&month);
    printf("Please enter you year: ");
    scanf("%d",&year);
    
    printfDayTable();

    int sevenDay = findTheSevenDayOfWeek(day , month , year);

    printf("the day: %d\n",sevenDay);
}
