#include <cstdio>

int main()
{
    int bin[3][3];
    while(true)
    {
        bool flag = false;
        for(int i = 0; i < 3; i++)
        {
            if(scanf("%d%d%d", &bin[i][0], &bin[i][1], &bin[i][2]) == EOF)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;

        int ans = 2147483647;
        int ans_n;
        char output[6][5] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
        int move[6][3] = {{0, 2, 1}, {0, 1, 2}, {2, 0, 1}, {2, 1, 0}, {1, 0, 2}, {1, 2, 0}};
        for(int i = 0; i < 6; i++)
        {
            int cnt = 0;
            for(int j = 0; j < 3; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    if(j == k)
                        continue;
                    cnt += bin[k][move[i][j]];
                }
            }
            if(ans > cnt)
            {
                ans = cnt;
                ans_n = i;
            }
        }

        printf("%s %d\n", output[ans_n], ans);
    }

    return 0;
}