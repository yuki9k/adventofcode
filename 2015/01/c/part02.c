#include <stdio.h>

int main(void) {
  FILE *f = fopen("../input", "r");
  if (f == NULL) {
    return 1;
  }

  int c;
  int floor = 0;
  int pos = 1;

  while ((c = fgetc(f)) != EOF) {
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }

    if (floor == -1) {
      printf("%d\n", pos);
      break;
    }

    pos++;
  }

  // printf("%d\n", floor);
  fclose(f);
  return 0;
}
