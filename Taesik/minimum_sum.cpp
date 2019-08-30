#include <bits/stdc++.h>
using namespace std;
int D[11], arr[11][11], visited[10], n, m = INT_MAX;
void dfs(int a, int col, int ans) {
  if(ans>m) return;
  if(col == n && ans<m) m = ans;
  D[a] = 1;
  for(int i=1;i<=n;i++) {
    if(D[i] == 0) dfs(i, col+1, ans+arr[col+1][i]);
  }
  D[a] = 0;
}
int greedy(int col) {
  if(col>n) return 0;
  int k = INT_MAX, idx;
  for(int i=1;i<=n;i++) {
    if(!visited[i] && k>arr[col][i]) {
      k = arr[col][i];
      idx = i;
    }
  }
  visited[idx] = 1;
  return greedy(col+1) + k;
}
int main() {
  scanf("%d", &n);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
  m = greedy(1);
  for(int i=1;i<=n;i++) dfs(i, 1, arr[1][i]);
  printf("%d", m);
}
