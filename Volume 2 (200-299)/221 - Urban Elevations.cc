#include <cstdio>

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Building {
  int x, y;
  int w, d;
  int h;
  int num;

  bool operator<(const Building &a) const {
    if (x != a.x)
      return x < a.x;
    if (y != a.y)
      return y < a.y;
    return h < a.h;
  }
};

bool cover(vector<pair<int, int> > v, Building &now) {
  sort(v.begin(), v.end());
  
  int l = now.x;
  for (int i = 0; i != v.size(); i++)
    if (v[i].first <= l)
      l = max(l, v[i].second);
    else
      return false;

  return l >= now.x + now.w;
}

int main() {
  Building city[110];

  int T = 1;
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    for (int i = 0; i != n; i++) {
      scanf("%d%d%d%d%d", &city[i].x, &city[i].y, &city[i].w, &city[i].d, &city[i].h);
      city[i].num = i + 1;
    }

    if (T != 1)
      printf("\n");
    printf("For map #%d, the visible buildings are numbered as follows:\n", T++);

    sort(city, city + n);

    bool first = true;
    for (int i = 0; i != n; i++) {
      vector<pair<int, int> > v;
      for (int j = 0; j != n; j++) {
        if (i == j)
          continue;
        if (city[i].h > city[j].h || city[i].y <= city[j].y)
          continue;

        int l = max(city[i].x, city[j].x);
        int r = min(city[i].x + city[i].w, city[j].x + city[j].w);

        if (l < r)
          v.push_back(make_pair(city[j].x, city[j].x + city[j].w));
      }
      if (!cover(v, city[i])) {
        if (first) {
          printf("%d", city[i].num);
          first = false;
        } else {
          printf(" %d", city[i].num);
        }
      }
    }
    printf("\n");
  }

  return 0;
}
