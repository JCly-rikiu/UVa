#include <cstdio>
#include <cstring>

int main() {
    char keyborad[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    char input;
    while(input = getchar()) {
        if(input == EOF)
            break;
        else if(input == ' ')
            printf(" ");
        else if(input == '\n')
            printf("\n");
        else {
            for(int i = 0; i < strlen(keyborad); i++)
                if(input == keyborad[i])
                    printf("%c", keyborad[i - 1]);
        }
    }

    return 0;
}