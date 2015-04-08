#include <cstdio>
#include <algorithm>

const int MAXN = 1010;

int main() {
  int n;
  int T = 1;
  while (scanf("%d", &n) != EOF && n != 0) {
    printf("Game %d:\n", T++);

    int ans[MAXN];
    for (int i = 0; i != n; i++) {
      scanf("%d", ans + i);
    }

    while (true) {
      int A = 0;
      int cnt[10][2] = {0};
      for (int i = 0; i != n; i++) {
        int buf;
        scanf("%d", &buf);
        if (buf == ans[i]) {
          A++;
        } else {
          cnt[ans[i]][0]++;
          cnt[buf][1]++;
        }
      }

      if (cnt[0][1] != 0)
        break;

      int B = 0;
      for (int i = 1; i != 10; i++) {
        B += std::min(cnt[i][0], cnt[i][1]);
      }

      printf("    (%d,%d)\n", A, B);
    }
  }

  return 0;
}