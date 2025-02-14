#include <string.h>
#include <unistd.h>

int puts(const char *str) {
  if (str == NULL) return -1;
  write(1, str, strlen(str));
  write(1, "\n", 1);

  return strlen(str);
}
