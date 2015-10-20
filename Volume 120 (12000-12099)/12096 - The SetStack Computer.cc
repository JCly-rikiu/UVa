#include <cstdio>
#include <iostream>

#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

map<set<int>, int> m;
vector<set<int> > id;

int find_set(set<int> st) {
  if (m.count(st))
    return m[st];

  id.push_back(st);
  return m[st] = id.size() - 1;
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    int n;
    scanf("%d", &n);

    stack<int> s;
    for (int i = 0; i != n; i++) {
      string cmd;
      cin >> cmd;
      if (cmd[0] == 'P') {
        s.push(find_set(set<int>()));
      } else if (cmd[0] == 'D') {
        s.push(s.top());
      } else {
        set<int> a = id[s.top()]; s.pop();
        set<int> b = id[s.top()]; s.pop();
        set<int> buf;
        switch (cmd[0]) {
        case 'U':
          set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(buf, buf.begin()));
          break;
        case 'I':
          set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(buf, buf.begin()));
          break;
        case 'A':
          buf = b;
          buf.insert(find_set(a));
          break;
        }
        s.push(find_set(buf));
      }
      cout << id[s.top()].size() << endl;
    }
    cout << "***" << endl;
  }

  return 0;
}
