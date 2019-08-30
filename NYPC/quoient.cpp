#include <bits/stdc++.h>
using namespace std;
long long sum;
int D[1000001];
int f(int n, int k) {
  if(D[n]) return D[n];
  int tmp = n;
  while(tmp%k == 0) tmp/=k;
  return D[n] = D[tmp]*D[n/tmp];
}
int main() {
  int a, b;
  D[1] = 1;
  scanf("%d %d", &a, &b);
  for(int i=1;i<=b;i++) D[i] = 1;
  if(a == 1) sum+=1;
  for(int i=2;i<=b;i++) {
    if(D[i] == 1) {
      int cnt = 1;
      for(int j=i;j<=b;j*=i, cnt++) for(int k=1;k*j<=b;k++) if((k*j)%(j*i)){
        D[k*j] *= cnt+1;
        // printf("D[%d] changed %d\n", k*j, D[k*j]);
      }
    }
    if(i>=a) sum+=D[i];
    if(i%1000 == 0) printf("i %d D[i] = %d\n", i, D[i]);
  }
  printf("%lld", sum);
}
