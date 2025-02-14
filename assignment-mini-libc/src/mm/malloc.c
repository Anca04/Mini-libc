// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

void *malloc(size_t size) {
  /* TODO: Implement malloc(). */
  int *result;
  int len = size + sizeof(size);

  result =
      mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

  *result = len;
  void *ret_result = (void *)(&result[1]);
  return ret_result;
}

void *calloc(size_t nmemb, size_t size) {
  /* TODO: Implement calloc(). */
  int *result;
  int len = size + sizeof(size);

  result =
      mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  return result;
}

void free(void *ptr) {
  /* TODO: Implement free(). */
  int *result = (int *)ptr;
  result--;
  munmap((void *)result, *result);
}

void *realloc(void *ptr, size_t size) {
  /* TODO: Implement realloc(). */
  memcpy(ptr, ptr, size);
  if (ptr == NULL) {
    return NULL;
  }

  return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  /* TODO: Implement reallocarray(). */
  size_t total_size = nmemb * size;
  void *new_ptr = realloc(ptr, total_size);

  return new_ptr;
}
