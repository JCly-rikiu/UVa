#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100;

map<char, double> molar_mass;

int main() {
  molar_mass['C'] = 12.01;
  molar_mass['H'] = 1.008;
  molar_mass['O'] = 16.00;
  molar_mass['N'] = 14.01;

  int T;
  scanf("%d", &T);

  while (T--) {
    double ans = 0.0;

    char molecular[MAXN];
    scanf("%s", molecular);

    int buf = 0;
    char atom;
    bool first = true;
    for (int i = 0; i != strlen(molecular); i++) {
      char now = molecular[i];
      if (now >= '0' && now <= '9') {
        buf = buf * 10 + static_cast<int>(now - '0');
      } else {
        if (first) {
          first = false;
        } else {
          if (buf == 0)
            buf = 1;
          ans += molar_mass[atom] * buf;
        }

        atom = now;
        buf = 0;
      }
    }
    if (buf == 0)
      buf = 1;
    ans += molar_mass[atom] * buf;

    printf("%.3lf\n", ans);
  }

  return 0; 
}