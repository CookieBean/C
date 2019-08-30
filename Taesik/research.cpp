#include <bits/stdc++.h>
using namespace std;
int arr[31][31];
int visited[31], n, m;
void f(int a) {
  for(int i=1;i<=n;i++) {
    if(arr[a][i]) {
      if(visited[i] > arr[a][i] + visited[a]) {
        visited[i] = arr[a][i] + visited[a];
        f(i);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i=1;i<=m;i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    arr[a][b] = arr[b][a] = w;
  }
  for(int i=1;i<=n;i++) visited[i] = INT_MAX;
  visited[1] = 0;
  f(1);
  if(visited[n]+1 == 0) {
    puts("-1");
    return 0;
  }
  printf("%d", visited[n]);
}
