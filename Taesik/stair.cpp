#include <bits/stdc++.h>
using namespace std;
int memo[100];
int dfs(int n) {
  if(n == 1 || n == 0) return 1;
  if(memo[n]) return memo[n];
  return memo[n] = dfs(n-1) + dfs(n-2);;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", n);
}
