// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset) {
  /* TODO: Implement mmap(). */
  if (flags & MAP_ANONYMOUS) {
    fd = -1;
  } else {
    errno = EBADF;
    return MAP_FAILED;
  }

  if (!(flags & (MAP_PRIVATE | MAP_SHARED))) {
    errno = EINVAL;
    return MAP_FAILED;
  }

  void *mmap_result = (void *)syscall(9, addr, length, prot, flags, fd, offset);
  if (mmap_result == MAP_FAILED) {
    return MAP_FAILED;
  }
  return mmap_result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
  /* TODO: Implement mremap(). */
  void *mremap_result =
      (void *)syscall(25, old_address, old_size, new_size, flags);
  if (mremap_result == MAP_FAILED) return MAP_FAILED;
  return mremap_result;
}

int munmap(void *addr, size_t length) {
  /* TODO: Implement munmap(). */
  int munmap_result = syscall(11, addr, length);
  if (munmap_result == -1) {
    errno = -munmap_result;
    return -1;
  }
  return 0;
}
