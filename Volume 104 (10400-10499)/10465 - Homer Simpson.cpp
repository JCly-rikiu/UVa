#include <cstdio>
#include <cstring>

int burger[10005];
int utime[10005];

void dp(int n, int t)
{
    for(int i = n; i <= t; i++)
    {
        if(utime[i] < utime[i - n] + n)
        {
            utime[i] = utime[i - n] + n;
            burger[i] = burger[i - n] + 1;
        }
    }
}

int main()
{
    int t, m, n;
    while(scanf("%d%d%d", &m, &n, &t) != EOF)
    {
        memset(burger, 0, sizeof(burger));
        memset(utime, 0, sizeof(utime));

        if(m < n)
        {
            dp(m, t);
            dp(n, t);
        }
        else
        {
            dp(n, t);
            dp(m, t);
        }

        if(utime[t] == t)
            printf("%d\n", burger[t]);
        else
            printf("%d %d\n", burger[utime[t]], t - utime[t]);
    }

    return 0;
}