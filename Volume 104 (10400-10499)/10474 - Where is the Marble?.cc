#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 10010;

int main() {
  int T = 1;
  int n, q;
  while (scanf("%d%d", &n, &q) != EOF) {
    if (n == 0 && q == 0)
      break;

    int num[MAXN];
    for (int i = 0; i != n; i++)
      scanf("%d", num + i);

    sort(num, num + n);

    printf("CASE# %d:\n", T++);
    for (int i = 0; i != q; i++) {
      int buf;
      scanf("%d", &buf);

      int pos = lower_bound(num, num + n, buf) - num;
      if (num[pos] == buf)
        printf("%d found at %d\n", buf, pos + 1);
      else
        printf("%d not found\n", buf);
    }
  }

  return 0;
}
