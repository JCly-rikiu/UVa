#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<char, char> mirror;

void mirror_init() {
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';

    return ;
}

bool is_mirrored(char* str) {
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        char buf = mirror[str[i]];
        if(buf != str[len - i - 1])
            return false;
    }
    return true;
}

bool is_palindrome(char* str) {
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main(){
    mirror_init();

    char input[100];
     while(scanf("%s", input) != EOF) {
        bool mirrored = is_mirrored(input);
        bool palindrome = is_palindrome(input);

        if(mirrored && palindrome)
            printf("%s -- is a mirrored palindrome.\n\n", input);
        else if(mirrored)
            printf("%s -- is a mirrored string.\n\n", input);
        else if(palindrome)
            printf("%s -- is a regular palindrome.\n\n", input);
        else
            printf("%s -- is not a palindrome.\n\n", input);
     }

    return 0;
}
    