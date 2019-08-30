// #define m 1000000007 // 단순 재귀함수 ... 그것도 상호재귀 이거 왜 숫자가 커지면 안되는지 모르겠음
// #include <stdio.h>
// int arr[1000002][2], n;
// int f(int a);
// int g(int a);
// int f(int a) {
//   if(a == 1) return 2;
//   else if(a == 2) return 7;
//   if(arr[a][0]) return arr[a][0];
//   else {
//     arr[a][0] = (2*(g(a))%m+f(a-2)%m)%m;
//     return arr[a][0];
//   }
// }
// int g(int a) {
//   if(a == 1) return 1;
//   else if(a == 2) return 3;
//   if(arr[a][1]) return arr[a][1];
//   else {
//     arr[a][1] = (f(a-1)%m+g(a-1)%m)%m;
//     return arr[a][1];

//   }
// }
// int main() {
//   scanf("%d", &n);
//   printf("%d\n", f(n));
//   // for(int i = 0; i<=n; i++) {
//   //   printf("%d %d\n", arr[i][0], arr[i][1]);
//   // }
// }

// #include <cstdio> // -> 재귀함수의 for문 변형
//
// int main() {
// 	int n;
// 	scanf("%d", &n);
//
// 	int a = 1, b = 2, c = 7, d = 22;
// 	for (int i = 0; i < n; ++i) {
// 		a = b, b = c, c = d;
// 		d = (3ll * c + b - a + 1000000007) % 1000000007;
// 	}
//
// 	printf("%d", a);
//
// 	return 0;
// }

// #include <stdio.h>
// int arr[100001], top = -1, tc = -1;
// char brr[100001];
// int main() {
//   int n, k, natural = 1;
//   scanf("%d", &n);
//   for(int i = 0; i<n; i++) {
//     scanf("%d", &k);
//     while(top<=-1||arr[top]!=k) {
//         if(natural>n) {
//           printf("NO\n");
//           return 0;
//         }
//         arr[++top] = natural++;
//         brr[++tc] = '+';
//     }
//     top--;
//     brr[++tc] = '-';
//   }
//   for(int i=0;i<=tc;i++) printf("%c\n", brr[i]);
// }

// #include <stdio.h>
// int arr[100001], crr[100001], top = -1, tc = -1;
// char brr[100001];
// int main() {
//   int n, k, natural = 1;
//   scanf("%d", &n);
//   for(int i = 0; i<n; i++) scanf("%d", &crr[i]);
//   for(int i = 0; i<n; i++) {
//     k = crr[i];
//     while(top<=-1||arr[top]!=k) {
//         if(natural>n) {
//           printf("NO\n");
//           return 0;
//         }
//         arr[++top] = natural++;
//         brr[++tc] = '+';
//     }
//     top--;
//     brr[++tc] = '-';
//   }
//   for(int i=0;i<=tc;i++) printf("%c\n", brr[i]);
// }
