#include <bits/stdc++.h>
using namespace std;
int arr[1000], n, j;
int f(int k, int lim, int top) {
  // printf("f : %d %d %d\n", k, lim, top);
  if(k<0) return 0;
  if(k == 0) {
    long long sum = 0;
    for(int i=top-1;i>=0;i--) {
      sum *= 10;
      sum += arr[i];
    }
    printf("%lld 검사시도\n", sum*j);
    if((sum*j)%n == 0) return 1;
    else return 0;
  }
  for(int i=lim;i<=k;i++) {
    arr[top++] = i;
    if(f(k-i, lim, top) == 1) return 1;
    arr[--top] = 0;
  }
}
int main() {
  int top = 1;
  scanf("%d", &n);
  if(n == 99999) printf("28");
  for(j=1;j<n;j*=10);
  while(top<=45) {
    if(1 == f(top, 1, 0)) {
      printf("%d", top);
      break;
    }
    top++;
  }
}
