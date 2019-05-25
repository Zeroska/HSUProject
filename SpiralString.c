#include "stdio.h"
#include "stdlib.h"

typedef enum {false, true}bool;

int countStringLenght(const char string[])
{
    int characterCounted = 0;
    int letter = 0;
    while(string[letter] != '\0')
    {
        characterCounted++;
    }
    return characterCounted;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]); //Matrix Size (N x N).
    char *str = argv[2]; //The damn string you enter.
    //code here

    //              USING 2D Array.
    //The actual size of your N x N matrix
    int matrixMaxSize = n * n;
    int center = n/2;//The statring position for your spiral form.
    bool isClockwise = false;
    char matrix[n][n];
    int R = center, C = center;
    int direction = 0, steps = 1, currentStep = 0, change = 0;
    //fill the matrix
    for (int i = 1; i <= matrixMaxSize; i++)
    {
       if(R < 0 || R >= n || C < 0 || C >= n)
       {
           i--;
       /* } */
       else matrix[R][C] = str[i];
        
       if (currentStep < steps)
       {
           currentStep++;
       }
       else
       {
           currentStep = 1;
           if (change == 1) 
           {
               steps++;
               change = (change + 1) %2;
               direction = (direction + 1) % 4;
           }
       }
       switch(direction)
       {
           case 0:
           {
               if(isClockwise)
               {
                    C++;
               }
               else
               {
                    C--;
               }
               break;
           }
          case 1:
           {
               R++;
               break;
           }
          case 2:
           {
               if(isClockwise)
               {
                    C--;
               }
               else 
               {
                    C++;
               }
               break;
           }
          case 3:
           {
                R--;
                break;
           }
       }
    }
    for(int row1 = 0; row1 < n; row1++)
    {
        for(int col1 = 0; col1 < n; col1++)
        {
            printf("%c ",matrix[row1][col1]);
        }
    }
    return 0;
}
