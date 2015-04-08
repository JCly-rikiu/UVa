#include <cstdio>

const int MAXN = 12;
char puzzle[MAXN][MAXN];
int num[MAXN][MAXN];
bool used[MAXN][MAXN];
int r, c;

void u_init() {
  for (int i = 0; i != MAXN; i++)
    for (int j = 0; j != MAXN; j++)
      used[i][j] = false;
}

void across(int x, int y) {
  printf("%3d.", num[x][y]);

  while (y != c && puzzle[x][y] != '*') {
    used[x][y] = true;
    printf("%c", puzzle[x][y]);
    y++;
  }
  printf("\n");
}

void down(int x, int y) {
  printf("%3d.", num[x][y]);

  while (x != r && puzzle[x][y] != '*') {
    used[x][y] = true;
    printf("%c", puzzle[x][y]);
    x++;
  }
  printf("\n");
}

int main() {
  int T = 1;
  while (scanf("%d%d", &r, &c) == 2) {
    for (int i = 0; i != r; i++) {
      scanf("%s", puzzle + i);
    }

    int cnt = 1;
    for (int i = 0; i != r; i++) {
      for (int j = 0; j != c; j++) {
        if (puzzle[i][j] == '*')
          continue;

        if (i - 1 < 0 || j - 1 < 0 ||
            puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*')
          num[i][j] = cnt++;
      }
    }

    if (T != 1) printf("\n");
    printf("puzzle #%d:\n", T++);

    printf("Across\n");
    u_init();
    for (int i = 0; i != r; i++) {
      for (int j = 0; j != c; j++) {
        if (used[i][j] == false && puzzle[i][j] != '*')
          across(i, j);
      }
    }

    printf("Down\n");
    u_init();
    for (int i = 0; i != r; i++) {
      for (int j = 0; j != c; j++) {
        if (used[i][j] == false && puzzle[i][j] != '*')
          down(i, j);
      }
    }
  }

  return 0;
}