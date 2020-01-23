// #include <bits/stdc++.h>
// using namespace std;
// int arr[200];
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   for(int i=1;i<=n;i++) scanf("%d", arr+i);
//   int s = 1, e = n+1;
//   while(s < e) {
//     int m = (s+e)/2;
//     if(arr[m] >= k) {
//       e = m;
//     } else {
//       s = m+1;
//     }
//   }
//   printf("%d\n", s);
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000005];
// int main() {
//   int n, t;
//   scanf("%d %d", &n, &t);
//   for(int i=1;i<=n;i++) scanf("%d", arr+i);
//   for(int i=1;i<=t;i++) {
//     int s = 1, e = n+1, k;
//     scanf("%d", &k);
//     while(s < e) {
//       int m = (s+e)/2;
//       if(arr[m] > k) {
//         e = m;
//       } else {
//         s = m+1;
//       }
//     }
//     printf("%d\n", s);
//   }
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[200];
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   for(int i=1;i<=n;i++) scanf("%d", arr+i);
//   int s = 1, e = n+1;
//   while(s < e) {
//     int m = (s+e)/2;
//     if(arr[m] >= k) {
//       e = m;
//     } else if(arr[m] < k) {
//       s = m+1;
//     }
//   }
//   if(arr[s] == k) printf("%d\n", s);
//   else printf("-1");
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[500005];
// int main() {
//   int n, t;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) scanf("%d", arr+i);
//   scanf("%d", &t);
//   for(int i=1;i<=t;i++) {
//     int s, e, k, t, tmp;
//     scanf("%d %d", &k, &t);
//     s = 1, e = n+1;
//     while(s < e) {
//       int m = (s+e)/2;
//       if(arr[m] < k) {
//         s = m+1;
//       } else {
//         e = m;
//       }
//     }
//     tmp = s;
//     s = 1, e = n+1;
//     while(s < e) {
//       int m = (s+e)/2;
//       if(arr[m] <= t) {
//         s = m+1;
//       } else {
//         e = m;
//       }
//     }
//     printf("%d\n", s-tmp);
//   }
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[101];
// int main() {
//   int n, k;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
//   scanf("%d", &k);
//   for(int i=1;i<=n;i++) {
//     printf("%d ", arr[i]);
//     if(arr[i] == k) return 0;
//   }
// }
//
// int maxi(int a, int b) {
//   int max = a;
//   for(int i=a;i<=b;i++) {
//     if(d[max] < d[i]) max = i;
//   }
//   return max;
// }
//
// #include <bits/stdc++.h>
// using namespace std;
// int arr[200];
// int main() {
//   int n, k;
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
//   scanf("%d", &k);
//   int s = 0, e = n-1;
//   while(s<e) {
//     int m = (s+e)/2;
//     printf("%d ", arr[m]);
//     if(arr[m] < k) s = m+1;
//     else if(arr[m] == k) {
//       return 0;
//     }
//     else e = m-1;
//   }
//   if(arr[s] == k) printf("%d", arr[s]);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11][11];
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     char a, b;
//     scanf(" %c %c", &a, &b);
//     arr[a-'A'][b-'A'] = 1;
//   }
//   for(int i=0;i<n;i++) {
//     for(int j=0;j<n;j++) printf("%d ", arr[i][j]);
//     puts("");
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
//     int c;
//     scanf(" %c %c %d", &a, &b, &c);
//     arr[a-'A'][b-'A'] = arr[b-'A'][a-'A'] = c;
//   }
//   for(int i=0;i<n;i++) {
//     for(int j=0;j<n;j++) printf("%d ", arr[i][j]);
//     puts("");
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[6][6], vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, ans[100][100], cnt;
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &arr[i][j]);
//   for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
//     if(!arr[i][j]) {
//       cnt++;
//       for(int k=0;k<4;k++) {
//         if(i+vx[k] >= 0 && i+vx[k] < n && j+vy[k] >= 0 && j+vy[k] < n && !arr[i+vx[k]][j+vy[k]]) {
//           ans[i*10 + j][(i+vx[k])*10 + j+vy[k]] = 1;
//         }
//       }
//     }
//   }
//   for(int i=0;i<n;i++) {
//     for(int j=0;j<n;j++) {
//       if(!arr[i][j]) {
//         for(int a=0;a<n;a++) for(int b=0;b<n;b++) if(!arr[a][b]) printf("%d ", ans[i*10 + j][a*10 + b]);
//         puts("");
//       }
//     }
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// stack<int> S;
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) {
//     int x;
//     scanf("%d", &x);
//     if(!x && !S.empty()) S.pop();
//     else S.push(x);
//   }
//   int sum = 0;
//   while(!S.empty()) {
//     sum += S.top();
//     S.pop();
//   }
//   printf("%d", sum);
// }

// #include <bits/stdc++.h>
// using namespace std;
// stack<int> S;
// int main() {
//   int n;scanf("%d", &n);
//   while(n) {
//     S.push(n%2);
//     n /= 2;
//   }
//   if(S.empty()) {
//     printf("0");
//   }
//   while(!S.empty()) {
//     printf("%d", S.top());
//     S.pop();
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11][11], visited[11], n;
// void dfs(int m) {
//   for(int i=0;i<n;i++) {
//     if(arr[m][i] && !visited[i]) {
//       visited[i] = 1;
//       printf("%c ", i+'A');
//       dfs(i);
//     }
//   }
// }
// int main() {
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &arr[i][j]);
//   visited[0] = 1;
//   printf("A ");
//   dfs(0);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11][11], n, m, s, e, visited[11];
// int dfs(int k) {
//   // printf("dfs : %d\n", k);
//   if(k == s) return 1;
//   for(int i=1;i<=n;i++) {
//     if(arr[k][i] && !visited[i]) {
//       visited[i] = 1;
//       if(int t = dfs(i)) {
//         printf("%d ", i);
//         return t;
//       }
//     }
//   }
//   return 0;
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][y] = arr[y][x] = 1;
//   }
//   scanf("%d %d", &s, &e);
//   visited[e] = 1;
//   dfs(e);
//   printf("%d", e);
// }

