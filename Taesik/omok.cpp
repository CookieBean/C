#include <bits/stdc++.h>
using namespace std;
int arr[30][30];
int vx[4] = {1, 0, 1, 1};
int vy[4] = {0, 1, 1, -1};
int dfs(int a, int b, int stone) {
  for(int i=0;i<4;i++) {
    int x = a, y = b, cnt = 1;
    if(arr[x-vx[i]][y-vy[i]] == stone) continue;
    while(arr[x+vx[i]][y+vy[i]] == stone) {
      cnt++;
      x += vx[i];
      y += vy[i];
    }
    if(cnt == 5) {
      printf("%d\n%d %d", stone, a, b);
      return 1;
    }
  }
  return 0;
}
int main() {
  memset(arr, -1, sizeof(arr));
  for(int i=1;i<=19;i++) for(int j=1;j<=19;j++) scanf("%d", &arr[i][j]);
  for(int i= 1;i<=19;i++) {
    for(int j=1;j<=19;j++) {
      if(arr[i][j]) if(dfs(i, j, arr[i][j])) return 0;
    }
  }
  printf("0");
}
