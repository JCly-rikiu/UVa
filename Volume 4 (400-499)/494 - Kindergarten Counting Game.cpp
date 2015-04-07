#include <cstdio>
#include <cstring>

int main()
{
    while(1)
    {
        char input[1000];
        if(fgets(input, 1000, stdin) == 0)
            break;

        int len = strlen(input);
        
        int cnt = 0;
        bool letter = false;
        for(int i = 0; i < len; i++)
        {
            if((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))
                letter = true;
            else if(letter)
            {
                letter = false;
                cnt++;
            }
        }

        if(letter)
            cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}