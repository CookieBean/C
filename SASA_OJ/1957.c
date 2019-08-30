#include <stdio.h>
int arr[11][11], visited[11][11], r, c, cnt = 0, vx[4] = {1, -1, 0, 0}, vy[4] = {0, 0, 1, -1}, sum, tc;
void f(int a, int b, int col) {
  visited[a][b] = 1;
  for(int i = 0; i<4; i++) {
    if(a+vx[i]>=0 && a+vx[i]<r && b+vy[i]>=0 && b+vy[i]<c && arr[a+vx[i]][b+vy[i]] == col && !visited[a+vx[i]][b+vy[i]]) {
      visited[a+vx[i]][b+vy[i]] = 1;
      f(a+vx[i], b+vy[i], col);
      sum++;
    }
  }
}
int main() {
  scanf("%d %d", &r, &c);
  for(int i = 0; i<r; i++) for(int j = 0; j<c; j++) scanf("%d", &arr[i][j]);
  for(int i = 0; i<r; i++) for(int j = 0; j<c; j++) {
      sum = 1;
      if(!visited[i][j]) f(i, j, arr[i][j]);
      if(sum>=3 && cnt<sum) {
        cnt = sum;
        tc = arr[i][j];
      }
    }
  if(cnt == 0) {
    printf("0");
    return 0;
  }
  printf("%d %d\n", tc, cnt);
}
