#include <cstdio>
#include <cstring>

int p[1000000];

void init(int until) {
  for (int i = 0; i <= until; i++)
    p[i] = i;
}

int find_p(int now) {
  if (p[now] == now)
    return now;
  return p[now] = find_p(p[now]);
}

void union_p(int p1, int p2) {
  int r1 = find_p(p1);
  int r2 = find_p(p2);

  if (r1 < r2)
    p[r2] = r1;
  else
    p[r1] = r2;
}

int main() {
  int T;
  scanf("%d", &T);
  getchar();

  while (T--) {
    int n;
    scanf("%d", &n);
    init(n);

    int success = 0, unsuccess = 0;
    while (true) {
      getchar();
      char cmd;
      cmd = getchar();

      if (cmd == '\n' || cmd == EOF)
        break;

      int c1, c2;
      scanf("%d%d", &c1, &c2);

      if (cmd == 'c')
        union_p(c1, c2);
      else
        if (find_p(c1) == find_p(c2))
          success++;
        else
          unsuccess++;
    }

    printf("%d,%d\n", success, unsuccess);
    if (T == 0)
      break;
    printf("\n");
  }

  return 0;
}