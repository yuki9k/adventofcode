#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int total = 0;
  FILE *f = fopen("../input", "r");

  char line[16];
  char *token_ptr;

  while (fgets(line, sizeof line, f) != NULL) {
    int dimensions[3];
    int i = 0;

    token_ptr = strtok(line, "x");

    while (token_ptr != NULL) {
      dimensions[i] = atoi(token_ptr);
      token_ptr = strtok(NULL, "x");
      i++;
    }

    int length = dimensions[0];
    int width = dimensions[1];
    int height = dimensions[2];
    int smallest = dimensions[2] * dimensions[0];

    for (int i = 1; i < 3; i++) {
      if (dimensions[i] * dimensions[i - 1] < smallest) {
        smallest = dimensions[i] * dimensions[i - 1];
      }
    }

    total += 2 * length * width + 2 * width * height + 2 * height * length +
             smallest;

    i = 0;
  }

  printf("%d\n", total);
  fclose(f);
  return 0;
}
