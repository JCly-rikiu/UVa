#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);

        int ans = 0;
        for(int j = 0; j < n; j++) {
            int buf;
            scanf("%d", &buf);

            if(buf > ans)
                ans = buf;
        }

        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}