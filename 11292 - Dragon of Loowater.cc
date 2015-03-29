#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    vector<int> dragon;
    vector<int> knight;
    for (int i = 0; i != n; ++i) {
      int buf;
      cin >> buf;
      dragon.push_back(buf);
    }
    for (int i = 0; i != m; ++i) {
      int buf;
      cin >> buf;
      knight.push_back(buf);
    }

    sort(dragon.begin(), dragon.end());
    sort(knight.begin(), knight.end());

    int ans = 0;
    bool is_find = false;
    vector<int>::iterator id = dragon.begin(), ik = knight.begin();
    for (; id != dragon.end(); ++id) {
      is_find = false;
      for (; ik != knight.end(); ++ik) {
        if (*ik >= *id) {
          ans += *ik;
          is_find = true;
          ++ik;
          break;
        }
      }
      if (is_find == false) {
        break;
      }
    }

    if (is_find) {
      cout << ans << endl;
    } else {
      cout << "Loowater is doomed!" << endl;
    }
  }

  return EXIT_SUCCESS;
}