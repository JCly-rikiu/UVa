#include <cstdio>
#include <cstring>

int n, m;
int ans[110][110];
int mx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int my[] = {1, 0, -1, 0, 1, -1, 1, -1};

void init() {
    for(int i = 0; i < 110; i++)
        for(int j = 0; j < 110; j++)
            ans[i][j] = 0;
    return ;
}

void set(int x, int y) {
    ans[x][y] = -1;
    for(int i = 0; i < 8; i++) {
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] != -1)
            ans[nx][ny]++;
    }

    return ;
}

int main() {
    int t = 1;
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0)
            break;

        init();
        for(int i = 0; i < n; i++) {
            char buf[110];
            scanf("%s", buf);
            int len = strlen(buf);
            for(int j = 0; j < len; j++)
                if(buf[j] == '*')
                    set(i, j);
        }

        if(t != 1)
            printf("\n");
        printf("Field #%d:\n", t++);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ans[i][j] == -1)
                    printf("*");
                else
                    printf("%d", ans[i][j]);
            }
            printf("\n");
        }   
    }

    return 0;
}