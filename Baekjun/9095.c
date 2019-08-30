#include <stdio.h>
int f(int k) {
  if(k==0) return 1;
  else if(k<0) return 0;
  return f(k-1) + f(k-2) + f(k-3);
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    int k;
    scanf("%d", &k);
    printf("%d\n", f(k));
  }
}
