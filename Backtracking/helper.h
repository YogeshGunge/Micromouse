struct maze {
  int link[4];
  int trace;
};
#define MAX 4

void mazeout(int r, int c, struct maze block[MAX][MAX]);
int getch(void);

