#include <stdio.h>
int f(long long int a) {
  if(!a) return 0;
  return f(a/10)+a%10;
}
int main() {
  long long int n;
  scanf("%lld", &n);
  printf("%d\n", f(n));
}
