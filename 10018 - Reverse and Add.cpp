#include <cstdio>
#include <cstring>

bool is_p(long long num) {
    char str[15];
    sprintf(str, "%lld", num);

    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

long long add(long long num) {
    char s1[15];
    sprintf(s1, "%lld", num);
    char s2[15];
    int len = strlen(s1);
    for(int i = 0; i < len; i++) {
        s2[i] = s1[len - i - 1];
    }
    s2[len] = '\0';

    long long newn;
    sscanf(s2, "%lld", &newn);

    return num + newn;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        long long n;
        scanf("%lld", &n);

        int times = 0;
        while(1) {
            if(is_p(n)) break;
            times++;
            n = add(n);
        }

        printf("%d %lld\n", times, n);
    }

    return 0;
}