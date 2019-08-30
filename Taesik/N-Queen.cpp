#include <stdio.h>
int column[10];
int up[20];
int down[20];
int n, cnt;
void dfs(int x, int y) {
  if(y>=n) {
    cnt++; return;
  }
  column[x] = 1; up[x+y] = 1; down[x-y+n] = 1;
  for(int i=1;i<=n;i++) if(!column[i] && !up[i+y+1] && !down[i-y-1+n]) dfs(i, y+1);
  column[x] = 0; up[x+y] = 0; down[x-y+n] = 0;
}
int main() {
  scanf("%d", &n);
  for(int i=1;i<=n;i++) dfs(i, 1);
  printf("%d", cnt);
}
