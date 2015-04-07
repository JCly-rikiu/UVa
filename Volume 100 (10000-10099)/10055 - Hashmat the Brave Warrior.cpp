#include <cstdio>

long long int abs(long long int n)
{
    if(n < 0)
        return -n;
    return n;
}

int main()
{
    long long int a, b;
    while(scanf("%lld%lld", &a, &b) != EOF)
        printf("%lld\n", abs(a - b));

    return 0;
}