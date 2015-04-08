#include <cstdio>
#include <cstring>

int ans[10010][10] = {0};

void init() {
  for (int i = 1; i != 10000; i++) {
    for (int j = 0; j != 10; j++)
      ans[i][j] = ans[i - 1][j];

    char num[10];
    sprintf(num, "%d", i);

    for (int j = 0; j != strlen(num); j++) {
      int now = static_cast<int>(num[j] - '0');
      ans[i][now]++;
    }
  }
}

int main() {
  init();

  int T;
  scanf("%d", &T);

  while (T--) {
    int num;
    scanf("%d", &num);

    for (int i = 0; i != 10; i++)
      printf("%d%c", ans[num][i], i == 9 ? '\n' : ' ');
  }

  return 0;
}