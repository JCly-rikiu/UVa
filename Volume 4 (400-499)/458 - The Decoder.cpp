#include <cstdio>
#include <cstring>

int main()
{
    char input[100000];
    while(scanf("%s", input) != EOF)
    {
        for(int i = 0; i < strlen(input); i++)
            printf("%c", input[i] - 7);
        printf("\n");
    }

    return 0;
}