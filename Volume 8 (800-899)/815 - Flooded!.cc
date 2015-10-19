#include <cstdio>

#include <algorithm>

using namespace std;

int land[35 * 35];

double abs(double n) {
  if (n < 0)
    return -n;
  return n;
}

bool eps(double a, double b) {
  return abs(a - b) < 1e-6;
}

int main() {
  int m, n;
  int T = 1;
  while (scanf("%d%d", &m, &n) != EOF) {
    if (n == 0 && m == 0)
      break;

    int num = n * m;
    for (int i = 0; i != num; i++)
      scanf("%d", land + i);

    int total;
    scanf("%d", &total);

    sort(land, land + num);

    double l = -1000, r = 1000;
    double mid;
    int cnt = 0;
    while (!eps(r, l)) {
      mid = (l + r) / 2;
      cnt = 0;
      double sum = 0;
      for (; cnt != num; cnt++) {
        if (land[cnt] > mid)
          break;
        sum += (mid - land[cnt]) * 100;
      }

      if (eps(sum, total))
        break;
      if (sum > total)
        r = mid;
      else
        l = mid;
    }

    printf("Region %d\n", T++);
    printf("Water level is %.2lf meters.\n", mid);
    printf("%.2lf percent of the region is under water.\n\n", (double)cnt / num * 100);
  }

  return 0;
}
