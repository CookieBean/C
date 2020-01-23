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

// #include <bits/stdc++.h>
// using namespace std;
// int arr[500005];
// int main() {
//   int n, m;
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) scanf("%d", arr+i);
//   scanf("%d", &m);
//   for(int i=1;i<=m;i++) {
//     int l, r, start, end;
//     scanf("%d %d", &l, &r);
//     int s = 0, e = n;
//     while(s<e) {
//       int m = (s+e)/2;
//       if(arr[m] < l) s = m+1;
//       else e = m;
//     }
//     start = s;
//     s = 0, e = n;
//     while(s<e) {
//       int m = (s+e)/2;
//       if(arr[m] > r) e = m;
//       else s = m+1;
//     }
//     end = s;
//     printf("%d\n", end - start);
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// void f(int n) {
//   if(n == 0) return;
//   printf("%d", n%10);
//   f(n/10);
//   return;
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   while(n%10 == 0) n /= 10;
//   f(n);
// }

// #include <bits/stdc++.h>
// using namespace std;
// bool flag = false;
// void f(int n) {
//   if(n == 0) return;
//   if(n%10 == 0) {
//     if(flag) {
//       printf("%d", n%10);
//     }
//   } else {
//     printf("%d", n%10);
//     flag = true;
//   }
//   f(n/10);
//   return;
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   f(n);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000];
// int main() {
//   int n, m;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) {
//     scanf("%d", &arr[i]);
//   }
//   scanf("%d", &m);
//   int i = 1;
//   while(i<=n) {
//     printf("%d ", arr[i]);
//     if(arr[i] == m) return 0;
//     i++;
//   }
// }

// #include <stdio.h>
// int n, a, b, d[1010];
// int maxi(int a, int b) {
//   int max = a;
//   for(int i=a;i<=b;i++) {
//     if(d[max] < d[i]) max = i;
//   }
//   return max;
// }
// int main()
// {
//   scanf("%d", &n);
//
//   for(int i=1; i<=n; i++)
//     scanf("%d", &d[i]);
//
//   scanf("%d%d", &a, &b);
//
//   printf("%d\n", maxi(a, b));
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000];
// int main() {
//   int n, k;
//   scanf("%d", &n);
//   int s = 1, e = n;
//   for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
//   scanf("%d", &k);
//   while(s<=e) {
//     int m = (s+e)/2;
//     printf("%d ", arr[m]);
//     if(arr[m] == k) return 0;
//     if(arr[m] > k) e = m-1;
//     else if(arr[m] < k) s = m+1;
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11][11];
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     char a, b;
//     int w;
//     scanf("\n%c %c %d", &a, &b, &w);
//     arr[a-'A'][b-'A'] = arr[b-'A'][a-'A'] = w;
//   }
//   for(int i=0;i<n;i++) {
//     for(int j=0;j<n;j++) printf("%d ", arr[i][j]);
//     printf("\n");
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[10][10], vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, ans[10][10], sym[300];
// int main() {
//   int n, top = 0;
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
//     scanf("%d", &arr[i][j]);
//     if(!arr[i][j]) sym[i*10+j] = top++;
//   }
//   for(int i=0;i<n;i++) {
//     for(int j=0;j<n;j++) {
//       if(!arr[i][j]) for(int k=0;k<4;k++) if(arr[i+vx[k]][j+vy[k]] == 0 && i+vx[k]>=0 && i+vx[k]<n && j+vy[k]>=0 && j+vy[k]<n) {
//         ans[sym[(i+vx[k])*10+j+vy[k]]][sym[10*i+j]] = ans[sym[i*10+j]][sym[(i+vx[k])*10+j+vy[k]]] = 1;
//       }
//     }
//   }
//   for(int i=0;i<top;i++) {
//     for(int j=0;j<top;j++) printf("%d ", ans[i][j]);
//     printf("\n");
//   }
// }

