#include <stdio.h>
int arr[40][40], a, b, t, cnt = 0, i, j, r, c, h, w, k;
int main() {
  scanf("%d %d", &a, &b);
  scanf("%d", &t);
  for(k=0;k<t;k++) {
    scanf("%d %d %d %d", &r, &c, &h, &w);
    for(i=r;i<r+h;i++) {
      for(j=c;j<c+w;j++) {
        if(arr[i][j]) arr[i][j] = 0;
        else arr[i][j] = 1;
      }
    }
  }
  for(i=1;i<=a;i++) for(j=1;j<=b;j++) if(!arr[i][j]) cnt++;
  printf("%d\n", cnt);
}
