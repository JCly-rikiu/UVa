#include <cstdio>
#include <cstring>

int main()
{
    bool first = true;
    char c;
    while(true)
    {
        c = getchar();
        if(c == EOF)
            break;

        if(c == '\"')
        {
            if(first)
            {
                printf("%s", "``");
                first = false;
            }
            else
            {
                printf("%s", "''");
                first = true;
            }
            continue;
        }
        printf("%c", c);
    }

    return 0;
}