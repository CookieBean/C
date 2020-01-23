#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005], ans = INT_MAX, visited[1005][1005];
int vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, n, m;
struct str {
  int x, y, cnt;
};
str t;
int f(int k) {
  queue<str> Q;
  str t = {1, 1, 1};
  Q.push(t);
  while(!Q.empty()) {
    str a;
    // printf("%d %d %d\n", a.x, a.y, a.cnt);
    a = Q.front();
    Q.pop();
    if(a.x == n && a.y == m) {
      if(ans > a.cnt) ans = a.cnt;
      break;
    }
    int x = a.x, y = a.y;
    for(int i=0;i<4;i++) {
      if(arr[x+vx[i]][y+vy[i]] == 2 && k != visited[x+vx[i]][y+vy[i]]) {
        visited[x+vx[i]][y+vy[i]] = k;
        str b;
        b.x = x+vx[i], b.y = y+vy[i], b.cnt = a.cnt+1;
        Q.push(b);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++) {
    char brr[1005];
    scanf("%s", brr);
    for(int j=0;j<m;j++) {
      if(brr[j] == '0') arr[i][j+1] = 2;
      else if(brr[j] == '1') arr[i][j+1] = 1;
    }
  }
  int k = 0;
  t = {1, 1, 1};
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      if(arr[i][j] == 1) {
        arr[i][j] = 2;
        visited[1][1] = k+1;
        k++;
        f(k);
        arr[i][j] = 1;
      }
    }
  }
  if(ans == INT_MAX) {
    printf("-1");
    return 0;
  }
  printf("%d", ans);
}
