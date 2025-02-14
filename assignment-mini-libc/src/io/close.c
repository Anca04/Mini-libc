// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int close(int fd) {
  /* TODO: Implement close(). */
  int file_close = syscall(3, fd);

  if (file_close < 0) {
    errno = -file_close;
    return -1;
  }

  return file_close;
}
