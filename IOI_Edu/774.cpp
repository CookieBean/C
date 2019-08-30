#include <stdio.h>
#include <algorithm>
int arr[300005];
int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", &arr[i]);
  std::sort(arr, arr+n);
  int i = n-1;
  while(arr[n-1]+1>=arr[i]+n-1 && i>=0) i--;
  printf("%d", i);
}
