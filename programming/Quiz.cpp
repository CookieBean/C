#include <bits/stdc++.h>
using namespace std;
long long arr[1001][1001];
long long f(int k, int x) {
  if(x == 0) return 1;
  if(k < x) return 0;
  if(arr[k][x] != -1) return arr[k][x];
  return arr[k][x] = (f(k-1, x) + f(k-2, x-1))%1000000003;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(arr, -1, sizeof(arr));
  printf("%lld", (f(n-1, m) + f(n-3, m-1))%1000000003);
}
