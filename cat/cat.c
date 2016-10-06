#include <stdio.h>

void filecopy (FILE *fp) {
  int c;

  while ((c = getc(fp)) != EOF) {
    putc(c, stdout);
  }
}

int main (int argc, char const *argv[]) {
  FILE *fp;

  if (argc == 1) {
    filecopy(stdin);
  } else {
    while (--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s\n", "errrrrooorrrrr");
        return 1;
      } else {
        filecopy(fp);
      }
    }
  }
  return 0;
}
