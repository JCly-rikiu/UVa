#include <iostream>
#include <cstdio>

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string repr(string str) {
  for (int i = 0; i != str.length(); i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = (char)((int)str[i] + 32);

  sort(str.begin(), str.end());

  return str;
}

int main() {
  vector<string> words;
  map<string, int> cnt;

  string str;
  while (cin >> str) {
    if (str[0] == '#')
      break;

    words.push_back(str);
    cnt[repr(str)]++;
  }

  vector<string> ans;
  for (int i = 0; i != words.size(); i++)
    if (cnt[repr(words[i])] == 1)
      ans.push_back(words[i]);

  sort(ans.begin(), ans.end());
  for (int i = 0; i != ans.size(); i++)
    cout << ans[i] << endl;

  return 0;
}