#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int create = 1;
char *path;

int main (int argc, char *argv[]) {
  int c;
  while ((c = getopt(argc, argv, "c:")) != -1) {
    switch (c) {
      case 'c':
        create = 0;
        break;
      default:
        abort();
    }
  }

  while (optind < argc) {
    path = argv[optind];
    /* check if file exists */
    if ( access(path, F_OK) != -1) {
      printf("file %s already exists\n", path);
    } else if (create > 0) {
      int filedes = creat(path, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
      printf("created file %s with descriptor: %d\n", path, filedes);
    }
    optind++;
  }

  return 0;
}
