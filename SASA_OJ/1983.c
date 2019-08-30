#include <stdio.h>
int main() {
  int n, i = 0;
  scanf("%d", &n);
  while(n>0) {
    i++;
    if(n%2 == 1) printf("%d\n", i);
    n/=2;
  }
}
