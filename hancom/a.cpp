#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, p, q;
int vx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, vy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int visited[101][101];
queue<int> Q;
int chk(int x, int y) {
  return x >= 1 && y >= 1 && x <= n && y <= m;
}
int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &p, &q);
  Q.push(1000*x + y);
  visited[x][y] = 1;
  while(!Q.empty()) {
    int k = Q.front();
    Q.pop();
    for(int i=0;i<8;i++) {
      if(chk((k/1000)%1000+vx[i], k%1000+vy[i]) && !visited[(k/1000)%1000+vx[i]][k%1000+vy[i]]) {
        int tmp = ((k/1000)%1000+vx[i])*1000 + (k%1000+vy[i]) + (k/1000000+1)*1000000;
        if((tmp/1000)%1000 == p && tmp%1000 == q) {
          printf("%d", tmp/1000000);
          return 0;
        }
        visited[(k/1000)%1000+vx[i]][k%1000+vy[i]] = 1;
        Q.push(tmp);
      }
    }
  }
}
