#include <stdio.h>
int a[21][21], n, cnt = 0;
int check(int ind, int len) {
  // printf("%d checking...\n", len);
  if(ind == 0) for(int i=0;i<n;i++) for(int j=0;j<=n-len;j++) {
    int k = 1;
    for(int q=j;q<j+len;q++) {
      if(a[i][q] != 'o') {
        k*=0;
        // printf("broken in a[%d][%d]\n", i, q);
        break;
      }
    }
    if(k) {
      cnt++;
      for(int q=j;q<j+len;q++) a[i][q] = 'x';
      // puts("--------");
      // for(int i=0;i<n;i++) {
      //   for(int j=0;j<n;j++) printf("%c ", a[i][j]);
      //   puts("");
      // }
    }
  } else for(int i=0;i<=n-len;i++) for(int j=0;j<n;j++) {
    int k = 1;
    for(int q=i;q<i+len;q++) {
      if(a[q][j] != 'o') {
        k*=0;
        break;
      }
    }
    if(k) {
      cnt++;
      for(int q=i;q<i+len;q++) a[q][j] = 'x';
    }
    // puts("--------");
    // for(int i=0;i<n;i++) {
    //   for(int j=0;j<n;j++) printf("%c ", a[i][j]);
    //   puts("");
    // }
  }
}
int main() {
  scanf("%d\n", &n);
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf(" %c", &a[i][j]);
  for(int i=n;i>0;i--) {
    check(0, i);
    check(1, i);
  }
  printf("%d\n", cnt);
}
