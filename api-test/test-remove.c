// mkdir /tmp/xaa
// touch /tmp/xaa/1
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // man remove
  //int remove(const char *pathname);

  int ret = 0;
  // it can only remove empty directory
  ret = remove("/tmp/xaa");
  if (ret < 0) {
    printf("err: %s\n", strerror(errno));
  }
  return 0;
}
