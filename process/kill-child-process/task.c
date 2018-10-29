#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // exit - cause normal process termination
  // The exit() function causes normal process termination and the
  // value of status & 0377 is returned to the parent.

  if (argc != 2) {
    exit(9);
  }

  int val = 0;
  val = atoi(argv[1]);

  if (val == 1) {
    while (1) ;
  } else if (val == 2) {
    exit(2);
  } else {
    exit(3);
  }

  return 0;
}


