#include <cstdio>

int main() {
  int N, k, m;

  while (true) {
    scanf("%d%d%d", &N, &k, &m);

    if (N == 0 && k == 0 && m == 0)
      break;

    bool members[22];
    for (int i = 0; i != 22; i++)
      members[i] = true;

    int cnt = N;
    int cnow = 0, rnow = 1;
    while (cnt > 0) {
      for (int i = 0; i != k; i++) {
        cnow = (cnow + 1) % N;
        while (members[cnow] == false)
          cnow = (cnow + 1) % N;
      }

      for (int i = 0; i != m; i++) {
        rnow = (rnow + N - 1) % N;
        while (members[rnow] == false)
          rnow = (rnow + N - 1) % N;
      }

      members[cnow] = members[rnow] = false;
      
      if (cnow == rnow) {
        printf("%3d", (cnow == 0 ? N : cnow));
        cnt--;
      } else {
        printf("%3d%3d", (cnow == 0 ? N : cnow), (rnow == 0 ? N : rnow));
        cnt -= 2;
      }

      if (cnt == 0)
        printf("\n");
      else
        printf(",");
    }
  }

  return 0;
}