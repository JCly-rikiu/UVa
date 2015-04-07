#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int l;
        scanf("%d", &l);

        int train[60];
        int ans = 0;
        for(int i = 0; i < l; i++) {
            scanf("%d", train + i);
            for(int j = 0; j < i; j++)
                if(train[j] > train[i])
                    ans++;
        }
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}