#include <stdio.h>
#include <string.h>

int main() {
  long system = 0xf7e11200;
  while (memcmp(system, "/bin/sh\x00", 8)) {
    printf("%p\n", system);
    system++;
  }
  printf("/bin/sh: %p\n", system);
}
