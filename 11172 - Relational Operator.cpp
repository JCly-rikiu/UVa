#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        long long a, b;
        scanf("%lld%lld", &a, &b);

        if(a < b)
            printf("<\n");
        else if(a == b)
            printf("=\n");
        else
            printf(">\n");
    }

    return 0;
}