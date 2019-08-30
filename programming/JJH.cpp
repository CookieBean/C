// #include <bits/stdc++.h>
// using namespace std;
// int arr[105];
// int main() {
//   int n, k, s = 0, e;
//   scanf("%d %d", &n, &k);
//   e = n;
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
//   while(s<e) {
//     int m = (s+e)/2;
//     if(arr[m] < k) s = m+1;
//     else e = m;
//   }
//   printf("%d", s+1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000005];
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
//   for(int j=0;j<m;j++) {
//     int s = 0, e = n, k;
//     scanf("%d", &k);
//     while(s<e) {
//       int m = (s+e)/2;
//       if(arr[m] > k) e = m;
//       else s = m+1;
//     }
//     printf("%d ", s+1);
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[105];
// int main() {
//   int n, k, s = 0, e;
//   scanf("%d %d", &n, &k);
//   e = n;
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
//   while(s<e) {
//     int m = (s+e)/2;
//     if(arr[m] < k) s = m+1;
//     else e = m;
//   }
//   if(arr[s] == k) printf("%d", s+1);
//   else printf("-1");
// }

#include <bits/stdc++.h>
using namespace std;
int arr[500005];
int main() {
  int n, m;
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", arr+i);
  scanf("%d", &m);
  for(int i=1;i<=m;i++) {
    int l, r, start, end;
    scanf("%d %d", &l, &r);
    int s = 0, e = n;
    while(s<e) {
      int m = (s+e)/2;
      if(arr[m] < l) s = m+1;
      else e = m;
    }
    start = s;
    s = 0, e = n;
    while(s<e) {
      int m = (s+e)/2;
      if(arr[m] > r) e = m;
      else s = m+1;
    }
    end = s;
    printf("%d\n", end - start);
  }
}
