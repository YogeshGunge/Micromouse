#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "helper.h"

#define MAX 4

/* reads from keypress, doesn't echo */
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

void mazeout(struct maze block[MAX][MAX])
{
int i,j;
for(i=0;i<MAX;i++)
	printf("%c%c",'+','-');      //+-+-+-+-
printf("%c", '+');                          //+-+-+-+-+
for(i=0;i<MAX;i++)                  //| | | |
	{printf("\n%c",'|');
	 for(j=0;j<MAX;j++)
		{if(block[i][j].trace==1)printf("%c", '*');
		else printf("%c", ' ');
		if(block[i][j].link[0]==1)printf("%c", ' ');
		else printf("%c", '|');
		 }
	 printf("\n%c",'+');
	 for(j=0;j<MAX;j++)
		{if(block[i][j].link[3]==1)printf("%c", ' ');
		else printf("%c", '-');
		printf("%c", '+');
		}
	 }
}
