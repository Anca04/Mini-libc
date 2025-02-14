#include <errno.h>
#include <internal/syscall.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int nanosleep(const struct timespec *t1, struct timespec *t2) {
  int result = syscall(35, t1, t2);

  if (result < 0) {
    errno = -result;
    return -1;
  }

  return 0;
}
