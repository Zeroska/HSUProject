#include "stdio.h"

#define DAY_DEFAULT 1
#define MONTH_DEFAULT 1
#define YEAR_DEFAULT 1
#define DAY_OF_NORMAL_YEAR 365

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
   -------------TO DO--------------
   Function can add them vao project
   - check input (number, letter)
   - refactor functions
   - 
 */

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
    // If a year is multiple of 400,
    // then it is a leap year
    if (year % 400 == 0)
    {
        return true;
    }
    // Else If a year is muliplt of 100,
    // then it is not a leap year
    if (year % 100 == 0)
    {
        return false;
    }
    // Else If a year is muliplt of 4,
    // then it is a leap year
    if (year % 4 == 0)
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
    totalDateDiff = (((year - 1) * DAY_OF_NORMAL_YEAR) + countLeapYear) + calculateTotalDayInYear(day ,month ,year) ;
    return totalDateDiff; //
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
    printf(ANSI_COLOR_RED "|Sunday    |  0 |\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "|Monday    |  1 |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE"|Tuesday   |  2 |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"|Wednesday |  3 |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA"|Thursday  |  4 |\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN"|Friday    |  5 |\n"ANSI_COLOR_RESET);
    printf("|Saturday  |  6 |\n");
    printf("*---------------*\n");
}

void cleanBuffer()
{
    int n;
    while((n = getchar()) != EOF && n != '\n' );
}

int main()
{
    //can't catch the 31/4 and 29/2 in 2019.
    int day, month, year;
    do {
    printf("Please enter your day: ");
    scanf("%d",&day);
    cleanBuffer();
    }while(day < 0 || day > 31 );
    //add check for day
    do{
    printf("Please enter you month: ");
    scanf("%d",&month);
    cleanBuffer();
    }while(month < 0 || month > 12);

    do{
    printf("Please enter you year: ");
    scanf("%d",&year);
    }
    while(year < 0 || year > 5000);

    printfDayTable();

    int sevenDay = findTheSevenDayOfWeek(day , month , year);
    printf("the day: %d\n",sevenDay);
}
