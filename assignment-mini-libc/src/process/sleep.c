#include <errno.h>
#include <time.h>
#include <unistd.h>

unsigned sleep(unsigned seconds) {
  struct timespec req, rem;
  req.tv_sec = seconds;
  req.tv_nsec = 0;

  while (nanosleep(&req, &rem) < 0) {
    if (errno == EINTR) {
      req = rem;
    } else {
      return seconds;
    }
  }

  return 0;
}
