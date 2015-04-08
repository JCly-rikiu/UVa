#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXN = 60;
string dna[MAXN];
map<char, int> atcg;
map<int, char> gcta;

int main() {
  atcg['A'] = 0;
  atcg['C'] = 1;
  atcg['G'] = 2;
  atcg['T'] = 3;

  gcta[0] = 'A';
  gcta[1] = 'C';
  gcta[2] = 'G';
  gcta[3] = 'T';

  int T;
  scanf("%d", &T);

  while (T--) {
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 0; i != m; i++)
      cin >> dna[i];

    string anss;
    int ansn = 0;
    for (int i = 0; i != n; i++) {
      int cnt[4] = {0};
      for (int j = 0; j != m; j++) {
        cnt[atcg[dna[j][i]]]++;
      }

      int maxn = 0;
      for (int j = 0; j != 4; j++) {
        if (cnt[j] > cnt[maxn]) {
          maxn = j;
        }
      }
      ansn += m - cnt[maxn];
      anss.append(1, gcta[maxn]);
    }

    cout << anss << endl;
    cout << ansn << endl;
  }

  return 0;
}