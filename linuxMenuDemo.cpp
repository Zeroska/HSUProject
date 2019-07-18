#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <iostream>
#include <termios.h>
#include <unistd.h>


#define MAX_REF 100
#define MAX_FRAME 20
#define AAA 3
#define STRINT "%3d"
#define LEFTALIGN 12
#define OLDCOLOR 15
#define BLINKCOLOR 14								
#define COLOR_RESET   "\033[0m"
#define COLOR_BLACK   "\033[30m"      /* Black */
#define COLOR_RED     "\033[31m"      /* Red */
#define COLOR_GREEN   "\033[32m"      /* Green */
#define COLOR_YELLOW  "\033[33m"      /* Yellow */
#define COLOR_BLUE    "\033[34m"      /* Blue */
#define COLOR_MAGENTA "\033[35m"      /* Magenta */
#define COLOR_CYAN    "\033[36m"      /* Cyan */
#define COLOR_WHITE   "\033[37m"      /* White */
#define COLOR_BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define COLOR_BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define COLOR_BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define COLOR_BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define COLOR_BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define COLOR_BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define COLOR_BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define COLOR_BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void gotoxy(short x, short y);
void clrscr(void);
void printxy_int(short x, short y, int value);
int getch(void);

//--------------------------------------

//cac ham bo sung

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
	fflush(stdin);
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

// short getCurrentY()

// {

// }

// int getColor()

// {

// }

// void setColor(int color)

// {

// }

void printxy_int(int x, int y, int value)
{
	gotoxy(x, y);
	printf(STRINT, value);

}

void printxycolor_int(int x, int y, int value, const char* color)
{
	gotoxy(x,y);
	printf("%s" STRINT "%s", color, value, COLOR_RESET);
}

void printxycolor_str(int x, int y, char *value, const char* color)
{
	gotoxy(x,y);
	printf("%s%s%s", color, value, COLOR_RESET);
}

void clrscr(void)
{
   system("clear");  
   fflush(stdin);
}

//-------------MENU-------------

char list1[5][21]={"Phep cong","Phep tru","Phep nhan","Phep chia","Thoat"};
char list2[4][21]={"1 chu so","2 chu so","So bat ky","Thoat"};

//--------MENU------------------

//char runmenu(char list[][21],int x, int y);

void swapbetter(int &a,int &b)
{
	if(a>=b) return;
	int tam = a;
	a = b;
	b = tam;
}
void generate_problem(char ops, char scope,int &a, int &b, int &kq)
{
	int lowbound, highbound; //scope
	switch(scope)
    {
		case 0: //1 chuso
			lowbound = 1;
			highbound = 9;
			a = rand()%9 + 1;
			b = rand()%9 + 1;
			break;
		case 1: //2 chu so
			lowbound = 10;
			highbound = 99;
			a = rand()%90 + 10;
			b = rand()%90 + 10;
			
			break;
		case 2: //bat ky 1..1000
			lowbound = 1;
			highbound = 999;
			a = rand()%999 + 1;
			b = rand()%999 + 1;
	}
	swapbetter(a,b);
	switch(ops)
	{
		case 0://cong
			kq = a + b;
			break;
		case 1://tru
			kq = a - b;
			break;
		case 2://nha
			kq = a * b;
			break;
		case 3://chia
			kq = a/b;
	}
}
//--------WINDOW----------------
void draw_window(int x1,int y1, int x2, int y2)
{
	char leftop = '+';
	char leftbottom = '-';
	char righttop = '+';
	char rightbottom = '+';
	char left = '|';
	char top = '-';
	int i;
	for(i=x1; i<=x2; i++)	
    {
		gotoxy(i,y1);
		putchar(top);
	}
	for(i=x1; i<=x2; i++)
	{
		gotoxy(i,y2);
		putchar(top);
	}
	for(i=y1; i<=y2; i++)
	{
        gotoxy(x1,i);
        putchar(left);
    }
	for(i=y1; i<=y2; i++)
	{
		gotoxy(x2,i);
		putchar(left);
	}
}


