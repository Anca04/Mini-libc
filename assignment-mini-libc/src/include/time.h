#ifndef MY_TIME_H
#define MY_TIME_H

#include <stddef.h>

typedef long time_t;
typedef long clock_t;

struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

int nanosleep(const struct timespec *t1, struct timespec *t2);
unsigned sleep(unsigned seconds);

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

#endif /* MY_TIME_H */
