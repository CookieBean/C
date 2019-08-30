#include <stdio.h>
int vx[4] = {1, 0, -1, 0};
int vy[4] = {0, 1, 0, -1};
int arr[1001][1001];
int main() {
  int n, k, cnt = 0, x = 1, y = 1, d = 0;
  scanf("%d %d", &n, &k);
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[i][j] = -1;
  while(1) {
    arr[x][y] = ++cnt;
    if(arr[x][y] == k) break;
    if(arr[x+vx[d]][y+vy[d]] != -1) d = (d+1)%4;
    x += vx[d];
    y += vy[d];
  }
  printf("%d %d", x, y);
}
