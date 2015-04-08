#include <cstdio>
#include <cstring>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    char in[100];
    scanf("%s", in);

    int ans = 0;
    int add = 0;
    for (int i = 0; i != strlen(in); ++i) {
      if (in[i] == 'O')
        ans += ++add;
      else
        add = 0;
    }

    printf("%d\n", ans);
  }

  return 0;
}