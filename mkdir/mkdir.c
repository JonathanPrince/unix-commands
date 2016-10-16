#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  int result = 0;
  int i = 1;

  if (argc == 1) {
    fprintf(stderr, "Directory name was not specified.\n");
    result = -1;
  }

  while (i < argc) {
    result = mkdir(argv[i], 0777);

    if (result != 0) {
      fprintf(stderr, "Error: '%s' %s\n", argv[i], strerror(errno));
    }
    i++;
  }

  return result;
}
