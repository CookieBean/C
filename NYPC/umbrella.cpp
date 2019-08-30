#include <bits/stdc++.h>
using namespace std;
int arr[20];
int main() {
  int n, m, cur, ans = 0;
  scanf("%d %d %d", &n, &m, &cur);
  for(int i=1;i<=m;i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if(y == 1) {
      if(arr[cur] >= 1) {
        arr[cur]--;
        // printf("치워짐 %d\n", cur);
      } else ans++;
      arr[x]++;
      // printf("보관됨 %d\n", x);
    }
    cur = x;
  }
  printf("%d", ans);
}
