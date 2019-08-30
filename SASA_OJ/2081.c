#include <stdio.h>
int main() {
  int a, b, c, n;
  scanf("%d %d %d %d", &a, &b, &c, &n);
  for(int i=0;i<=n/c;i++) for(int j=0;j<=(n-i*c)/b;j++) if(!((n-i*c-b*j)%a)) {
      puts("1");
      return 0;
  }
  puts("0");
}
