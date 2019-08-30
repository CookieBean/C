#include <bits/stdc++.h>
using namespace std;
int arr[32][32];
int visited[32][32];
int ans[32];
int cnt;
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
queue<pair<int, int>> Q;
void bfs(int x, int y, int cnt) {
  visited[x][y] = 1;
  pair<int, int> b(x, y);
  Q.push(b);
  while(!Q.empty()) {
    pair<int, int> a = Q.front();
    Q.pop();
    ans[cnt]++;
    x = a.first; y = a.second;
    for(int i=0;i<4;i++) if(arr[x+vx[i]][y+vy[i]] && !visited[x+vx[i]][y+vy[i]]) {
      pair<int, int> b(x+vx[i], y+vy[i]);
      Q.push(b);
      visited[x+vx[i]][y+vy[i]] = 1;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(arr[i][j] && !visited[i][j]) bfs(i, j, ++cnt);
  printf("%d\n", cnt);
  for(int i=1;i<=cnt;i++) printf("%d\n", ans[i]);
}
