#include <stdio.h>
int main() {
  char a;
  int b;
  scanf("%c %d", &a, &b);
  printf("%c\n", (a+(char)b-'a')%26+'a');
  return 0;
}
