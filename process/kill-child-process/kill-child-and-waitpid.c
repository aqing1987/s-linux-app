#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void callhome(int choice) {
  pid_t pid;
  pid_t wret;
  int status, child_ret;

  // fork() creates a new process by duplicating the calling process.
  // The new process is referred to as the child process. The calling
  // process is referred to as the parent process.
  pid = fork();
  if (pid == -1) {
    printf("fork err, %s\n", strerror(errno));
  } else if (pid == 0) {
    // child process
    // the exec() family of functions replaces the current process
    // image with a new process image.
    if (choice == 1)
      execl("./child", "child", "1", (char*)NULL);
    else if (choice == 2)
      execl("./child", "child", "2", (char*)NULL);
  } else {
    // wait for state changes in a child of the calling process, and
    // obtain information about the child whose state has changed.
    // A state change is considered to be: the chid terminated; the
    // child was stopped by a signal; or the child was resumed by a
    // signal. In the case of a terminated child, performing a wait
    // allows the system to release the resources associated with the
    // child; if a wait is not performed, then the terminated child
    // remains in a "zombie" state.
    // The waitpid() system call suspends execution of the calling
    // process until a child specified by pid argument has changed
    // state.
    printf("child pid = %d\n", pid);
    if (choice == 1)
      printf("test with (kill -SIGTERM %d)\n", pid);

    int i = 0;
    for (i = 0, wret = -1; i < 10 && wret == -1; i++) {
      wret = waitpid(pid, &status, 0);
      printf("i = %d\n", i);
    }
    
    printf("wret = %d\n", wret);

    // returns the exit status of the child.
    child_ret = WEXITSTATUS(status);
    printf("child ret = %d\n", child_ret);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("invalid\n");
    return -1;
  }

  callhome(atoi(argv[1]));
  return 0;
}
