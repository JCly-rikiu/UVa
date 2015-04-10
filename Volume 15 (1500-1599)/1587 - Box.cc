#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 8;
int w[MAXN];
int h[MAXN];

int main() {
  int wb, hb;
  while (scanf("%d%d", &wb, &hb) != EOF) {
    w[0] = min(wb, hb);
    h[0] = max(wb, hb);

    for (int i = 1; i != 6; i++) {
      scanf("%d%d", &wb, &hb);
      w[i] = min(wb, hb);
      h[i] = max(wb, hb);
    }
 
    for (int i = 0; i != 6; i++) {
      for (int j = i + 1; j != 6; j++) {
        if (w[i] > w[j]) {
          swap(w[i], w[j]);
          swap(h[i], h[j]);
        } else if (w[i] == w[j]) {
          if (h[i] > h[j]) {
            swap(w[i], w[j]);
            swap(h[i], h[j]);            
          }
        }
      }
    }

    bool ans = true;
    for (int i = 0; i < 6; i += 2) {
      if (w[i] != w[i + 1]) {
        ans = false;
        break;
      }
      if (h[i] != h[i + 1]) {
        ans = false;
        break;
      }
    }

    if (ans) {
      ans = false;
      if (w[0] == w[2] && h[0] == w[5] && h[2] == h[5])
        ans = true;
    }

    if (ans)
      printf("POSSIBLE\n");
    else
      printf("IMPOSSIBLE\n");
  }

  return 0;
}