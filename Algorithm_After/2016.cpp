#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005], ans = INT_MAX, visited[1005][1005][2];
int vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, n, m;
struct str {
  int x, y, opp, cnt;
};
queue<str> Q;
int main() {
  for(int i=0;i<1005;i++) for(int j=0;j<1005;j++) arr[i][j] = -1;
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++) {
    char brr[1005];
    scanf("%s", brr);
    for(int j=0;j<m;j++) {
      if(brr[j] == '0') arr[i][j+1] = 0;
      else if(brr[j] == '1') arr[i][j+1] = 1;
    }
  }
  str t = {1, 1, 1, 1};
  visited[1][1][1] = 1;
  visited[1][1][0] = 1;
  Q.push(t);
  while(!Q.empty()) {
    str a;
    a = Q.front();
    Q.pop();
    if(a.x == n && a.y == m) {
      if(ans > a.cnt) ans = a.cnt;
      break;
    }
    int x = a.x, y = a.y;
    for(int i=0;i<4;i++) {
      if(arr[x+vx[i]][y+vy[i]] == 0 && !visited[x+vx[i]][y+vy[i]][a.opp]) {
        visited[x+vx[i]][y+vy[i]][a.opp] = 1;
        str b;
        b.x = x+vx[i], b.y = y+vy[i], b.opp = a.opp, b.cnt = a.cnt+1;
        Q.push(b);
      } else if(arr[x+vx[i]][y+vy[i]] == 1 && !visited[x+vx[i]][y+vy[i]][a.opp] && a.opp == 1) {
        str b;
        visited[x+vx[i]][y+vy[i]][a.opp] = 1;
        b.x = x+vx[i], b.y = y+vy[i], b.opp = 0, b.cnt = a.cnt+1;
        Q.push(b);
      }
    }
  }
  if(ans == INT_MAX) {
    printf("-1");
    return 0;
  }
  printf("%d", ans);
}