// #include <bits/stdc++.h>
// using namespace std;
// stack<char> S;
// int main() {
//   char arr[100];
//   scanf("%s", arr);
//   for(int i=0;arr[i];i++) {
//     if(arr[i] == '+' || arr[i] == '-') {
//       while(!S.empty()) {
//         printf("%c", S.top());
//         S.pop();
//       }
//       S.push(arr[i]);
//     } else if(arr[i] == '/' || arr[i] == '*') {
//         while(!S.empty() && ((S.top() == '*') || (S.top() == '/'))) {
//           printf("%c", S.top());
//           S.pop();
//         }
//         S.push(arr[i]);
//     } else {
//         printf("%c", arr[i]);
//     }
//   }
//   while(!S.empty()) {
//     printf("%c", S.top());
//     S.pop();
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[100][100];
// int main() {
//   int n, ind = 0;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) {
//     char x, y;
//     scanf(" %c %c", &x, &y);
//     arr[x-'A'][y-'A'] = arr[y-'A'][x-'A'] = 1;
//   }
//   int max = 0;
//   for(int i=0;i<100;i++) {
//     int sum = 0;
//     for(int j=0;j<100;j++) sum += arr[i][j];
//     if(max < sum) {
//       ind = i;
//       max = sum;
//     }
//   }
//   printf("%c", ind+'A');
// }

// #include <bits/stdc++.h>
// using namespace std;
// queue<int> Q;
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=n;i++) Q.push(i);
//   for(int i=1;i<=n;i++) {
//     for(int j=1;j<m;j++) {
//       Q.push(Q.front());
//       Q.pop();
//     }
//     printf("%d ", Q.front());
//     Q.pop();
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101][101], visited[11], n;
// queue<int> Q;
// int main() {
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &arr[i][j]);
//   Q.push(0);
//   visited[0] = 1;
//   while(!Q.empty()) {
//     printf("%c ", Q.front()+'A');
//     for(int i=0;i<n;i++) {
//       if(arr[Q.front()][i] && !visited[i]) {
//         Q.push(i);
//         visited[i] = 1;
//       }
//     }
//     Q.pop();
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101][101], visited[11], n, m, s, e;
// queue<int> Q;
// int main() {
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
//     if(Q.front() == e) {
//       puts("Yes");
//       return 0;
//     }
//     for(int i=1;i<=n;i++) {
//       if(arr[Q.front()][i] && !visited[i]) {
//         Q.push(i);
//         visited[i] = 1;
//       }
//     }
//     Q.pop();
//   }
//   puts("No");
//   return 0;
// }

