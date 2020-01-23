// #include <stdio.h>
//
// int main() {
//   int a = 3;
//   int b = 4;
//   int c = 6;
//   printf("%d %d %d\n", a, b, c);
//   // b = ++(c = 6); c++에선 가능
//   // b = 1 + (c = 6); c, c++ 모두 가능
//   // v = ++c = 6; c++ 가능
//   printf("%d %d %d\n", a, b,
// }

// #include <stdio.h>
// int func() {
//   return 1;
// }
// int arr[3];
// int main() {
//   int a, b, c;
//   scanf("%d %d",&a,&b);
//   c = a + b;
//   // char* c = "%d %d";
//   // scanf(c, &a, &b);
//   printf("%d\n", arr[10]);
// }

// #include <stdio.h>
// int count[300], a[300][3][3];
// int main() {#include <bits/stdc++.h>
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

//   int n, k;
//   char m, final;
//   scanf("%d", &n);
//   scanf(" %c", &m);
//   scanf("%d", &count[m]);
//   printf("%d %d\n", m, count[m]);
//   for(int p=0;p<3;p++) {
//     for(int q=0;q<3;q++) {
//       char k;
//       scanf(" %c", &k);
//       if(k != '.') a[m][p][q] = k;
//     }
//   }
//   for(int i=0;i<3;i++) {
//     for(int j=0;j<3;j++) printf("%d ", a['p'][i][j]);
//     puts("");
//   }
// }

// #include <stdio.h>
// int a[11][11], i, j;
// int main() {
//   int n = 12;
//   while(1) {
//     printf("\a");
//   }
//   // \t는 기본이 8칸
// }

// #include <stdio.h>
// int main() {
// 	char a[1000];
// 	scanf("%[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n ]s", a);
// 	printf("%s", a);
// }
//
// #include <stdio.h>
// int main() {
// 	char a = 1;
// 	a = 1./2; // 1/2는 정수, 1./2는 실수. 즉, 이 둘을 실수에 넣어보면 차이를 바로 알 수 있다.
//
// }

// #include <stdio.h>
// int main() {
//     long double a = 1.15544;
// 		printf("%Lf\"\n", a);
// 		int b = -1/2;
// 		printf("-1/2 : %d\n", -1/2);
// 		printf("var : %d\n", b);
// 		b = 1/2;
// 		printf("1/2 : %d\n", 1/2);
// 		printf("var : %d\n", b);
// 		b = 5+4*3/2-1;
// 		printf("%d\n", (1+2, 3+4));
// 		printf("shift : %d", -8>>1);
// }

// #include <stdio.h>
// int main() {
//   int a = 5;
//   printf("%d %d\n", a++, a++); // 6 5
//   printf("%d %d\n", ++a, ++a); // 7 7
//   printf("%d %d\n", ++a, a++); // 7 5
//   printf("%d %d\n", a++, ++a); // 6 7
//   printf("%d %d %d %d\n", ++a, --a, a++, ++a);
// }

// #include <stdio.h>
// int arr[102][102], n, m, cnt = 1;
// int main() {
// 	scanf("%d %d", &n, &m);
// 	for(int i=2-n;i<=m;i++) for(int j=n;j>0;j--) if(i+n-j>=1 && i+n-j<=m) arr[j][i+n-j] = cnt++;
// 	for(int i=1;i<=n;i++) {
// 		for(int j=1;j<=m;j++) printf("%d ", arr[i][j]);
// 		puts("");
// 	}
// }
//
// #include <stdio.h>
// int arr[102][102], n, m, cnt = 0, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, x, y, d;
// int main() {
// 	scanf("%d %d", &n, &m);
// 	for(int i=0;i<n;i++) for(int j=0;j<m;j++) arr[i][j] = -1;
// 	while(cnt+1<=n*m) {
// 		arr[x][y] = ++cnt;
// 		if(arr[x+dx[d]][y+dy[d]] != -1) d = (d+1)%4;
// 		x+=dx[d];
// 		y+=dy[d];
// 	}
// 	for(int i=0;i<n;i++) {
// 		for(int j=0;j<m;j++) printf("%d ", arr[i][j]);
// 		puts("");
// 	}
// }

// #include <bits/stdc++.h>
// using namespace std;
// set<int*> S;
// int main()
// {
//     int *a, cmp = 1;
// 		a = &cmp;
// 		S.insert(a);
// 		cmp = 5;
// 		printf("%d", **S.begin());
// }
// using namespace std;
// int main() {
//   bool a = true;
//   printf("%d", a+2);
// }

// #include <bits/stdc++.h>
// using namespace std;
// int arr[1000], n, k, max = 0;;
// bool cmp(int a, int b) {
//   return a>b;
// }
// int main() {
//   scanf("%d", &n);
//   for(int i=1;i<=n;i++) {
//     scanf("%d", &arr[i]);
//   }
//   sort(arr+1, arr+n+1);
//   for(int i=1;i<=n;i++) printf("%d ", arr[i]);
//   puts("");
//   sort(arr+1, arr+n+1, cmp);
//   for(int i=1;i<=n;i++) printf("%d ", arr[i]);
// }

#include <bits/stdc++.h>
using namespace std;
int arr[11], cnt;
int main() {
  int money, k;
  scanf("%d %d", &money, &k);
  for(int i=1;i<=k;i++) scanf("%d", &arr[i]);
  while(money) {
    int i;
    for(i=1;i<=k && money >= arr[i];i++);
    i--;
    money -= arr[i];
    cnt++;
  }
  printf("%d", cnt);
}
