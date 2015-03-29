#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
  int b, j;

  bool operator <(const Job &x) const {
    return j > x.j;
  }
};

int main() {
  int n, t = 0;
  while (scanf("%d", &n) != EOF && n != 0) {
    vector<Job> queue;
    for (int i = 0; i != n; ++i) {
      int b, j;
      scanf("%d%d", &b, &j);
      queue.push_back((Job){b, j});
    }

    sort(queue.begin(), queue.end());

    int ans = 0;
    int now = 0;
    for (int i = 0; i != n; ++i) {
      now += queue[i].b;
      ans = ans >= now + queue[i].j ? ans : now + queue[i].j;
    }

    printf("Case %d: %d\n", ++t, ans);
  }

  return 0;
}