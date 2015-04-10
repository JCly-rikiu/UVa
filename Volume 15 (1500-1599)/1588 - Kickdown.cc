#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    if (s1.length() > s2.length())
      swap(s1, s2);

    int len1 = s1.length(), len2 = s2.length();

    int ans = len1 + len2;
    for (int i = -len2 + 1; i != len1; i++) {
      bool failed = false;
      for (int j = 0; j != len2; j++) {
        if (j + i >= 0 && j + i < len1) {
          if (static_cast<int>(s1[j + i] - '0') +
              static_cast<int>(s2[j] - '0') == 4) {
            failed = true;
            break;
          }
        }
      }
      if (failed)
        continue;

      int buf = len2;
      if (i < len1 - len2)
        buf += -i - (len2 - len1);
      else if (i > 0) {
        buf += i;
      }

      if (ans > buf)
        ans = buf;
      else if (ans < buf)
        break;
    }

    cout << ans << endl;
  }

  return 0;
}