// #include <stdio.h>
// int arr[101][101], visited[11], n, m, s, e, ans = 100;
// void dfs(int k, int cnt) {
//   if(k == e && ans > cnt) ans = cnt;
//   for(int i=1;i<=n;i++) {
//     if(arr[k][i] && !visited[i]) {
//       visited[i] = 1;
//       dfs(i, cnt+1);
//       visited[i] = 0;
//     }
//   }
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][y] = arr[y][x] = 1;
//   }
//   scanf("%d %d", &s, &e);
//   visited[s] = 1;
//   dfs(s, 1);
//   if(ans != 100) printf("%d", ans);
//   else puts("-1");
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101][101], visited[101];
// queue<int> Q;
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
//     for(int i=1;i<=n;i++) {
//       if(arr[Q.front()][i] && !visited[i]) {
//         visited[i] = visited[Q.front()] + 1;
//         Q.push(i);
//       }
//     }
//     Q.pop();
//   }
//   if(visited[e]) printf("%d", visited[e]-1);
//   else puts("-1");
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11][12], n, m, visited[11];
// void dfs(int k) {
//   for(int i=0;i<arr[k][11];i++) {
//     if(!visited[arr[k][i]]) {
//       visited[arr[k][i]] = 1;
//       printf("%d ", arr[k][i]);
//       dfs(arr[k][i]);
//     }
//   }
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][arr[x][11]++] = y;
//     arr[y][arr[y][11]++] = x;
//   }
//   visited[1] = 1;
//   printf("%d ", 1);
//   dfs(1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// queue<int> Q;
// int arr[11][12], visited[11], n, m;
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     int x, y;
//     scanf("%d %d", &x, &y);
//     arr[x][arr[x][11]++] = y;
//     arr[y][arr[y][11]++] = x;
//   }
//   Q.push(1);
//   visited[1] = 1;
//   while(!Q.empty()) {
//     printf("%d ", Q.front());
//     for(int i=0;i<arr[Q.front()][i];i++) {
//       if(!visited[arr[Q.front()][i]]) {
//         visited[arr[Q.front()][i]] = 1;
//         Q.push(arr[Q.front()][i]);
//       }
//     }
//     Q.pop();
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[31][31], n, m, visited[31][31], ans[1000], top, vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, cnt;
// int dfs(int x, int y) {
//   cnt++;
//   visited[x][y] = 1;
//   for(int i=0;i<4;i++) {
//     if(x+vx[i] > 0 && x+vx[i] <=n && y+vy[i] > 0 && y+vy[i] <=n && !visited[x+vx[i]][y+vy[i]] && arr[x+vx[i]][y+vy[i]]) {
//       dfs(x+vx[i], y+vy[i]);
//     }
//   }
// }
// bool cmp(int n, int m) { return n > m; }
// int main() {
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
//   for(int i=1;i<=n;i++) {
//     for(int j=1;j<=n;j++) {
//       if(!visited[i][j] && arr[i][j]) {
//         cnt = 0;
//         dfs(i, j);
//         ans[top++] = cnt;
//       }
//     }
//   }
//   printf("%d\n", top);
//   sort(ans, ans+top, cmp);
//   for(int i=0;i<top;i++) {
//     printf("%d\n", ans[i]);
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101];
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   for(int i=0;i<n;i++) scanf("%d", &arr[i]);
//   int s = 0, e = n;
//   while(s < e) {
//     int m = (s+e)/2;
//     if(arr[m] < k) {
//       s = m+1;
//     } else e = m;
//   }
//   printf("%d", s+1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000005];
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
//   for(int j=1;j<=m;j++) {
//     int x;
//     scanf("%d", &x);
//     int s = 1, e = n+1;
//     while(s < e) {
//       int m = (s+e)/2;
//       if(arr[m] <= x) s = m+1;
//       else e = m;
//     }
//     printf("%d ", s);
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[101];
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
//   int s = 1, e = n;
//   while(s < e) {
//     int m = (s+e)/2;
//     if(arr[m] < k) s = m+1;
//     else e = m;
//   }
//   if(arr[s] == k) printf("%d", s);
//   else puts("-1");
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[500005];
// int main() {
//   int n, t, k;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
//   scanf("%d", &t);
//   for(int i=1;i<=t;i++) {
//     int x, y, tmp;
//     scanf("%d %d", &x, &y);
//     int s = 1, e = n+1;
//     while(s<e) {
//       int m = (s+e)/2;
//       if(arr[m] < x) s = m+1;
//       else e = m;
//     }
//     tmp = s;
//     s = 1, e = n+1;
//     while(s<e) {
//       int m = (s+e)/2;
//       if(arr[m] <= y) s = m+1;
//       else e = m;
//     }
//     printf("%d\n", s-tmp);
//   }
// }
