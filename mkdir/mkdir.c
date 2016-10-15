#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  int i;
  if (argc == 1) {
    fprintf(stderr, "Directory name was not specified.\n");
  }
  for (i = 0; i < argc; ++i) {
    mkdir(argv[i], 0777);
  }
  return 0;
}
