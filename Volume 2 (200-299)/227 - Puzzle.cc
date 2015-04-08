#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Pos {
  int x, y;
} space;

map<char, int> way;
const int wayx[] = { -1, 1, 0, 0};
const int wayy[] = { 0, 0, 1, -1};

int main() {
  way['A'] = 0;
  way['B'] = 1;
  way['R'] = 2;
  way['L'] = 3;

  int T = 1;
  while (true) {
    bool flag = false;

    string puzzle[5];
    for (int i = 0; i != 5; i++) {
      while (puzzle[i].length() == 0)
        getline(cin, puzzle[i]);
      if (puzzle[i] == "Z") {
        flag = true;
        break;
      }

      int pos = puzzle[i].find(" ");
      if (pos != -1) {
        space.x = i;
        space.y = pos;
      }
    }

    if (flag)
      break;

    string cmd;
    string buf;
    cin >> buf;
    cmd += buf;
    while (buf[buf.length() - 1] != '0') {
      cin >> buf;
      cmd += buf;
    }

    bool invalid = false;
    for (int i = 0; i != cmd.length() - 1; i++) {
      int now = way[cmd[i]];
      Pos buf;
      buf.x = space.x + wayx[now];
      buf.y = space.y + wayy[now];

      if (buf.x < 0 || buf.x > 4 || buf.y < 0 || buf.y > 4) {
        invalid = true;
        break;
      }

      swap(puzzle[space.x][space.y], puzzle[buf.x][buf.y]);
      space = buf;
    }

    if (T != 1)
      printf("\n");
    printf("Puzzle #%d:\n", T++);
    if (invalid) {
      printf("This puzzle has no final configuration.\n");
    } else {
      for (int i = 0; i != 5; i++) {
        for (int j = 0; j != 5; j++) {
          printf("%c%c", puzzle[i][j], j == 4 ? '\n' : ' ');
        }
      }
    }
  }

  return 0;
}