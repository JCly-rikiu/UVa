#include <cstdio>

int abs(int num)
{
    if(num < 0)
        return -num;
    return num;
}

int main()
{
    bool flag[3010];
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n - 1; i++)
            flag[i] = false;

        bool is_jolly = false;
        int now, last;
        scanf("%d", &last);
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &now);
            int buf = abs(now - last);
            if(flag[buf])
                is_jolly = true;
            else
                flag[buf] = true;
            last = now;
        }

        if(is_jolly)
            printf("Not jolly\n");
        else
            printf("Jolly\n");
    }

    return 0;
}