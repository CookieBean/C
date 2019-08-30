#include <stdio.h>
int n, m;
int arr[10001];
int f(int k) {
  if(k == 1) return 1;
  else if(k == 2) return 3;
  else if(arr[k]) return arr[k];
  else {
    arr[k] = (f(k-1)+2*f(k-2))%m;
    return arr[k];
  }
}
int main() {
  scanf("%d %d", &n, &m);
  printf("%d\n", f(n));
}
