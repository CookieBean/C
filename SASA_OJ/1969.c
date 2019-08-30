#include <stdio.h>
char arr[12][6], visited[12][6], vx[4] = {1, -1, 0, 0}, vy[4] = {0, 0, 1, -1}, cnt=0, k=0, sum=0, count=0; // 이거 문제가 한번 웨이브에 여러개가 동시에 터지면 그건 체인이 아님!!!
void g(int n) {
  for(int i=11;i>0;i--) if(arr[i][n]=='.'&&arr[i-1][n]!='.') {
    while(i>=1) arr[i+1][n] = arr[--i][n];
    arr[0][n]='.';
    i=12;
  }
}
void f(int x, int y, char z) {
  if(visited[x][y]!=k&&arr[x][y] == z&&z!='.') {
    visited[x][y] = k;
    cnt++;
    for(int i=0;i<=3;i++) if(x+vx[i]>=0&&x+vx[i]<=11&&y+vy[i]>=0&&y+vy[i]<=5) f(x+vx[i], y+vy[i], z);
  }
}
int main() {
  for(int i=0;i<12;i++) for(int j=0;j<6;j++) scanf(" %c", &arr[i][j]);
  for(int i=0;i<12;i++) {
    for(int j=0;j<6;j++) {
      cnt = 0;
      k++;
      f(i, j, arr[i][j]);
      if(cnt>=4) {
        for(int a=0;a<12;a++) for(int b=0;b<6;b++) {
          if(visited[a][b] == k) arr[a][b] = '.';
          visited[a][b] = 0;
        }
        count++;
      }
    }
    if(i == 11&&count>0) {
      sum++;
      count = 0;
      for(int a=0;a<6;a++) g(a);
      i = -1;
    }
  }
  printf("%d\n", sum);
}
