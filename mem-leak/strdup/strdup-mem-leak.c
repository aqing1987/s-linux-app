/**
 * strdup without free leads to mem leak
 * check with 'top -p pid'
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "memleak.h"

int main(int argc, char *argv[]) {
  char *dest = NULL;

  dbg_init(10);
  dbg_catch_sigsegv();

  dest = strdup("hhll");
  free(dest);

  dbg_heap_dump("");
  dbg_mem_stat();

  if (argc == 2 && atoi(argv[1]) == 1) {
    while (1) {
      usleep(1000);
      dest = strdup("hhhhhfdfdf");
    }
  }
  
  return 0;
}
