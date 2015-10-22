#include <cstdio>
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

struct Command {
  int cmd;
  string var;
  int value;
};

vector<Command> program[1000];
int n, q;
int t[6];
bool isLock = false;

void input() {
  getchar();
  scanf("%d", &n);
  for (int i = 0; i != 5; i++)
    scanf("%d", t + i);
  scanf("%d", &q);

  for (int i = 1; i <= n; i++) {
    program[i].clear();
    
    string cmd;
    while (cin >> cmd) {
      Command buf;
      if (cmd == "print") {
        buf.cmd = 1;
        cin >> buf.var;
      } else if (cmd == "lock") {
        buf.cmd = 2;
      } else if (cmd == "unlock") {
        buf.cmd = 3;
      } else if (cmd == "end") {
        buf.cmd = 4;
      } else {
        buf.cmd = 0;
        buf.var = cmd;
        string trash;
        cin >> trash;
        cin >> buf.value;
      }
      program[i].push_back(buf);
      if (buf.cmd == 4)
        break;
    }
  }
}

void solve() {
  deque<pair<int, int> > wq;
  queue<pair<int, int> > bq;
  map<string, int> variable;

  for (int i = 1; i <= n; i++)
    wq.push_back(make_pair(i, 0));

  while (!wq.empty()) {
    int now = wq.front().first;
    int cur = wq.front().second;
    wq.pop_front();
    
    int cnt = 0;
    while (true) {
      Command statement = program[now][cur];
      cnt += t[statement.cmd];

      if (statement.cmd == 0) {
        variable[statement.var] = statement.value;
      } else if (statement.cmd == 1) {
        printf("%d: %d\n", now, variable[statement.var]);
      } else if (statement.cmd == 2) {
        if (isLock) {
          bq.push(make_pair(now, cur));
          break;
        } else {
          isLock = true;
        }
      } else if (statement.cmd == 3) {
        isLock = false;
        if (!bq.empty()) {
          wq.push_front(bq.front());
          bq.pop();
        }
      } else {
        break;
      }
      cur++;

      if (cnt >= q) {
        wq.push_back(make_pair(now, cur));
        break;
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    input();
    solve();
    if (T != 0)
      printf("\n");
  }

  return 0;
}
