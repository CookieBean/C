// #include <bits/stdc++.h>
// using namespace std;
// int arr[100005], tree[131073], brr[100005], n, chk = 1;
// void insert(int k, int var) {
//   if(k == 1) tree[1] = max(tree[1], var);
//   if(tree[k] < var) tree[k] = var, insert(k/2, var);
//   else return;
// }
// int find(int l, int r, int s, int e, int node) {
//   if(r < s || l > e) return 0;
//   else if(l <= s && e <= r) return tree[node];
//   else return max(find(l, r, s, (s+e)/2, node*2), find(l, r, (s+e)/2+1, e, node*2+1));
// }
// int main() {
//   scanf("%d", &n);
//   while(chk < n) chk*=2;
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]), brr[i] = arr[i];
//   sort(arr, arr+n);
//   for(int i=0;i<n;i++) {
//     int j;
//     for(j=0;j<n;j++) if(arr[i] == brr[j]) break;
//     // printf("%d번째 : arr[%d] = %d, %d\n", i, i, arr[i], j);
//     insert(chk+j, find(1, j, 1, n, 1)+1);
//     // for(int j=1;j<=16;j++) printf("%d ", tree[j]);
//     // puts("");
//   }
//   printf("%d", tree[1]);
// }

// #include <bits/stdc++.h>
// using namespace std;
// struct cow {
//   int index, value, seen, see;
// };
// struct cow arr[160005];
// stack<struct cow> S;
// int main() {
//   int n;
//   long long sum = 0, minimum = LLONG_MAX, maximum = -1, m = 1;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) {
//     int x;
//     scanf("%d", &x);
//     arr[i] = {i, x, 0, 0};
//     arr[i+n] = {i+n, x, 0, 0};
//     if(arr[m].value < arr[i].value) m = i;
//   }
//   for(int k=m;k<=m+n-1;k++) {
//     struct cow x = arr[k];
//     while(!S.empty() && S.top().value <= x.value) {
//       arr[S.top().index].see = k-S.top().index-1;
//       S.pop();
//     }
//     arr[k].seen = S.size();
//     sum += S.size();
//     S.push(x);
//   }
//   while(!S.empty()) {
//     arr[S.top().index].see = m+n-1-S.top().index;
//     S.pop();
//   }
//   maximum = sum;
//   for(int i=m;i<=m+n-1;i++) {
//     // printf("a : %d %d\n", arr[i].see, arr[i].seen);
//   }
//   for(int i=m+n-1;i>=m;i--) {
//     sum += arr[i].see - arr[i].seen;
//     // printf("sum : %lld\n", sum);
//     if(minimum > sum) minimum = sum;
//   }
//   printf("%lld %lld", maximum, minimum);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1005][1005];
// int main() {
//   int n, m, q;
//   scanf("%d %d %d", &n, &m, &q);
//   for(int i=1;i<=q;i++) {
//     int a, b, x, y, k;
//     scanf("%d %d %d %d %d", &a, &b, &x, &y, &k);
//     for(int j=a;j<=x;j++) {
//       arr[j][b] += k;
//       arr[j][y+1] += -k;
//     }
//   }
//   long long sum = 0;
//   for(int i=1;i<=n;i++) {
//     for(int j=1;j<=m;j++) printf("%d ", arr[i][j]);
//     sum += arr[i][m]
//     puts("");
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int w, h, x, y, a, b, t;
//   scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);
//   printf("%d %d", ((x+t)/w)%2?w-((x+t)%w):(x+t)%w, ((y+t)/h)%2?h-((y+t)%h):(y+t)%h);
// }

// #include <bits/stdc++.h>
// using namespace std;
// stack<char> S;
// char arr[100005];
// int ans;
// int main() {
//   scanf("%s", arr);
//   int flag = 0;
//   for(int i=0;arr[i];i++) {
//     if(flag == 1 && arr[i] == ')') {
//       S.pop();
//       // printf("%d %d\n", i, S.size());
//       ans += S.size();
//       flag = 0;
//       continue;
//     }
//     if(arr[i] == '(') flag = 1, S.push(')');
//     else flag = 0, S.pop(), ans++;
//   }
//   printf("%d", ans);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1048577], ans = INT_MAX;
// void dfs(int k, int cnt) {
//   // printf("%d\n", k);
//   if(k == 0) {
//     if(cnt < ans) ans = cnt;
//     return;
//   }
//   int j = k;
//   j = k - (k%4) + 3-k%4;
//   if(!arr[j]) {
//     arr[j] = 1;
//     dfs(j, cnt+1);
//   }
//   // printf("passed\n");
//   for(int i=0;i<18;i++) {
//     int n = k;
//     n -= ((n>>i)%8)<<i;
//     n += (7-(n>>i)%8)<<i;
//     printf("n : %d, %d, %d\n", n, ((n>>i)%8)<<i, (7-(n>>i)%8)<<i);
//     if(!arr[n]) {
//       arr[n] = 1;
//       dfs(n, cnt+1);
//     }
//   }
// }
// int main() {
//   int n = 0;
//   for(int i=1;i<=20;i++) {
//     int x;
//     scanf("%d", &x);
//     n = n<<1;
//     n += x;
//   }
//   printf("%d\n", n);
//   arr[n] = 1;
//   dfs(n, 0);
//   printf("%d", ans);
// }
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d")
}
