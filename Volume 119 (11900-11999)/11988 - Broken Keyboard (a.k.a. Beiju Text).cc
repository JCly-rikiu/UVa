#include <cstdio>
#include <cstring>

const int MAXN = 100000 + 10;
char str[MAXN];
int next[MAXN];

int main() {
  while (scanf("%s", str + 1) != EOF) {
    next[0] = 0;
    int cur = 0, last = 0;
    for (int i = 1; i <= strlen(str + 1); i++) {
      char now = str[i];
      if (now == '[') {
        cur = 0;
      } else if (now == ']') {
        cur = last;
      } else {
        next[i] = next[cur];
        next[cur] = i;
        if (next[i] == 0)
          last = i;
        cur = i;
      }
    }

    for (int i = next[0]; i != 0; i = next[i])
      printf("%c", str[i]);
    printf("\n");
  }

  return 0;
}
