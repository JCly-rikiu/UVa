#include <cstdio>
#include <cmath>

const double E = 1e-4;

double ans[12][35];

void init() {
  for (int i = 0; i != 10; i++) {
    double m = (1 << (i + 1));
    m = 1 - 1 / m;
    m = log2(m);

    for (int j = 0; j != 31; j++) {
      ans[i][j] = m + ((1 << j) - 1);
    }
  }
}

bool eq(double a, double b) {
  return fabs(a - b) < E; 
}

int main() {
  init();

  double a;
  int b;
  while (scanf("%lfe%d", &a, &b) != EOF) {
    if (b == 0 && eq(a, 0.0))
      break;

    double now = log2(a) + b * log2(10);

    for (int i = 0; i != 10; i++) {
      for (int j = 1; j != 31; j++) {
        if (eq(ans[i][j], now)) {
          printf("%d %d\n", i, j);
        }
      }
    }
  }

  return 0;
}