#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int l, n;
    scanf("%d%d", &l, &n);

    int earliest = 0, lastest = 0;
    for (int i = 0; i != n; i++) {
      int pos;
      scanf("%d", &pos);

      int minium = pos < l - pos ? pos : l - pos;
      int maxium = l - minium;

      if (minium > earliest)
        earliest = minium;

      if (maxium > lastest)
        lastest = maxium;
    }

    printf("%d %d\n", earliest, lastest);
  }

  return 0;
}