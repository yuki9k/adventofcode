#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareInt(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

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

    qsort(dimensions, 3, sizeof(int), compareInt);
    int n = dimensions[0];
    int m = dimensions[1];
    int k = dimensions[2];

    int wrap = 2 * (n + m);
    int bow = n * m * k;
    total += wrap + bow;
  }

  printf("%d\n", total);
  fclose(f);
  return 0;
}