// #include <stdio.h>
// int arr[100][100], visited[100], n;
// int f(int node, int var, int end) {
//   if(node == end) return var;
//   int min = 100000000, i = 1;
//   for(;i<=n;i++) {
//     if(arr[node][i] && !visited[i]) {
//       visited[i] = 1;
//       if(min > f(i, var + 1, end)) min = f(i, var + 1, end);
//       visited[i] = 0;
//     }
//   }
//   return min;
// }
// int main() {
//   int m, s, e;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][y] = arr[y][x] = 1;
//   }
//   scanf("%d %d", &s, &e);
//   visited[s] = 1;
//   printf("%d", (f(s, 0, e)+1) == 100000001 ? -1 : f(s, 0, e) + 1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// queue<int> Q;
// int arr[101][101], visited[101], ans[101];
// int main() {
//   int n, m, s, e;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][y] = arr[y][x] = 1;
//   }
//   scanf("%d %d", &s, &e);
//   Q.push(s);
//   visited[s] = 1;
//   while(!Q.empty()) {
//     int x = Q.front();
//     Q.pop();
//     for(int i=1;i<=n;i++) {
//       if(arr[x][i] && !visited[i]) {
//         Q.push(i);
//         visited[i] = 1;
//         ans[i] = ans[x] + 1;
//       }
//     }
//   }
//   if(ans[e] == 0) {
//     printf("-1");
//     return 0;
//   }
//   printf("%d", ans[e]);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[100][202], visited[101], n;
// int f(int k) {
//   for(int i=0;i<arr[k][201];i++) {
//     if(!visited[arr[k][i]]) {
//       printf("%d ", arr[k][i]);
//       visited[arr[k][i]] = 1;
//       f(arr[k][i]);
//     }
//   }
// }
// int main() {
//   int m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][arr[x][201]++] = y;
//     arr[y][arr[y][201]++] = x;
//     // printf("arr[%d][%d] = %d\n", x, arr[x][201]-1, y);
//     // printf("arr[%d][%d] = %d\n", y, arr[y][201]-1, x);
//   }
//   visited[1] = 1;
//   printf("1 ");
//   f(1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101][202], visited[101];
// queue<int> Q;
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][arr[x][201]++] = y;
//     arr[y][arr[y][201]++] = x;
//   }
//   Q.push(1);
//   visited[1] = 1;
//   while(!Q.empty()) {
//     int x = Q.front();
//     Q.pop();
//     printf("%d ", x);
//     for(int i=0;i<arr[x][201];i++) {
//       if(!visited[arr[x][i]]) {
//         Q.push(arr[x][i]);
//         visited[arr[x][i]] = 1;
//       }
//     }
//   }
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[101][101], vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, visited[101][101], cnt, n, ans[1000], top = -1;
// void dfs(int x, int y) {
//   cnt++;
//   visited[x][y] = 1;
//   for(int i=0;i<4;i++) {
//     if(x+vx[i] >=1 && x+vx[i] <=n && y+vy[i] >=1 && y+vy[i] <=n && arr[x+vx[i]][y+vy[i]] && !visited[x+vx[i]][y+vy[i]]) {
//       dfs(x+vx[i], y+vy[i]);
//     }
//   }
// }
// bool cmp(int n, int m) {
//   return m<n;
// }
// int main() {
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
//   for(int i=1;i<=n;i++) {
//     for(int j=1;j<=n;j++) {
//       if(arr[i][j] == 1 && !visited[i][j]) {
//         cnt = 0;
//         dfs(i, j);
//         ans[++top] = cnt;
//       }
//     }
//   }
//   printf("%d\n", top+1);
//   sort(ans, ans+top+1, cmp);
//   for(int i=0;i<=top;i++) {
//     printf("%d\n", ans[i]);
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[12][12], visited[100], n, m, ans = INT_MAX;
// void dfs(int k, int var) {
//   if(k == n && ans > var) ans = var;
//   for(int i=1;i<=n;i++) {
//     if(arr[k][i] && !visited[i]) {
//       visited[i] = 1;
//       dfs(i, var+arr[k][i]);
//       visited[i] = 0;
//     }
//   }
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y, w;
//     scanf("%d %d %d", &x, &y, &w);
//     arr[x][y] = arr[y][x] = w;
//   }
//   visited[1] = 1;
//   dfs(1, 0);
//   if(ans == INT_MAX) {
//     printf("-1");
//     return 0;
//   }
//   printf("%d", ans);
// }

// #include <stdio.h>
// int main() {
//   int w, h, p, q, t;
//   scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);
//   printf("%d %d", ((t+p)/w)%2 ? w-(t+p)%w : (t+p)%w, ((t+q)/h)%2 ? h-(t+q)%h : (t+q)%h);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int n;
//   scanf("%d", &n);
//   int x = 1, y = 1, flag = 1, cnt = 1;
//   while(n--) {
//     // printf("%d %d\n", x, y);
//     if(flag) {
//       if(x < cnt) x++;
//       else if(y > 1) y--;
//       else {
//         if(y == 1) x++;
//         else if(x == 1) y++;
//         cnt++;
//         flag = 0;
//       }
//     } else {
//       if(y < cnt) y++;
//       else if(x > 1) x--;
//       else {
//         if(x == 1) y++;
//         else if(y == 1) x++;
//         cnt++;
//         flag = 1;
//       }
//     }
//   }
//   printf("%d %d", x, y);
// }

#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
long long brr[1005][1005];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i=1;i<=k;i++) {
    int a, b, x, y, c;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &c);
    arr[a][b] += c;
    arr[x+1][y+1] += c;
    arr[a][y+1] += -c;
    arr[x+1][b] += -c;
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      brr[i][j] = brr[i-1][j] + brr[i][j-1] - brr[i-1][j-1] + arr[i][j];
      printf("%lld ", brr[i][j]);
    }
    puts("");
  }
}