void eraseLineBaseOnXYCord(int xCord, int yCord) //it is supposed to erase a line
{
    printf("%c[%d;%dk",0x1B, yCord,xCord); //the line
    fflush(stdin);
}

void clear_window(int x1, int y1, int x2, int y2)
{
	int i=0,j;
	for (;i<y2-y1-1;i++)
	{
		gotoxy(x1+1,y1+1+i);
		for(j=1;j<x2-x1;j++)
			putchar(' ');
	}
}
void showlist(int x1, int y1, char s[5][21], int count)
{
	int i;
	for(i=0; i<count; i++)
	{
		gotoxy(x1+1,y1+1+i);
		printf("%s",s[i]);
	}
}
char runmenu1(int x1, int y1, char s[5][21], int count, int oldchoice=0)
{
	char c, choice;
	int i;
	draw_window(x1,y1,x1+25,y1+6);
	showlist(x1,y1,s,count);
	i = oldchoice;
	do
	{
		printxycolor_str(x1+1,y1+1+i,s[i],COLOR_YELLOW);
		c=getch();
		if(c==0) c=getch();
		switch(c)
		{
            case 65:
			// case 72: //up
				printxycolor_str(x1+1,y1+1+i,s[i],COLOR_RESET);
				i = (i + count - 1)	% count;
				break;
            case 66:
			// case 80: //down
				printxycolor_str(x1+1,y1+1+i,s[i],COLOR_RESET);
				i = (i + 1)	% count;
				break;
            case 10:
			// case 13:
				if(i==(count-1))
					choice = -1;
				else
				 	choice = i;
				break;
		}
	}while(c!=10);//13
	return choice;
}
//--------MAIN------------------
int main(int argc, char** argv) {
	char ops, scope, choice1=0, choice2=0;
	int numproblem=0, score=0;
	char s[37];
	int a,b,kq,answer;
	int x = 10;
	int y = 5;
	time_t t;
	clrscr();
	//Gioi thieu chuong trinh
	sprintf(s,"Chuong trinh minh hoa MENU - huanpdt");
	printxycolor_str(x,y-2,s,COLOR_RED);	
	do
	{
		choice1 = runmenu1(x,y,list1,5,choice1);
		choice2 = 0;
		while(choice1!=-1 && choice2!=-1)
		{
			srand((unsigned) time(&t));
			choice2 = runmenu1(x+26,y,list2,4,choice2);
			if(choice2!=-1)
			{
				generate_problem(choice1,choice2,a,b,kq);
				numproblem ++;
				draw_window(x,y+8,75,y+15);
                
				clear_window(x,y+8,75,y+15);
				//show problem
				ops = choice1;
				switch(ops)
				{
					case 0://cong
						sprintf(s,"%4d + %4d =   ?",a,b);
						break;
					case 1://tru
						sprintf(s,"%4d - %4d =   ?",a,b);
						break;
					case 2://nhan
						sprintf(s,"%4d * %4d =   ?",a,b);
						break;
					case 3://chia
						sprintf(s,"%4d / %4d =   ?",a,b);
						break;
				}
				printxycolor_str(x+1,y+9,s,COLOR_RESET);
				gotoxy(x+2,y+11);
				printf("Nhap ket qu= ");
				scanf("%d",&answer);
				if(answer==kq)
				{
					sprintf(s,"DUNG ROI!");
					score++;
				}
				else
					sprintf(s,"SAI!");
				printxycolor_str(x+2,y+13,s,COLOR_RESET);
				//show score
				sprintf(s,"Scores: %3d/%3d",score,numproblem);
				printxycolor_str(x+2,y+16,s,COLOR_RESET);
			}
		}
	}while(choice1!=-1);
	y = 1;
	gotoxy(x+1,y);
	printf("Chuong trinh ket thuc!");
	system("pause");
	return 0;
}

//http://www.cse.psu.edu/~kxc104/class/cmpen472/16f/hw/hw8/vt100ansi.htm
