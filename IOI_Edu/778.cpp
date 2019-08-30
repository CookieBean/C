#include <stdio.h>
int arr[1000001];
int main() {
  int n, maxi;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n>m) if(maxi<n) maxi = n;
    else if(maxi<m) maxi = m;
    for(int j=n+1;j<m;j++) arr[j]++;
  }
  int max = 0;
  for(int i=1;i<=maxi;i++) {
    if(max<arr[i]) max = arr[i];
  }
  printf("%d", max);
}
