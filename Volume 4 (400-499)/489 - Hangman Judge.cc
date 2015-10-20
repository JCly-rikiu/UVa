#include <cstdio>
#include <cstring>

int main() {
  int T;
  while (scanf("%d", &T) != EOF) {
    if (T == -1)
      break;

    char str[100];
    char guess[100];
    scanf("%s%s", str, guess);

    int cnt = 0;
    bool isExist[30] = {false};
    for (int i = 0; i != strlen(str); i++) {
      if (isExist[str[i] - 'a'] == false)
        cnt++;
      isExist[str[i] - 'a'] = true;
    }

    int state = 0;
    int stroke = 0;
    for (int i = 0; i != strlen(guess); i++) {
      if (isExist[guess[i] - 'a']) {
        cnt--;
        isExist[guess[i] - 'a'] = false;
      } else {
        stroke++;
      }

      if (cnt == 0) {
        state = 2;
        break;
      }

      if (stroke >= 7) {
        state = 1;
        break;
      }
    }

    printf("Round %d\n", T);
    switch (state) {
    case 0:
      printf("You chickened out.\n");
      break;
    case 1:
      printf("You lose.\n");
      break;
    case 2:
      printf("You win.\n");
      break;
    }
  }

  return 0;
}

