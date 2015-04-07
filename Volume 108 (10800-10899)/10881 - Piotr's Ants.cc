#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10010;

struct Ant {
  int pos;
  int way;
  int id;
  bool operator<(const Ant &a) const {
    return pos < a.pos;
  }
} before[MAXN], after[MAXN];

const char wayName[][10] = { "L", "Turning", "R" };

int main() {
  int T;
  scanf("%d", &T);
  for (int ti = 1; ti <= T; ++ti) {
    int l, t, n;
    scanf("%d%d%d", &l, &t, &n);

    for (int i = 0; i < n; ++i) {
      int pos;
      char way;
      scanf("%d %c", &pos, &way);

      int dway = (way == 'R' ? 1 : -1);
      before[i] = (Ant){ pos, dway, i };
      after[i] = (Ant){ pos + t * dway, dway, 0 };
    }

    int order[MAXN] = {0};
    sort(before, before + n);
    for (int i = 0; i < n; ++i) {
      order[before[i].id] = i;
    }

    sort(after, after + n);
    for (int i = 0; i < n - 1; ++i) {
      if (after[i].pos == after[i + 1].pos)
        after[i].way = after[i + 1].way = 0;
    }

    printf("Case #%d:\n", ti);
    for (int i = 0; i < n; ++i) {
      int ans = order[i];
      if (after[ans].pos > l || after[ans].pos < 0) {
        printf("Fell off\n");
      } else {
        printf("%d %s\n", after[ans].pos, wayName[after[ans].way + 1]);
      }
    }
    printf("\n");
  }

  return 0;
}