#include "stdio.h"
#include "stdlib.h"

//This is a menu for a game which about selection and choices 



//This function is use for cursor Positioning
void goToXY(int x, int y) //move the cursor to the X:Y cord
{
  printf("%c[%d;%df",0x1B,y ,x); //0x1B is ESC Exp: "ESC[5;6f" go to 5:6 on console screen
  fflush(stdin);//flush the buffer
}
//Draw the menu base on cordinate you set for 
void drawMenuBorder(int x1, int y1, int x2 ,int y2)
{
  char left = '|';//the column at the left (right) is print as '|'
  char top = '-';// the row at the top(bottom) is print as '-'
  int i;
  for(i = x1; i <= x2; i++) 
  {
    goToXY(i, y1);
    printf("%c",top);
  }

  for(i = x1; i <= x2 ; i++)
  {
    goToXY(i, y2);
    printf("%c",top);
  }

  for(i = y1; i <= y2 ;i++)
  {
    goToXY(x1,i);
    printf("%c",left);
  }

  for(i = y1; i <= y2; i++)
  {
    goToXY(x2, i);
    printf("%c",left);
  }
}


int main()
{
  int x = 10, y = 5;
  drawMenuBorder(x,y+8,75,y+15);
}
