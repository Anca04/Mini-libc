// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <unistd.h>

int open(const char *filename, int flags, ...) {
  /* TODO: Implement open system call. */
  int file_open;
  va_list args;
  va_start(args, flags);

  if (flags & O_CREAT) {
    mode_t mode = va_arg(args, mode_t);
    file_open = syscall(2, filename, flags, mode);
  } else {
    file_open = syscall(2, filename, flags);
  }
  va_end(args);

  if (file_open < 0) {
    errno = -file_open;
    return -1;
  }

  return file_open;
}
