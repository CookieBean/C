#include <stdio.h>
int arr[101];
int min = 100;
int main() {
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    scanf("%d", &arr[i]);
  }
  for(int i=1;i<=n;i++) {
    int k;
    scanf("%d", &k);
    if(k) if(min>arr[i]/k) min = arr[i]/k;
  }
  printf("%d", min);
  return 0;
}
