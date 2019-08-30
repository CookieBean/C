#include <stdio.h>
int main() {
  int n, ans = 2, tmp = 1; // tmp is n-2 term
  scanf("%d", &n);
  for(int i=3;i<=n;i++) {
    int k = (3*ans - tmp)%12345>0 ? (3*ans - tmp)%12345 : (3*ans - tmp)%12345 + 12345;
    tmp = ans;
    ans = k;
  }
  printf("%d", ans);
}
