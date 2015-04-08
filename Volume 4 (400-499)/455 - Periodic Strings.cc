#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;

  bool first = true;
  while (T--) {
    string str;
    cin >> str;

    for (int i = 1; i <= str.length(); i++) {
      if (str.length() % i != 0)
        continue;

      string part = str.substr(0, i);
      string buf = part;
      int times = str.length() / i;
      for (int j = 1; j != times; j++)
        buf += part;

      if (str == buf) {
        if (first) {
          first = false;
          cout << i << endl;
        } else {
          cout << endl << i << endl;
        }

        break;
      }
    }
  }

  return 0;
}