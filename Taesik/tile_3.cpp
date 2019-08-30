#include <bits/stdc++.h>
using namespace std;
int F[40];
int main() {
  int n;
  scanf("%d", &n);
  if(n%2||n==0) {
    printf("0");
    return 0;
  }
  F[4] = 11;
  F[2] = 3;
  F[0] = 1;
  for(int i=3;i<=n/2;i++) {
    F[i*2] += 3*F[i*2-2];
    for(int j=i*2-4;j>=0;j-=2) {
      F[i*2] += 2*F[j];
    }
  }
  printf("%d", F[n]);
}
