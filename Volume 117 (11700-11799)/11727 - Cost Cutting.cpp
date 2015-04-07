#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int c = 1; c <= t; c++) {
        int salary[3];
        for(int i = 0; i < 3; i++)
            scanf("%d", salary + i);

        sort(salary, salary + 3);

        printf("Case %d: %d\n", c, salary[1]);
    }

    return 0;
}