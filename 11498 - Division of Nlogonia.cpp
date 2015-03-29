#include <cstdio>

int main() {
    int k;
    while(scanf("%d", &k) != EOF) {
        if(k == 0)
            break;

        int n, m;
        scanf("%d%d", &n, &m);
        
        for(int i = 0; i < k; i++) {
            int x, y;
            scanf("%d%d", &x, &y);

            x -= n;
            y -= m;

            if(x == 0 || y == 0)
                printf("divisa\n");
            else if(x > 0) {
                if(y > 0)
                    printf("NE\n");
                else
                    printf("SE\n");
            }
            else {
                if(y > 0)
                    printf("NO\n");
                else
                    printf("SO\n");
            }
        } 
    }

    return 0;
}