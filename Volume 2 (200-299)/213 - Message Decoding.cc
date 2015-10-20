#include <cstdio>

int readchar() {
  char ch;
  do {
    ch = getchar();
  } while (ch == '\n');
  
  return ch - '0';
}

int main() {
  char header[10000];
  while (true) {
    if (fgets(header, 100000, stdin) == 0)
      break;

    while (true) {
      int len = 0;
      for (int i = 0; i != 3; i++)
        len = len * 2 + readchar();
      if (len == 0)
        break;

      int start = 1, end = 1;
      for (int i = 0; i != len; i++)
        end *= 2;
      end = end - 1;
      start = end - len;

      while (true) {
        int num = 0;
        for (int i = 0; i != len; i++)
          num = num * 2 + readchar();
        if (num == end)
          break;

        printf("%c", header[start + num]);
      }
    }
    printf("\n");
    getchar();
  }

  return 0;
}