#include <cstdio>
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000010;
const int MAXTEAM = 1010;

int teamID[MAXN];

int main() {
  int T = 1;
  int t;
  while (scanf("%d", &t) != EOF) {
    if (t == 0)
      break;

    queue<int> team[MAXTEAM];
    for (int i = 0; i != t; i++) {
      int n;
      scanf("%d", &n);

      for (int j = 0; j != n; j++) {
        int id;
        scanf("%d", &id);

        teamID[id] = i;
      }
    }

    printf("Scenario #%d\n", T++);

    queue<int> q;
    string cmd;
    while (cin >> cmd) {
      if (cmd[0] == 'S')
        break;

      if (cmd[0] == 'E') {
        int id;
        scanf("%d", &id);

        if (team[teamID[id]].empty())
          q.push(teamID[id]);
        team[teamID[id]].push(id);
      } else {
        int now = q.front();
        printf("%d\n", team[now].front());
        team[now].pop();
        if (team[now].empty())
          q.pop();
      }
    }
    printf("\n");
  }

  return 0;
}
