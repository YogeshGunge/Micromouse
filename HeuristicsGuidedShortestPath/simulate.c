#include <stdio.h>
#include "helper.h"

#define MAX 4

struct maze block[MAX][MAX];

struct pseudomouse {
  int pmr[2 * MAX], pmc[2 * MAX]; // Current Position of mouse
  char dir[2 * MAX][MAX * MAX]; // Path taken by the mouse
  int dist[2 * MAX]; // Total distance travelled
  int top;
} m;

const char * directionStr[] = {"Right", "Up", "Left", "Down"};

int main() {
  int r1, r2, c1, c2, i, j, k, nlinks, d, direction, distance, distanceMin, closestMouseIndex, closestMouseDistance, closestDirection, closestNlinks;
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
    closestMouseIndex = 0;
    closestMouseDistance  = (MAX * MAX) + (MAX * MAX);
    direction = 0;
    for (i = 0; i <= m.top; i++) {
      nlinks = block[m.pmr[i]][m.pmc[i]].link[0] + block[m.pmr[i]][m.pmc[i]].link[1] + block[m.pmr[i]][m.pmc[i]].link[2] + block[m.pmr[i]][m.pmc[i]].link[3];
      if (block[m.pmr[i]][m.pmc[i] + 1].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[0] == 1) nlinks--;
      if (block[m.pmr[i] - 1][m.pmc[i]].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[1] == 1) nlinks--;
      if (block[m.pmr[i]][m.pmc[i] - 1].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[2] == 1) nlinks--;
      if (block[m.pmr[i] + 1][m.pmc[i]].trace == 1 && block[m.pmr[i]][m.pmc[i]].link[3] == 1) nlinks--;
      printf("\n\nNumber of links of mouse %d at (%d, %d) is %d", i, m.pmr[i], m.pmc[i], nlinks);
      if(nlinks == 0) {
        distanceMin = (MAX * MAX) + (MAX * MAX);
      }
      else {
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
          //printf("\nDistance0 is %d", distance);
        }
        if (block[m.pmr[i] - 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[1] == 1) {
          distance = (r2 - (m.pmr[i] - 1)) * (r2 - (m.pmr[i] - 1)) + (c2 - m.pmc[i]) * (c2 - m.pmc[i]);
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 1;
          }
          //printf("\nDistance1 is %d", distance);
        }
        if (block[m.pmr[i]][m.pmc[i] - 1].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[2] == 1) {
          distance = (r2 - m.pmr[i]) * (r2 - m.pmr[i]) + (c2 - (m.pmc[i] - 1)) * (c2 - (m.pmc[i] - 1));
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 2;
          }
          //printf("\nDistance2 is %d", distance);
        }
        if (block[m.pmr[i] + 1][m.pmc[i]].trace != 1 && block[m.pmr[i]][m.pmc[i]].link[3] == 1) {
          distance = (r2 - (m.pmr[i] + 1)) * (r2 - (m.pmr[i] + 1)) + (c2 - m.pmc[i]) * (c2 - m.pmc[i]);
          if(distance < distanceMin) {
            distanceMin = distance;
            direction = 3;
          }
          //printf("\nDistance3 is %d", distance);
        }
      } // End of else on nlinks
      // Step 3: Find the closest mouse
      printf("\nDirection chosen by mouse %d at (%d, %d) is %s, bcoz distance = %d", i, m.pmr[i], m.pmc[i], directionStr[direction], distanceMin);
      if(distanceMin < closestMouseDistance) {
        closestMouseDistance = distanceMin;
        closestMouseIndex = i;
        closestDirection = direction;
        closestNlinks = nlinks;
      }
    } // End of for loop on i
    // Step 4: Add more mouse if nlinks > 1
    printf("\nClosest mouse %d at (%d, %d), at distance from target = %d, nlinks is %d, direction is %d", closestMouseIndex, m.pmr[closestMouseIndex], m.pmc[closestMouseIndex], closestMouseDistance, closestNlinks, closestDirection);
    if(closestNlinks > 1) {
       i = closestMouseIndex;
       m.top++;
       m.pmr[m.top] = m.pmr[i];
       m.pmc[m.top] = m.pmc[i];
       for (k = 0; k < m.dist[i]; k++)
         m.dir[m.top][k] = m.dir[i][k];
       m.dist[m.top] = m.dist[i];
       printf("\nAdded 1 more mouse at (%d, %d), top is %d", m.pmr[i], m.pmc[i], m.top);
    }
    // Step 5: Move the closest mouse
    printf("\nDirection taken by mouse %d at (%d, %d) is %s", closestMouseIndex, m.pmr[closestMouseIndex], m.pmc[closestMouseIndex], directionStr[closestDirection]);
    switch (closestDirection) {
    case 0:
      m.pmc[closestMouseIndex]++;
      break;
    case 1:
      m.pmr[closestMouseIndex]--;
      break;
    case 2:
      m.pmc[closestMouseIndex]--;
      break;
    case 3:
      m.pmr[closestMouseIndex]++;
      break;
    } // End of switch on closestDirection
    printf(" and moved to (%d, %d).", m.pmr[closestMouseIndex], m.pmc[closestMouseIndex]);
    m.dir[closestMouseIndex][m.dist[closestMouseIndex]] = closestDirection;
    m.dist[closestMouseIndex]++;
    printf("\nDistance travelled by mouse %d at (%d, %d) is %d", closestMouseIndex, m.pmr[closestMouseIndex], m.pmc[closestMouseIndex], m.dist[closestMouseIndex]);
    block[m.pmr[closestMouseIndex]][m.pmc[closestMouseIndex]].trace = 1;
    printf("\nCurrent Maze: \n");
    mazeout(block);
    printf("\nDistance of mouse %d at (%d, %d) from (%d, %d) is : %d\n", closestMouseIndex, m.pmr[closestMouseIndex], m.pmc[closestMouseIndex], r2, c2, closestMouseDistance);
    printf("\nTotal number of mouse is : %d\n", (m.top+1));
    getch();
    if (m.pmr[closestMouseIndex] == r2 && m.pmc[closestMouseIndex] == c2) break;
  }// End of for loop on d

  //to print solution
  i = closestMouseIndex;
  if (m.pmr[i] == r2 && m.pmc[i] == c2) {
    printf("\n\nSolution is:\nStart -> ");
    for (k = 0; k < m.dist[i]; k++)
      printf("%s -> ", directionStr[m.dir[i][k]]);
      printf("Target\n");
  } else printf("\nNo Path goes to destination!!");
  getch();
}
