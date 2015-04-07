#include <cstdio>

int perfect(int num) {
    int sum = 0;
    for(int i = 1; i < num; i++)
        if(num % i == 0) 
            sum += i;

   return sum;
}

int main() {
    printf("PERFECTION OUTPUT\n");
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)
            break;

        int result = perfect(n);
        if(result > n)
            printf("%5d  ABUNDANT\n", n);
        else if(result == n)
            printf("%5d  PERFECT\n", n);
        else
            printf("%5d  DEFICIENT\n", n);
    }
    printf("END OF OUTPUT\n");

    return 0;
}