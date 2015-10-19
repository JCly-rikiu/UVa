#include <cstdio>

#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
  int T = 1;
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    bool sleep[15];
    int student[15][2];
    int until = 1;
    int sleepnum = 0;
    for (int i = 0; i != n; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);

      until *= (a + b);

      c--;
      c %= (a + b);
      if (c >= a) {
        sleep[i] = true;
        pq.push(make_pair((a + b) - c, i));
        sleepnum++;
      } else {
        sleep[i] = false;
        pq.push(make_pair(a - c, i));
      }

      student[i][0] = a;
      student[i][1]=  b;
    }

    int now = 0;
    int buf = 0;
    while (!pq.empty()) {
      if (now != pq.top().first) {
        sleepnum += buf;
        buf = 0;
      }
      if (sleepnum == 0) {
        printf("Case %d: %d\n", T++, now + 1);
        break;
      }

      if (now > until) {
        printf("Case %d: -1\n", T++);
        break;
      }

      now = pq.top().first;
      int id = pq.top().second;
      pq.pop();

      if (sleep[id]) {
        sleep[id] = false;
        buf--;
        pq.push(make_pair(now + student[id][0], id));
      } else {
        if (sleepnum > (n - sleepnum)) {
          sleep[id] = true;
          buf++;
          pq.push(make_pair(now + student[id][1], id));
        }
      }
    }
  }

  return 0;
}
