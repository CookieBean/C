// #include <bits/stdc++.h>
// using namespace std;
// int f1(int n) {
//   int sum = 0;
//   for(int i=1;i<=n;i++) sum+=i;
//   return sum;
// }
// long long f2(int n) {
//   if(n == 1) return 1;
//   return f2(n/2)*2 + ((n+1)/2)*((n+1)/2);
// }
// int f3(int n) {
//   if(n == 1) return 1;
//   return f3(n-1) + n;
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   time_t t1, t2, t3, t4;
//   t1 = clock();
//   // printf("%d ", f1(n));
//   t2 = clock();
//   printf("%lld ", f2(n));
//   t3 = clock();
//   // printf("%d\n", f3(n));
//   t4 = clock();
//   printf("%f", (float)(t3-t2)/CLOCKS_PER_SEC);
// }

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

// #include <cstdio>
// #include <cmath>
// int f(int n, int k) {
//   if(k < 2) return n;
//   int T=(int)powf(10.0, k-1);
//   return (n%10)*T+f((n%T)/10, k-2)*10+n/T;
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%d\n", f(n, log10(n)+1));
//   return 0;
// }
//#include <bits/stdc++.h>
//using namespace std;
//char arr[10001];
//void f(int n) {
//	if(n<=0) return;
//	f(n-1);
//	arr[n] = '*';
//	printf("%s\n", arr+1);
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	f(n);
//}

//#include <bits/stdc++.h>
//using namespace std;
//char arr[10001];
//void f(int n) {
//	if(n<=0) return;
//	f(n-1);
//	arr[n] = '*';
//	puts(arr+1);
//}
//void f1(int n) {
//	if(n == 1) {
//	puts("*");
//	return;
//	}
//	f1(n-1);
//	for(int i=1;i<=n;i++) printf("*");
//	puts("");
//	return;
//}
//void f2(int n) {
//	if(n<1) return;
//	f2(n-1);
//	for(int i=1;i<=n;i++) printf("*");
//	puts("");
//	return;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	time_t start = clock();
//	f1(n);
//	time_t end = clock();
//	time_t start2 = clock();
//	f2(n);
//	time_t end2 = clock();
//	time_t start3 = clock();
//	f(n);
//	time_t end3 = clock();
//	printf("%f %f %f", (float)(end-start)/CLOCKS_PER_SEC, (float)(end2-start2)/CLOCKS_PER_SEC, (float)(end3-start3)/CLOCKS_PER_SEC);
//}

// #include <bits/stdc++.h>
// using namespace std;
// double g(int n, int k) {
//   if(k == n) return 1;
//   if(k == 1) return n;
//   return ((double)(n-k+1)/k) * g(n, k-1);
// }
// // long long h(int n, int k) {
// //   if(k == 1) return n;
// //   if(n == k) return 1;
// //   return (long long)(h(n-1, k) + h(n-1, k-1));
// // }
// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   time_t start = clock();
//   printf("%lf \n", g(n, k));
//   time_t end = clock();
//   printf("time = %f", (float)(end-start)/CLOCKS_PER_SEC);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[100005], n, m;
// int f(int n) {
//   if(n <= 1) return 1;
//   if(n%2 == 0) return (((f(n/2)%m)*(f(n/2)%m)) + 2*((f(n/2-1)%m)*(f(n/2-1)%m)))%m;
//   else return (((f(n/2)%m)*(f(n/2+1)%m)) + 2*((f(n/2-1)%m)*(f(n/2)%m)))%m;
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   time_t start = clock();
//   arr[0] = arr[1] = 1;
//   for(int i=2;i<=n;i++) {
//     arr[i] = (arr[i-1] + 2*arr[i-2])%m;
//   }
//   printf("%d\n", f(n));
//   time_t end = clock();
//   printf("%d\n", arr[n]);
//   printf("time : %f", (float)(end-start)/CLOCKS_PER_SEC);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1<<7][1<<7], gray, white;
// void f(int s, int e, int var) {
//   int x = arr[s][e], y = arr[s][e];
//   if(x) {
//     for(int i=s;i<=var;i++) for(int j=e;j<=var;j++) x = x & arr[i][j];
//   } else {
//     for(int i=s;i<=var;i++) for(int j=e;j<=var;j++) x = x | arr[i][j];
//   }
//   if(x == y) {
//     if(x) {
//       white++;
//       return;
//     } else {
//       gray++;
//       return;
//     }
//   }
//   f(s, e, var/2);
//   f(s+var/2, e, var/2);
//   f(s, e+var/2, var/2);
//   f(s+var/2, e+var/2, var/2);
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", &arr[i][j]);
//   f(1, 1, n);
//   printf("gray : %d, white : %d", gray, white);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   FILE* in = fopen("./asdf/input.txt", "r");
//   FILE* out = fopen("output.txt", "w");
//   int n;
//   fscanf(in, "%d", &n);
//   fprintf(out, "%d", n);
//   fclose(in);
//   fclose(out);
// }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> S;
// int t = -1;
// void f(int n, int top) {
//   // printf("f : %d %d\n", n, top);
//   if(n == 0) {
//     for(auto iter = S.begin();iter != S.end();iter++) printf("%d ", *iter);
//     puts("");
//     return;
//   } else if(n < 0) return;
//   for(int i=n;i>=top;i--) {
//     S.push_back(i);
//     f(n-i, i);
//     S.pop_back();
//   }
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   f(n, 1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1305][1305], n, m;
// int f(int k, int lim) {
//   // printf("%d %d\n", k, lim);
//   if(k == 0) return 1;
//   if(k < lim) return 0;
//   if(arr[k][lim]) return arr[k][lim];
//   int sum = 0;
//   for(int i=lim;i<=m;i++) sum += f(k-i, i), sum %= 123456789;
//   return arr[k][lim] = sum;
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) arr[0][i] = 1;
//   for(int i=1;i<=n;i++) {
//     for(int k=1;k<=m;k++) {
//       int sum = 0;
//       for(int j=k;j<=m && i>=j;j++) {
//         sum += arr[i-j][j];
//       }
//       arr[i][k] = sum;
//     }
//   }
//   for(int i=1;i<=n;i++) {
//     for(int j=1;j<=m;j++) printf("%d ", arr[i][j]);
//     puts("");
//   }
//   printf("%d", arr[n][m]);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[11], dp[10005];
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) scanf("%d", &arr[i]);
//   dp[0] = 1;
//   for(int j=0;j<=n;j++) {
//     if(dp[j]) {
//       for(int k=1;k<=m;k++) {
//         if((dp[j+arr[k]] == 0 || dp[j+arr[k]] > dp[j]) && j+arr[k] <= n) dp[j+arr[k]] = dp[j] + 1;
//       }
//     }
//   }
//   printf("%d", dp[n]-1);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n, m;
// int f(int x, int y) {
//   if(x > n) return 0;
//   if(y > m) return 0;
//   int sum = 0;
//   // printf("%d %d\n", x, y);
//   if(x == n && y == m) return 1;
//   if((float)(y+1)/x <= (float)m/n) sum += f(x, y+1);
//   if((float)(y)/(x+1) <= (float)m/n) sum += f(x+1, y);
//   return sum;
// }
// int main() {
//   scanf("%d %d", &n, &m);
//   printf("%d", f(1, 0));
// }

#include <bits/stdc++.h>
using namespace std;
int f(int x, int y) {
  if(x == 1) {
    if(y == 0) return 1;
    else return 0;
  }
  if(x == 2) {
    if(y == 1 || y == 0) return 1;
    else return 0;
  }
  return f(x-2, y-1) + f(x-1, y);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d", f(n, m));
}
