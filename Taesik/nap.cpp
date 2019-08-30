#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000], ans;
int main() {
  int n, m, w, h;
  scanf("%d %d %d %d", &n, &m, &w, &h);
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
    int k;
    scanf("%d", &k);
    arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1] + k;
  }
  for(int i=w;i<=n;i++) for(int j=h;j<=m;j++) {
    int sum = arr[i][j] - arr[i-w][j] - arr[i][j-h] + arr[i-w][j-h];
    if(sum > ans) ans = sum;
  }
  printf("%d", ans);
}
