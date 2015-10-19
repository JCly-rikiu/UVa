#include <iostream>
#include <cstdio>

#include <vector>
#include <string>

using namespace std;

const int MAXN = 25;

vector<int> v[MAXN];
int pos[MAXN];

void init() {
  for (int i = 0; i != MAXN; i++) {
    v[i].push_back(i);
    pos[i] = i;
  }
}

void put_back(int id, int num) {
  for (int i = v[id].size() - 1; i >= 0; i--) {
    int now = v[id][i];
    if (now == num)
      return ;

    v[id].pop_back();
    v[now].push_back(now);
    pos[now] = now;
  }
}

void put_on(int id, int num, int to) {
  int st;
  for (int i = v[id].size() - 1; i >= 0; i--) {
    int now = v[id][i];
    pos[now] = to;
    
    if (now == num) {
      st = i;
      break;
    }
  }

  v[to].insert(v[to].end(), v[id].begin() + st, v[id].end());
  v[id].erase(v[id].begin() + st, v[id].end());
}

int main() {
  int n;
  scanf("%d", &n);

  init();

  while (true) {
    string cmd1, cmd2;
    int a, b;
    cin >> cmd1 >> a >> cmd2 >> b;
    if (cmd1 == "quit")
      break;

    if (pos[a] == pos[b])
      continue;

    if (cmd1 == "move") {
      if (cmd2 == "over") {
        put_back(pos[a], a);
        v[pos[b]].push_back(a);
        v[pos[a]].pop_back();
        pos[a] = pos[b];
      } else {
        put_back(pos[a], a);
        put_back(pos[b], b);
        v[pos[b]].push_back(a);
        v[pos[a]].pop_back();
        pos[a] = pos[b];
      }
    } else {
      if (cmd2 == "over") {
        put_on(pos[a], a, pos[b]);
      } else {
        put_back(pos[b], b);
        put_on(pos[a], a, pos[b]);
      }
    }
  }

  for (int i = 0; i != n; i++) {
    printf("%d:", i);
    for (int j = 0; j != v[i].size(); j++)
      printf(" %d", v[i][j]);
    printf("\n");
  }

  return 0;
}
