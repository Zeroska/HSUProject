#include "stdio.h"
#include "stlib.h"


#define clear(void) printf("\033[H\033[J") //Clear 
#define gotoXY(xCord, yCord) printf("\033[%d;%dH",(xCord), (yCord))


//Create a grid 20 x 10
//each square must be mark by something
//mark the square occupied or free by using 1 and 0, 1 for free and 0 for
//ocupied
//
//how to score (point counter)
//multi-thread using ?
//random the block drop down
//start at the top and end at the bottom of the grid
//control the move up move left,right and down key
//space in ANCII
//shape of the block drop 0.down
//the speed of the block
//track the location of the block

//ALGORITHM for scanning the full line and deleted it and add point
//set the foreground to purple

int addPoint();

void gotoXY(int xCord, int yCord)
{
    printf("%c[%d;%df", 0x1B, yCord, xCord);
    fflush(stdin);
}


//void eraseLineBaseOnXY(int xCord, int yCord)
//{
    //this line is supposed to erase a line (from cursor the end of line)
//    printf("%c[%d;%dk",0x1B,yCord,xCord);//The K is the final character to determine what cursor would do
//    fflush(stdin);                      //clear the input buffer
//}


void draw2DimensionGrid(int xCord, int yCord, int xCord1, int yCord1) //Draw the grid 20x10 height 20 width 10
{
    //draw the top of the grid
    for (int i = 0; i < )
}

void createMainMenu()
{

}

int main(void)
{
    printf("Game Over");
}
