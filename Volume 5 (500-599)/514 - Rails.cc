#include <cstdio>

#include <vector>
#include <stack>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    int now;
    while (scanf("%d", &now)) {
      vector<int> v;
      if (now == 0)
        break;

      v.push_back(now);
      for (int i = 0; i != n - 1; i++) {
        scanf("%d", &now);
        v.push_back(now);
      }
      
      stack<int> s;
      int next = 0;
      for (int i = 1; i <= n; i++) {
        s.push(i);
        
        while (!s.empty() && s.top() == v[next]) {
          s.pop();
          next++;
        }
      }

      if (s.empty())
        printf("Yes\n");
      else
        printf("No\n");
    }
    printf("\n");
  }

  return 0;
}