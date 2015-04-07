#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    int now = 1;
    while(t--) {
        int a, b;
        scanf("%d%d", &a, &b);

        if((a & 1) == 0)
            a++;
        int ans = 0;
        for(int i = a; i <=b; i += 2)
            ans += i;

        printf("Case %d: %d\n", now++, ans);
    }

    return 0;
}