// Copyright (c) 2015 Chen Li-Yu

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    vector<LL> coin;
    LL total = 0;
    for (int i = 0; i != n; ++i) {
      LL buf;
      scanf("%lld", &buf);
      coin.push_back(buf);
      total += buf;
    }

    LL divide = total / n;
    LL now = 0;
    vector<LL> gap;
    gap.push_back(0);
    for (int i = 0; i != n - 1; ++i) {
      now += divide - coin[i];
      gap.push_back(-now);
    }

    sort(gap.begin(), gap.end());

    LL mid = gap[gap.size() / 2];

    LL ans = 0;
    for (int i = 0; i != gap.size(); ++i) {
      ans += abs(mid - gap[i]);
    }

    printf("%lld\n", ans);
  }


  return 0;
}