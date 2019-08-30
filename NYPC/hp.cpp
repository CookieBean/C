#include <stdio.h>
int main() {
  int h, t, max_hp = 0;
  scanf("%d %d", &h, &t);
  for(int i=1;i<=t;i++) {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 1) {
      if(h-m > 0) h -= m;
    } else if(n == 2) {
      h += m;
    } else if(!max_hp) {
      max_hp = h+m;
      h += m;
    }
  }
  printf("%d", max_hp);
}
