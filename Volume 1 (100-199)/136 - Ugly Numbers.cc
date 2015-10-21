#include <cstdio>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(1);

  int cnt = 0;
  int now = 0;
  while (cnt < 1500) {
    int buf = pq.top();
    pq.pop();

    if (now >= buf)
      continue;
    now = buf;
    pq.push(now * 2);
    pq.push(now * 3);
    pq.push(now * 5);

    cnt++;
  }

  printf("The 1500'th ugly number is %d.\n", now);

  return 0;
}
