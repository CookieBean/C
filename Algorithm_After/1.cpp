#include <bits/stdc++.h>
using namespace std;
long long D[300000][4];
int arr[105];
int f(int p, int c) {
  if(p == 0) return 0;
  if(D[p][c]) return D[p][c];
  if(c == 2) return D[p][c] = f(p-1, 0);
  else return D[p][c] = max(f(p-1, 0), f(p-1, c+1) + arr[p]);
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d", f(n, 0));
}
