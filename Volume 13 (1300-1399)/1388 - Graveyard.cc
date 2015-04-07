// Copyright (c) 2015 Chen Li-Yu

#include <cstdio>
#include <cmath>

int main() {
  int n, m;
  while(scanf("%d%d", &n, &m) != EOF) {
    double ans = 0.0;
    for (int i = 1; i != n; ++i) {
      double pos = static_cast<double>(i) / n * (n + m);
      ans += fabs(pos - floor(pos + 0.5)) / (n + m);
    }

    printf("%.4lf\n", ans * 10000);
  }

  return 0;
}