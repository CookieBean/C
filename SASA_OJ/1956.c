#include <stdio.h>
int arr[11][11], vx[4]={1, -1, 0, 0}, vy[4]={0, 0, 1, -1}, visited[11][11], sum = 0, cnt, r, c;
void f(int x, int y, int col) {
  if(arr[x][y] == col && visited[x][y] == 0) {
    cnt++;
    visited[x][y] = 1;
    for(int i = 0; i<=3; i++) if(x+vx[i]>=0 && x+vx[i]<r && y+vy[i]>=0 && y+vy[i]<c) f(x+vx[i], y+vy[i], col);
  }
}
int main() {
  scanf("%d %d", &r, &c);
  for(int i = 0; i<r; i++) for(int j = 0; j<c; j++) scanf("%d", &arr[i][j]);
  for(int i = 0; i<r; i++) for(int j = 0; j<c; j++) {
    cnt = 0;
    f(i, j, arr[i][j]);
    if(cnt>=3) sum++;
  }
  printf("%d\n", sum);
}
