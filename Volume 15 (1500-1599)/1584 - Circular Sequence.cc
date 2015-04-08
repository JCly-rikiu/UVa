#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    string str;
    cin >> str;

    string ans = str;
    int len = str.length();
    for (int i = 0; i != len; i++) {
      string buf = str.substr(i, len) + str.substr(0, i);
      if (buf < ans)
        ans = buf;
    }

    cout << ans << endl;
  }

  return 0;
}