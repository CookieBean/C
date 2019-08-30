#include <stdio.h>
#include <algorithm>
int arr[32][32];
int ans[32];
bool visited[32][32];
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
int dfs(int x, int y) {
  int sum = 0;
  visited[x][y] = true;
  for(int i=0;i<4;i++) if(!visited[x+vx[i]][y+vy[i]] && arr[x+vx[i]][y+vy[i]]) sum+=dfs(x+vx[i], y+vy[i]);
  return sum + arr[x][y];
}
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      if(arr[i][j] && !visited[i][j]) ans[++cnt] = dfs(i, j);
    }
  }
  printf("%d\n", cnt);
  std::sort(ans+1, ans+cnt);
  for(int i=1;i<=cnt;i++) printf("%d\n", ans[i]);
}
