#include <stdio.h>
#include "helper.h"

#define MAX 4

struct maze block[MAX][MAX];

struct maze_invaded {
  int wall[4];
}
cur_blk[MAX][MAX];

int main(void) {
  int r1, r, c1, c, i, j, nlinks, stackR[MAX * MAX], stackC[MAX * MAX], top;
  char ch;
  top = -1;
  //initialise mazes
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      block[i][j].trace = 0;
      block[i][j].link[0] = 0;
      block[i][j].link[1] = 0;
      block[i][j].link[2] = 0;
      block[i][j].link[3] = 0;
      cur_blk[i][j].wall[0] = 1;
      cur_blk[i][j].wall[1] = 1;
      cur_blk[i][j].wall[2] = 1;
      cur_blk[i][j].wall[3] = 1;
    }
  //to input maze from user
  printf("\n%c", '+');
  for (j = 0; j < MAX; j++)
    printf("%c%c", '-', '+');
  for (i = 0; i < MAX; i++) {
    printf("\n%c", '|');
    for (j = 0; j < MAX - 1; j++) {
      printf(" ");
      ch = getch();
      if (ch == ' ') {
        block[i][j].link[0] = 1;
        block[i][j + 1].link[2] = 1;
        printf("%c", ' ');
      } else printf("%c", '|');
    }
    printf(" %c", '|');
    printf("\n%c", '+');
    if (i != MAX - 1)
      for (j = 0; j < MAX; j++) {
        ch = getch();
        if (ch == ' ') {
          block[i][j].link[3] = 1;
          block[i + 1][j].link[1] = 1;
          printf("%c", ' ');
        } else printf("%c", '-');
        printf("%c", '+');
      }
    else
      for (j = 0; j < MAX; j++)
        printf("%c%c", '-', '+');
  }
  printf("\nEnter row and colomn of starting position:");
  scanf("%d%d", & r1, & c1);
  //to solve the maze
  r = r1;
  c = c1;
  while (1) { //Count the links
    block[r][c].trace = 1;
    nlinks = block[r][c].link[0] + block[r][c].link[1] + block[r][c].link[2] + block[r][c].link[3];
    if (block[r][c + 1].trace == 1 && block[r][c].link[0] == 1) nlinks--;
    if (block[r - 1][c].trace == 1 && block[r][c].link[1] == 1) nlinks--;
    if (block[r][c - 1].trace == 1 && block[r][c].link[2] == 1) nlinks--;
    if (block[r + 1][c].trace == 1 && block[r][c].link[3] == 1) nlinks--;
    //Case1: End Of Backtracking
    if (top == -1 && nlinks == 0) break;
    else if (nlinks == 0) //Case2: Backtrack
    {
      if (top != -1) {
        r = stackR[top];
        c = stackC[top];
        top--;
      }
    } else if (nlinks == 1) //Case3: Move Forward
    {
      if (block[r][c + 1].trace == 0 && block[r][c].link[0] == 1) c++;
      else if (block[r - 1][c].trace == 0 && block[r][c].link[1] == 1) r--;
      else if (block[r][c - 1].trace == 0 && block[r][c].link[2] == 1) c--;
      else if (block[r + 1][c].trace == 0 && block[r][c].link[3] == 1) r++;
    } else //Store branch point and move forward
    {
      top++;
      stackR[top] = r;
      stackC[top] = c;
      if (block[r][c + 1].trace == 0 && block[r][c].link[0] == 1) c++;
      else if (block[r - 1][c].trace == 0 && block[r][c].link[1] == 1) r--;
      else if (block[r][c - 1].trace == 0 && block[r][c].link[2] == 1) c--;
      else if (block[r + 1][c].trace == 0 && block[r][c].link[3] == 1) r++;
    }
    mazeout(r, c, block);
    getch();
  }
  getch();
  return 0;
}

