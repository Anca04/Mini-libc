// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
  /* TODO: Implement strcpy(). */
  char *d;
  for (d = destination; *source != '\0'; source++, d++) *d = *source;

  *d = *source;
  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  /* TODO: Implement strncpy(). */
  size_t i;
  for (i = 0; i < len && source[i] != '\0'; i++) destination[i] = source[i];

  while (i < len) {
    destination[i] = '\0';
    i++;
  }

  return destination;
}

char *strcat(char *destination, const char *source) {
  /* TODO: Implement strcat(). */
  size_t i, j;
  for (i = 0; destination[i] != '\0'; i++) {
    ;
  }

  for (j = 0; source[j] != '\0'; j++) destination[i + j] = source[j];

  destination[i + j] = '\0';
  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  /* TODO: Implement strncat(). */
  size_t i, j;
  for (i = 0; destination[i] != '\0'; i++) {
    ;
  }

  for (j = 0; j < len && source[j] != '\0'; j++) destination[i + j] = source[j];
  destination[i + j] = '\0';

  return destination;
}

int strcmp(const char *str1, const char *str2) {
  /* TODO: Implement strcmp(). */
  size_t i = 0;
  while (str1[i] == str2[i]) {
    if (str1[i] == '\0' || str2[i] == '\0') break;
    i++;
  }

  if (str1[i] == '\0' && str2[i] == '\0')
    return 0;
  else
    return str1[i] - str2[i];

  return -1;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  /* TODO: Implement strncmp(). */
  size_t i = 0;
  size_t j = 0;

  while (j == len && str1[i] == str2[i]) {
    if (str1[i] == '\0' || str2[i] == '\0') break;
    i++;
    j++;
  }

  if (str1[i] == '\0' && str2[i] == '\0')
    return 0;
  else
    return str1[i] - str2[i];

  return -1;
}

size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++) {
    ;
  }

  return i;
}

char *strchr(const char *str, int c) {
  /* TODO: Implement strchr(). */

  while (*str != '\0' && *str != c) str++;
  if (*str == c) return (char *)str;

  return NULL;
}

char *strrchr(const char *str, int c) {
  /* TODO: Implement strrchr(). */
  char *ret = 0;
  while (*str != '\0') {
    if (*str == c) ret = (char *)str;
    str++;
  }

  if (ret != 0) return ret;
  return NULL;
}

char *strstr(const char *haystack, const char *needle) {
  /* TODO: Implement strstr(). */
  char *h, *n;
  if (*needle == '\0') return (char *)haystack;

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      h = (char *)haystack;
      n = (char *)needle;

      while (*h != '\0' && *n != '\0' && *h == *n) {
        h++;
        n++;
      }

      if (*n == '\0') return (char *)haystack;
    }
    haystack++;
  }
  return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  /* TODO: Implement strrstr(). */
  char *h, *n;
  char *result = 0;
  if (*needle == '\0') return (char *)haystack;

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      h = (char *)haystack;
      n = (char *)needle;

      while (*h != '\0' && *n != '\0' && *h == *n) {
        h++;
        n++;
      }

      if (*n == '\0') result = (char *)haystack;
    }
    haystack++;
  }

  if (result != 0) return result;
  return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
  /* TODO: Implement memcpy(). */
  size_t i;
  char *tmp_source = (char *)source;
  char *tmp_destination = (char *)destination;

  for (i = 0; i < num; i++) tmp_destination[i] = tmp_source[i];
  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  /* TODO: Implement memmove(). */
  size_t i;
  char *tmp_source = (char *)source;
  char *tmp_destination = (char *)destination;
  char buffer[1000];

  for (i = 0; i < num; i++) buffer[i] = tmp_source[i];
  for (i = 0; i < num; i++) tmp_destination[i] = buffer[i];

  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  /* TODO: Implement memcmp(). */
  char *tmp_ptr1 = (char *)ptr1;
  char *tmp_ptr2 = (char *)ptr2;
  int result = 0;

  if (ptr1 == ptr2) return 0;

  while (num--) {
    if (*tmp_ptr1 != *tmp_ptr2) {
      if (*tmp_ptr1 > *tmp_ptr2)
        result = 1;
      else
        result = -1;
      break;
      (*tmp_ptr1)++;
      (*tmp_ptr2)++;
    }
  }

  return result;
}

void *memset(void *source, int value, size_t num) {
  /* TODO: Implement memset(). */
  char *tmp = (char *)source;

  while (num--) {
    *tmp++ = value;
  }

  return source;
}
