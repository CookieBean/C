#include <bits/stdc++.h>
using namespace std;
int f1(int n) {
  int sum = 0;
  for(int i=1;i<=n;i++) sum+=i;
  return sum;
}
long long f2(int n) {
  if(n == 1) return 1;
  return f2(n/2)*2 + ((n+1)/2)*((n+1)/2);
}
int f3(int n) {
  if(n == 1) return 1;
  return f3(n-1) + n;
}
int main() {
  int n;
  scanf("%d", &n);
  time_t t1, t2, t3, t4;
  t1 = clock();
  // printf("%d ", f1(n));
  t2 = clock();
  printf("%lld ", f2(n));
  t3 = clock();
  // printf("%d\n", f3(n));
  t4 = clock();
  printf("%f", (float)(t3-t2)/CLOCKS_PER_SEC);
}

// #include <bits/stdc++.h>
// using namespace std;
// char d[21] = "0123456789ABCDEFGHIJ";
// void f(int n, int k) {
//   if(n == 0) return;
//   f(n/k, k);
//   if(n%k > 9) printf("%c", n%k+'a'-10);
//   else printf("%d", n%k);
//   return;
// }
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   f(n, k);
// }
