#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t;
  while (cin >> s >> t) {
    bool ans = true;
    int it = 0;
    for (int i = 0; i != s.length(); i++) {
      while (t[it] != s[i]) {
        it++;
        if (it == t.length()) {
          ans = false;
          break;
        }
      }
      it++;
      if (ans == false)
        break;
      
      if (i != s.length() - 1 && it == t.length()) {
        ans = false;
        break;
      }
    }

    if (ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}