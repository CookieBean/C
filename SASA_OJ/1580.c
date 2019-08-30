#include <stdio.h>
void g(int n) {
  if(n<=0) return;
  g(n-1);
  printf("*");
}
void f(int n) {
  if(n<=0) return;
  f(n-1);
  g(n);
  puts("");
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  f(n);
}
