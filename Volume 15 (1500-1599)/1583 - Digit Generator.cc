#include <cstdio>
#include <cstring>

const int MAXN = 101000;

int ans[MAXN] = {0};

void init() {
  for (int i = 100000; i > 0; i--) {
    char num[10];
    sprintf(num, "%d", i);

    int add = 0;
    for (int j = 0; j != strlen(num); j++) {
      add += static_cast<int>(num[j] - '0');
    }

    ans[i + add] = i;
  }
}

int main() {
  init();

  int T;
  scanf("%d", &T);

  while (T--) {
    int num;
    scanf("%d", &num);

    printf("%d\n", ans[num]);
  }

  return 0;
}