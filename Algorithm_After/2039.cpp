#include <bits/stdc++.h>
using namespace std;
queue<int> Q[100001];
queue<int> QQ;
int deep[100001], parent[100001];
int main() {
  int n, m;
  deep[1] = 0;
  scanf("%d %d", &n, &m);
  for(int i=1;i<n;i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == 1) {
      deep[y] = 1;
      parent[y] = 1;
      QQ.push(y);
    } else if(y == 1) {
      deep[x] = 1;
      parent[x] = 1;
      QQ.push(x);
    } else {
      Q[x].push(y);
      Q[y].push(x);
    }
  }
  while(!QQ.empty()) {
    int k = QQ.front();
    QQ.pop();
    while(!Q[k].empty()) {
      QQ.push(Q[k].front());
      if(deep[Q[k].front()]) {
        Q[k].pop();
        continue;
      }
      deep[Q[k].front()] = deep[k] + 1;
      parent[Q[k].front()] = k;
      Q[k].pop();
    }
  }
  for(int i=1;i<=m;i++) {
    int x, y, tx, ty;
    scanf("%d %d", &x, &y);
    tx = x, ty = y;
    while(x != y) {
      if(deep[x] >= deep[y]) x = parent[x];
      else y = parent[y];
    }

    printf("%d\n", x);
  }
}
