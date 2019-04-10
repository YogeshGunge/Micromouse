#include <stdio.h>
#include "helper.h"

#define MAX 4

struct maze block[MAX][MAX];

struct pseudomouse {
  int pmr[2 * MAX], pmc[2 * MAX];
  char dir[2 * MAX][MAX * MAX];
  int dist[2 * MAX];
  int top;
} m;

const char * directionStr[] = {"Right", "Up", "Left", "Down"};

int main() {
  int r1, r2, c1, c2, i, j, k, nlinks, d, direction, distance, distanceMin, mouseMoved;
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
  getch();
  //to solve the maze
  //to initialise first mouse
  m.pmr[0] = r1;
  m.pmc[0] = c1;
  m.top = 0;
  block[r1][c1].trace = 1;
  for (d = 0; d < (MAX * MAX); d++) {
    mouseMoved = 0;
    direction = 0;
    for (i = 0; i <= m.top && mouseMoved == 0; i++) {
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
        for (k = 0; k < m.dist[i]; k++)
          m.dir[m.top][k] = m.dir[i][k];
        m.dist[m.top] = m.dist[i];
      case 1:
        // Step 2: Choose the path that is towards your goal
        // 0 - right, 1 - top, 2 - left, 3 - down
        // finding direction that gives minimum distance
        distanceMin = (MAX * MAX) + (MAX * MAX);
        if (block[m.pmr[i]][m.pmc[i] + 1].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[0] == 1) {
          distance = (r2 - m.pmr[i]) * (r2 - m.pmr[i]) + (c2 - (m.pmc[i] + 1)) * (c2 - (m.pmc[i] + 1));
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 0;
          }
          printf("\nDistance0 is %d", distance);
        }
        if (block[m.pmr[i] - 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[1] == 1) {
          distance = (r2 - (m.pmr[i] - 1)) * (r2 - (m.pmr[i] - 1)) + (c2 - m.pmc[i]) * (c2 - m.pmc[i]);
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 1;
          }
          printf("\nDistance1 is %d", distance);
        }
        if (block[m.pmr[i]][m.pmc[i] - 1].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[2] == 1) {
          distance = (r2 - m.pmr[i]) * (r2 - m.pmr[i]) + (c2 - (m.pmc[i] - 1)) * (c2 - (m.pmc[i] - 1));
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 2;
          }
          printf("\nDistance2 is %d", distance);
        }
        if (block[m.pmr[i] + 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[3] == 1) {
          distance = (r2 - (m.pmr[i] + 1)) * (r2 - (m.pmr[i] + 1)) + (c2 - m.pmc[i]) * (c2 - m.pmc[i]);
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 3;
          }
          printf("\nDistance3 is %d", distance);
        }
        printf("\nDirection chosen by mouse %d is %s", i, directionStr[direction]);
        // Step 3: Move the mouse
        switch (direction) {
        case 0:
          m.pmc[i]++;
          break;
        case 1:
          m.pmr[i]--;
          break;
        case 2:
          m.pmc[i]--;
          break;
        case 3:
          m.pmr[i]++;
          break;
        } // End of switch on direction
        m.dir[i][m.dist[i]] = direction;
        m.dist[i]++;
        printf("\nDistance travelled by mouse %d is %d", i, m.dist[i]);
        block[m.pmr[i]][m.pmc[i]].trace = 1;
        mouseMoved = 1;
      } // End of switch on nlinks
      if (m.pmr[i] == r2 && m.pmc[i] == c2) break;
    }
    if (m.pmr[i] == r2 && m.pmc[i] == c2) break;
    printf("\nCurrent Maze: \n");
    mazeout(block);
    getch();
  }
  //to print solution
  if (m.pmr[i] == r2 && m.pmc[i] == c2) {
    printf("\n\nSolution is:\nStart -> ");
    for (k = 0; k < m.dist[i]; k++)
      printf("%s -> ", directionStr[m.dir[i][k]]);
      printf("Target\n");
  } else printf("\nNo Path goes to destination!!");
  getch();
}
