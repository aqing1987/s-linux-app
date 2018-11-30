#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t g_tid;

#define handle_error_en(en, msg) \
  do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void* t_func(void* ignore) {
  (void)ignore;

  int s;

  s = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  if (s)
    handle_error_en(s, "pthread_setcancelstate");

  printf("thread_func: started;\n");

  // the cancellation point
  while (1)
    ;

  // should never get here
  printf("thread: not canceled!\n");
  return NULL;
}

static void test() {
  pthread_attr_t attr;
  int err;

  printf("tid: %d\n", (int)g_tid);

  if (g_tid) {
    // cancel
    printf("test(): sending cancellation request\n");
    int s;
    s = pthread_cancel(g_tid);
    if (s)
      handle_error_en(s, "pthread_cancel");

    g_tid = 0;
  }

  printf("test(): create thread\n");
  pthread_attr_init(&attr);
  pthread_attr_setstacksize(&attr, 64*1024);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  err = pthread_create(&g_tid, &attr, t_func, NULL);
  if (err) {
    handle_error_en(err, "Failed starting thread.");
  }

  printf("tid: %d\n", (int)g_tid);
  
  pthread_attr_destroy(&attr);
}

int main(int argc, char *argv[]) {

  test();

  sleep(5);

  printf("test again!\n");

  test();

  // give thread a chance to get started
  sleep(2);

  return 0;
}
