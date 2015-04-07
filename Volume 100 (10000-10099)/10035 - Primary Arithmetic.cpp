#include <cstdio>
#include <cstring>

int main() {
    char n1[12], n2[12];

    while(scanf("%s%s", n1, n2) != EOF) {
        if(strcmp(n1, "0") == 0 && strcmp(n2, "0") == 0)
            break;

        int l1 = strlen(n1) - 1;
        int l2 = strlen(n2) - 1;

        int ans = 0;
        int last = 0;
        for(; l1 >=0 || l2 >= 0; l1--, l2--) {
            int num1 = 0, num2 = 0;
            if(l1 >= 0)
                num1 = n1[l1] - '0';
            if(l2 >= 0)
                num2 = n2[l2] - '0';
            if(last + num1 + num2 >= 10) {
                ans++;
                last = 1;                
            } else {
                last = 0;
            }
        }
        if(ans == 0)
            printf("No carry operation.\n");
        else if(ans == 1)
            printf("%d carry operation.\n", ans);
        else
            printf("%d carry operations.\n", ans);
    }

    return 0;
}