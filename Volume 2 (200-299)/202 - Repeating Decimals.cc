#include <cstdio>
#include <algorithm>

int numerator, denominator;
int mu, lam;

int f(int n) {
  n *= 10;
  return n % denominator;
}

void floyd_cycle_finding(int x0) {
  int tortoise = f(x0), hare = f(f(x0));
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(f(hare));
  }

  tortoise = x0;
  mu = 0;
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    mu++;
  }

  hare = f(tortoise);
  lam = 1;
  while (tortoise != hare) {
    hare = f(hare);
    lam++;
  }
}

int main() {
  while (scanf("%d%d", &numerator, &denominator) != EOF) {
    floyd_cycle_finding(numerator % denominator);

    printf("%d/%d = ", numerator, denominator);
    printf("%d.", numerator / denominator);
    int now = numerator % denominator;
    for (int i = 0; i != mu; i++) {
      now *= 10;
      printf("%d", now / denominator);
      now %= denominator;
    }

    printf("(");
    for (int i = 0; i != std::min(50 - mu, lam); i++) {
      now *= 10;
      printf("%d", now / denominator);
      now %= denominator;
    }
    if (lam > 50 - mu) printf("...");
    printf(")\n");

    printf("   %d = number of digits in repeating cycle\n", lam);
    printf("\n");
  }

  return 0;
}
