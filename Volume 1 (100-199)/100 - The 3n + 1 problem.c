#include <stdio.h>

int f(int);

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        printf("%d %d",a,b);
        if(a > b)
        {
            int c = a;
            a = b;
            b = c;
        }
        int max = 0;
        int i;
        for(i=a;i<=b;i++)
        {
            int v = f(i);
            if(max < v)
                max = v;
        }
        printf(" %d\n",max);
    }

    return 0;
}

int f(int n)
{
    if(n==1) return 1;
    if(n%2==1) return f(3*n+1)+1;
    if(n%2==0) return f(n/2)+1;
}
