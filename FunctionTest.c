#include "stdio.h"
#include "string.h"

#define gotoXy(x, y) printf("\033[%d;%dH",(y),(x))
#define clear(void) printf("\033[H\033[J")


void gotoXY(int xCord, int yCord)
{
    printf("\033[%d;%df", yCord, xCord);
    fflush(stdin);
}
int main()
{
    int a;
    clear(void);
        printf(
        "Enter your number in the box below\n"
        "+-----------------+\n"
        "|                 |\n"
        "+-----------------+\n"
    );
    gotoXY(2,3);
    scanf("%d",&a);
}
