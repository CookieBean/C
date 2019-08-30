// #include <stdio.h>
// int D[1005][1005];
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   for(int i=1;i<=1000;i++){
//     D[i][1]=i;
//     D[i][0]=1;
//   }
//   for(int i=3;i<=n;i++){
//     for(int j=1;j<=k;j++){
//       D[i][j] = (D[i-1][j]+D[i-2][j-1])%1000000003;
//     }
//   }
//   printf("%d",(D[n-3][k-1]+D[n-1][k])%1000000003);
// }

#include <bits/stdc++.h>
int D[1001][1001][2];
int n, k;
int f(int a, int b, bool t) {
  if(b == k || a >= n) {
    if(a > n && !t && b == k) return 1;
    else if(a == n && b == k) return 1;
    else if(b == k && a<n) return 1;
    else return 0;
  } else if(D[a][b][t] != -1) return D[a][b][t];
  D[a][b][t] = 0;
  D[a][b][t] = (D[a][b][t] + f(a+2, b+1, t))%1000000003;
  D[a][b][t] = (D[a][b][t] + f(a+1, b, t))%1000000003;
  return D[a][b][t];
}
int main() {
  memset(D, -1, sizeof(D));
  scanf("%d %d", &n, &k);
  printf("%d", (f(1, 0, false) + f(2, 1, true))%1000000003);
}
