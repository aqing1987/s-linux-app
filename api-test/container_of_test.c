#include <stdio.h>

#define offset(type, member) ((size_t) &((type *)0)->member)
#define container_of(ptr,type,member)  ({ \
        const typeof(((type*)0)->member) *_mptr=(ptr);\
        (type*)((char*)_mptr-offset(type,member));\
})

struct test_struct {
  int num;
  char ch;
};

int main() {
  struct test_struct *ts;
  struct test_struct ts_1 = {12, 'b'};
  char* ptr_ch = &ts_1.ch;

  ts = container_of(ptr_ch, struct test_struct, ch);

  printf("num = %d\n", ts->num);
  printf("ch = %c\n", ts->ch);
    
  return 0;
}
