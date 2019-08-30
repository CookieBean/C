#include <bits/stdc++.h>
using namespace std;
int p[100001], n, m, ans = 0;
int arr[2001][2001], vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1};
typedef struct point {
  int x;
  int y;
} Point;
queue<Point> Q, U;
int find(int n) {
  if(n == p[n]) return n;
  return p[n] = find(p[n]);
}
bool can(int x, int y) {
  return (x>=1 && x<=n && y>=1 && y<=n);
}
void bfs_spread() {
  while(!Q.empty()) {
    Point cor = Q.front();
    Q.pop();
    int x = cor.x; int y = cor.y;
    for(int i=0;i<4;i++) {
      if(!can(x+vx[i], y+vy[i])) continue;
      if(arr[x+vx[i]][y+vy[i]]) {
        int af = find(arr[x][y]); int bf = find(arr[x+vx[i]][y+vy[i]]);
        if(af != bf) {
          p[af] = bf;
          m--;
        }
      } else {
        arr[x+vx[i]][y+vy[i]] = arr[x][y];
        Point tmp = {x+vx[i], y+vy[i]};
        U.push(tmp);
      }
    }
  }
}
void bfs_find() {
  while(!U.empty()) {
    Point cor = U.front();
    Q.push(cor);
    U.pop();
    int x = cor.x; int y = cor.y;
    for(int i=0;i<4;i++) {
      int af = find(arr[x][y]), bf = find(arr[x+vx[i]][y+vy[i]]);
      if(arr[x+vx[i]][y+vy[i]] && (af != bf) && can(x+vx[i], y+vy[i])) {
        p[af] = bf;
        m--;
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i=1;i<=m;i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    arr[x][y] = i;
    p[i] = i;
    Point tmp = {x, y};
    U.push(tmp);
  }
  while(m>1) {
    bfs_find();
    if(m<=1) {
      printf("%d", ans);
      return 0;
    }
    bfs_spread();
    ans++;
  }
  printf("%d", ans);
}
