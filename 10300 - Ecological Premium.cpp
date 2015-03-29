#include <cstdio>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        while(n--) {
            int f;
            scanf("%d", &f);

            int ans = 0;
            for(int i = 0; i < f; i++) {
                int size, number, ef;
                scanf("%d%d%d", &size, &number, &ef);

                ans += size * ef;
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}