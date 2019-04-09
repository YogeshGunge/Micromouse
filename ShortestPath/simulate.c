#include <stdio.h>
#include "helper.h"

#define MAX 4

struct maze block[MAX][MAX];

struct pseudomouse {
  int pmr[2 * MAX], pmc[2 * MAX];
  char dir[2 * MAX][MAX * MAX];
  int top;
} m;

int main() {
  int r1, r2, c1, c2, i, j, k, nlinks, d;
  char ch;
  //initialise maze
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      block[i][j].trace = 0;
      block[i][j].link[0] = 0;
      block[i][j].link[1] = 0;
      block[i][j].link[2] = 0;
      block[i][j].link[3] = 0;
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
  printf("\nEnter row and colomn of destination position:");
  scanf("%d%d", & r2, & c2);
  //to solve the maze
  //to initialise first mouse
  m.pmr[0] = r1;
  m.pmc[0] = c1;
  m.top = 0;
  block[r1][c1].trace = 1;
  for (d = 0; d < (MAX * MAX); d++) {
    for (i = 0; i <= m.top; i++) {
      nlinks = block[m.pmr[i]][m.pmc[i]].link[0] + block[m.pmr[i]][m.pmc[i]].link[1] + block[m.pmr[i]][m.pmc[i]].link[2] + block[m.pmr[i]][m.pmc[i]].link[3];
      if (block[m.pmr[i]][m.pmc[i] + 1].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[0] == 1) nlinks--;
      if (block[m.pmr[i] - 1][m.pmc[i]].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[1] == 1) nlinks--;
      if (block[m.pmr[i]][m.pmc[i] - 1].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[2] == 1) nlinks--;
      if (block[m.pmr[i] + 1][m.pmc[i]].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[3] == 1) nlinks--;
      switch (nlinks) {
      case 0:
        break;
      case 3:
      case 2:
        m.top++;
        m.pmr[m.top] = m.pmr[i];
        m.pmc[m.top] = m.pmc[i];
        for (k = 0; k < d; k++)
          m.dir[m.top][k] = m.dir[i][k];
      case 1:
        if (block[m.pmr[i]][m.pmc[i] + 1].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[0] == 1) {
          m.dir[i][d] = 0;
          m.pmc[i]++;
        } else if (block[m.pmr[i] - 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[1] == 1) {
          m.dir[i][d] = 1;
          m.pmr[i]--;
        } else if (block[m.pmr[i]][m.pmc[i] - 1].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[2] == 1) {
          m.dir[i][d] = 2;
          m.pmc[i]--;
        } else if (block[m.pmr[i] + 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[3] == 1) {
          m.dir[i][d] = 3;
          m.pmr[i]++;
        }
        block[m.pmr[i]][m.pmc[i]].trace = 1;
      }
      if (m.pmr[i] == r2 && m.pmc[i] == c2) break;
    }
    if (m.pmr[i] == r2 && m.pmc[i] == c2) break;
    printf("\n\nCurrent Maze: \n");
    mazeout(block);
    getch();
  }
  //to print solution
  if (m.pmr[i] == r2 && m.pmc[i] == c2) {
    printf("\n\nSolution is:\nStart -> ");
    for (k = 0; k <= d; k++)
      switch (m.dir[i][k]) {
      case 0:
        printf("%s", "Right -> ");
        break;
      case 1:
        printf("%s", "Up -> ");
        break;
      case 2:
        printf("%s", "Left -> ");
        break;
      case 3:
        printf("%s", "Down -> ");
        break;
      }
      printf("Target\n");
  } else printf("\nNo Path goes to destination!!");
  getch();
}
