#include <stdio.h>

int main(void) {
  FILE *f = fopen("../input", "r");
  if (f == NULL) {
    return 1;
  }

  int c;
  int floor = 0;

  while ((c = fgetc(f)) != EOF) {
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
  }

  printf("%d\n", floor);
  fclose(f);
  return 0;
}
