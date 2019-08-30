// 1번
// #include <stdio.h>
// int main() {
//   printf("Hello\n");
// }

// 2번
// #include <stdio.h>
// int main() {
//   printf("Hello World\n");
// }

// 3번
// #include <stdio.h>
// int main() {
//   printf("Hello\nWorld\n");
// }

// 4번
// #include <stdio.h>
// int main() {
//   printf("'Hello'\n");
// }

// 5번
// #include <stdio.h>
// int main() {
//   printf("\"Hello World\"\n");
// }

// 6번
// #include <stdio.h>
// int main() {
//   printf("\"!@#$%%^&*()\"\n");
// }

// 7번
// #include <stdio.h>
// int main() {
//   printf("#include <stdio.h>\nint main()\n{\n    printf(\"Hello World\\n\");\n    return 0;\n}");
// }

// 8번
// #include <stdio.h>
// int main() {
//   int a;
//   scanf("%d", &a);
//   printf("%d\n", a);
// }

// 9번
// #include <stdio.h>
// int main() {
//   char a;
//   scanf("%c", &a);
//   printf("%c\n", a);
// }

// 10번
// #include <stdio.h>
// int main() {
//   float a;
//   scanf("%f", &a);
//   printf("%f\n", a);
// }

// 11번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%d %d\n", a, b);
// }

// 12번
// #include <stdio.h>
// int main() {
//   char a, b;
//   scanf("%c %c", &a, &b);
//   printf("%c %c\n", b, a);
// }

// 13번
// #include <stdio.h>
// int main() {
//   float a, b;
//   scanf("%f", &a);
//   printf("%.2f\n", a);
// }

// 14번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%d\n", a>b);
// }

// 15번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d", &a, &b);
//   printf("%d %d %d\n", a, a, a);
// }

// 16번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d:%d", &a, &b);
//   printf("%d:%d\n", a, b);
// }

// 17번
// #include <stdio.h>
// int main() {
//   int a, b, c;
//   scanf("%d.%d.%d", &a, &b, &c);
//   printf("%04d.%02d.%02d\n", a, b, c);
// }

// 18번
// #include <stdio.h>
// int main() {
//   int a, b, c;
//   scanf("%d-%d", &a, &b);
//   printf("%06d%07d\n", a, b);
// }

// 19번
// #include <stdio.h>
// int main() {
//   char a[50];
//   fgets(a, sizeof(a), stdin);
//   fputs(a, stdout);
// }

// 20번
// #include <stdio.h>
// int main() {
//   char a[2005];
//   fgets(a, sizeof(a), stdin);
//   fputs(a, stdout);
// }

// 21번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d.%d", &a, &b);
//   printf("%d\n%d\n", a, b);
// }

// 22번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%d\n", a>=b ? a : b);
// }

// 23번
// #include <stdio.h>
// int main() {
//   char a;
//   while((a = getc(stdin))!=EOF) {
//     printf("'%c'\n", a);
//   }
//   return 0;
// }

// 24번
// #include <stdio.h>
// int main() {
//   int a[6];
//   scanf("%1d%1d%1d%1d%1d", &a[0], &a[1], &a[2], &a[3], &a[4]);
//   printf("[%d]\n", a[0]*10000);
//   printf("[%d]\n", a[1]*1000);
//   printf("[%d]\n", a[2]*100);
//   printf("[%d]\n", a[3]*10);
//   printf("[%d]\n", a[4]*1);
// }

// 25번
// #include <stdio.h>
// int main() {
//   int h, m, s;
//   scanf("%d:%d", &h, &m);
//   printf("%d\n", m);
// }

// 26번
// #include <stdio.h>
// int main() {
//   int h, m, s;
//   scanf("%d.%d.%d\n", &h, &m, &s);
//   printf("%02d-%02d-%04d\n", s, m, h);
// }

// 27번
// #include <stdio.h>
// int main() {
//   unsigned int n;
//   scanf("%u", &n);
//   printf("%u\n", n);
// }

// 28번
// #include <stdio.h>
// int main() {
//   double n;
//   scanf("%lf", &n);
//   printf("%lf\n", n);
// }


// 29번
// #include <stdio.h>
// int main() {
//   long long int n;
//   scanf("%lld", &n);
//   printf("%lld\n", n);
// }

// 30번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%o\n", n);
// }

// 31번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%x\n", n);
// }

// 32번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%X\n", n);
// }

// 33번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%o", &n);
//   printf("%d\n", n);
// }

// 34번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%x", &n);
//   printf("%o\n", n);
// }

// 35번
// #include <stdio.h>
// int main() {
//   char n;
//   scanf("%c", &n);
//   printf("%d\n", n);
// } // %c 라는 의미 자체가 1을 넣는다면, 00000001을 바꾸려는 변수(n)에 덮는거 같아. 그러니깐 만약 n을 int로 선언한뒤, 초기화를 안해주면 처음 들어갔던 쓰레기값 때문에 안덮어진 부분이 있어서 이상한 값이 나오는거야. 따라서
//  초기화해줄때 0같은 얘 또는 char 범위를 넘지 않는 만큼을 저장한다면 상관이 없지. 왜냐하면 그만큼은 1을 char로 넣을때 덮어지니깐.
// #include <stdio.h>
// int main() {
//   int n;
//   n = 256; // -> 256 = 2^8 따라서 9번째 비트에도 값이 들어가기에 65(A)가 덮지 못했어!
//   scanf("%c", &n);
//   printf("%d\n", n);
// }

// 36번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%c\n", n);
// }

// 37번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%lld\n", a+b);
// }

// 38번
// #include <stdio.h>
// int main() {
//   long long int a, b; // long long int 형 변수인데 %d로 받으면, CODE SASA에서는 오류가 안난다. 원인 불명. 하지만 오류나야 정상.(위에서 한 char과 같은 이유로)(ex) 1, 1
//   scanf("%lld %lld", &a, &b);
//   printf("%lld\n", a+b);
// }

// 39번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d", &a);
//   printf("%d\n", -a);
// }

// 40번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%c", &a);
//   printf("%c\n", (char)a+1); // 이제 char int 프린트나 할당, 저장의 원리를 알았으니 이렇게 형변환 해서 출력도 문제가 없다는걸 알았겠지?
// }

// 41번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%d\n", a/b);
// }

// 42번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%d\n", a%b);
// }

// 43번
// #include <stdio.h>
// int main() {
//   long a, b;
//   scanf("%ld", &a, &b);
//   printf("%ld\n", a+1);
// }

// 44번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   printf("%lld\n%lld\n%lld\n%lld\n%lld\n%.2f\n", a+b, a>b ? a-b : b-a, a*b, a/b, a%b, (float)a/b);
// }

// 45번
// #include <stdio.h>
// int main() {
//   int a, b, c;
//   scanf("%d %d %d", &a, &b, &c);
//   printf("%d\n%.1f\n", a+b+c, (float)(a+b+c)/3);
// }

// 46번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%d\n", n<<1);
// }

// 47번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n<<m);
// }

// 48번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n==m);
// }

// 49번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", m>=n ? 1 : -1);
// }

// 50번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", m!=n);
// }

// 51번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d", &n);
//   printf("%d\n", !n);
// }

// 52번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n&&m);
// }

// 53번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n||m);
// }

// 54번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", (!n&&m)||(n&&!m));
// }

// 55번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", (n&&m)||(!n&&!m));
// }

// 56번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", (!n&&!m));
// }

// 57번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d", &n);
//   printf("%d\n", ~n);
// }

// 58번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n&m);
// }

// 59번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n^m);
// }

// 60번
// #include <stdio.h>
// int main() {
//   int n, m;
//   scanf("%d %d", &n, &m);
//   printf("%d\n", n|m);
// }

// 61번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   scanf("%d %d %d", &n, &m, &k);
//   printf("%d\n", (n<m ? n : m)<k ? (n<m ? n : m) : k);
// }

// 62번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   for(int i = 0; i<3; i++) {
//     scanf("%d", &m);
//     if(m%2 == 0) printf("%d\n", m);
//   }
// }

// 63번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   for(int i = 0; i<3; i++) {
//     scanf("%d", &m);
//     if(m%2 == 0) printf("even\n");
//     else printf("odd\n");
//   }
// }

// 64번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   scanf("%d", &n);
//   if(n>0) printf("plus\n");
//   else printf("minus\n");
//   if(n%2 == 0) printf("even\n");
//   else printf("odd\n");
// }

// 65번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   scanf("%d", &n);
//   if(n>=90 && n<=100) printf("A\n");
//   else if(n>=70 && n<=89) printf("B\n");
//   else if(n>=40 && n<=69) printf("C\n");
//   else if(n>=0 && n<=39) printf("D\n");
// }

// 66번
// #include <stdio.h>
// int main() {
//   char n, m, k;
//   scanf("%c", &n);
//   switch (n) {
//     case 'A':
//       printf("best!!!\n");
//       break;
//     case 'B':
//       printf("good!!\n");
//       break;
//     case 'C':
//       printf("run!\n");
//       break;
//     case 'D':
//       printf("slowly~\n");
//       break;
//     default :
//       printf("what?\n");
//       break;
//   }
// }

// 67번
// #include <stdio.h>
// int main() {
//   int n, m, k;
//   scanf("%d", &n);
//   switch (n) { // switch 문에서 gcc같은 경우는 case a...b 하면 a이상 b이하 정수들이 모두 그 케이스로 들어감. 비주얼에서는 안된다고 한다.
//     case 12: // 따라서 비주얼에서는 어쩔 수 없이 그냥 case 3: case 4: 하고 break 안쓰는 방식으로 해야함.
//     case 1 ... 2:
//       printf("winter\n");
//       break;
//     case 3 ... 5:
//       printf("spring\n");
//       break;
//     case 6 ... 8:
//       printf("summer\n");
//       break;
//     case 9 ... 11:
//       printf("fall\n");
//       break;
//     default :
//       break;
//   }
// }

// 68번
// #include <stdio.h>
// int main() {
//   int n = 1;
//   while(n!=0) {
//     scanf("%d", &n);
//     printf("%d\n", n);
//   }
// } //OR DOWN WAY
// #include <stdio.h>
// int main() {
//   int n;
//   re:
//   scanf("%d", &n);
//   printf("%d\n", n);
//   if(n!=0) goto re; // goto 문의 label은 switch 의 label과 비슷하게 생겼으나, 그 case 레이블을 바로 goto가 사용하지는 못하는 것 같다. 실제 테스트시 작동 X
// }

// 69번
// #include <stdio.h>
// int main() {
//   int n, a, i = 0;
//   scanf("%d", &n);
//   if(n == 0) return 0;
//   re:
//   i++;
//   scanf("%d", &a);
//   printf("%d\n", a);
//   if(i<n) goto re;
// }

// 70번
// #include <stdio.h>
// int main() {
//   int n = 1;
//   while(n!=0) {
//     scanf("%d", &n);
//     printf("%d\n", n);
//   }
// }

// 71번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   while (n>0) {
//     printf("%d\n", n--);
//   }
// }

// 72번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   while (n>0) {
//     printf("%d\n", --n);
//   }
// }

// 73번
// #include <stdio.h>
// int main() {
//   char n;
//   scanf("%c", &n);
//   for(char i = 'a'; i<=n; i++) {
//     printf("%c ", i);
//   }
// } OR DOWN WAY
// #include <stdio.h>
// int main() {
//   char n, m = 'a';
//   scanf("%c", &n);
//   do {
//     printf("%c ", m);
//     m++;
//   } while (n>=m);
// }

// 74번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i = 0; i<=n ;i++) {
//     printf("%d\n", i);
//   }
// }

// 75번
// #include <stdio.h>
// int main() {
//   int n, sum = 0;
//   scanf("%d", &n);
//   for(int i = 0; i<=n ;i+=2) {
//     sum+=i;
//   }
//   printf("%d\n", sum);
// }

// 76번
// #include <stdio.h>
// int main() { // 현재 Codeup 에서는 정확한 풀이 판정 받음. SASA OJ 에서만 표현오류 원인불명
//   char n;
//   while((n=getc(stdin))!='q') {
//     if(n!=' ') printf("%c\n", n);
//   }
//   printf("%c\n", n);
// }
// #include <stdio.h>
// int main() {
//   char n;
//   while(1) {
//     scanf("%c ", &n);
//     printf("%c\n", n);
//     if(n == 'q') break;
//   }
// }

// 77번
// #include <stdio.h>
// int main() {
//   int n = 0, a, i = 1;
//   scanf("%d", &a);
//   while (n<a) {
//     n+=i;
//     i++;
//   }
//   printf("%d\n", --i);
// }

// 78번
// #include <stdio.h>
// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   for(int i = 1; i<=a; i++) {
//     for(int j = 1; j<=b; j++) {
//       printf("%d %d\n", i, j);
//     }
//   }
// }

// 79번
// #include <stdio.h>
// int main() {
//   int a;
//   scanf("%X", &a);
//   for(int i = 1; i<=15; i++) {
//     printf("%X*%X=%X\n", a, i, a*i);
//   }
// }

// 80번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     if(i%3 == 0) printf("X ");
//     else printf("%d ", i);
//   }
// }

// 81번
// #include <stdio.h>
// int main() {
//   int r, g, b;
//   scanf("%d %d %d", &r, &g, &b);
//   for(int i = 0; i<r; i++)
//     for(int j = 0; j<g; j++)
//       for(int k = 0; k<b; k++) printf("%d %d %d\n", i, j, k);
//   printf("%d\n", r*g*b);
// }

// 82번
// #include <stdio.h>
// int main() {
//   int h, b, c, s;
//   scanf("%d %d %d %d", &h, &b, &c, &s);
//   printf("%.1f MB\n", (float)h*b*c*s/8/1024/1024);
// }

// 83번
// #include <stdio.h>
// int main() {
//   int w, h, b;
//   scanf("%d %d %d", &w, &h, &b);
//   printf("%.2f MB\n", (float)h*b*w/8/1024/1024);
// }

// 84번
// #include <stdio.h>
// int main() {
//   int w, sum = 0;
//   scanf("%d", &w);
//   for(int i = 1; sum<w; i++) {
//     sum+=i;
//   }
//   printf("%d\n", sum);
// }

// 85번
// #include <stdio.h>
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     if(i%3!=0) printf("%d ", i);;
//   }
// }

// 86번
// #include <stdio.h>
// int main() {
//   int a, d, n;
//   scanf("%d %d %d", &a, &d, &n);
//   for(int i = 1; i<n; i++) {
//     a+=d;
//   }
//   printf("%d\n", a);
// }

// 87번
// #include <stdio.h>
// int main() {
//   int a, d, n;
//   scanf("%d %d %d", &a, &d, &n);
//   for(int i = 1; i<n; i++) {
//     a*=d;
//   }
//   printf("%d\n", a);
// }

// 88번
// #include <stdio.h>
// int main() {
//   int a, r, d, n;
//   scanf("%d %d %d %d", &a, &r, &d, &n);
//   for(int i = 1; i<n; i++) {
//     a*=r;
//     a+=d;
//   }
//   printf("%d\n", a);
// }

// 89번
// #include <stdio.h>
// int main() {
//   int a, r, d, n;
//   scanf("%d %d %d", &a, &r, &d);
//   int max = (a>r ? a : r)>d ? (a>r ? a : r) : d;
//   for(int i = max; i<=a*r*d; i++) {
//     if(i%r == 0 && i%a == 0 && i%d == 0) {n = i; break;}
//   }
//   printf("%d\n", n);
// }

// 90번
// #include <stdio.h>
// int main() {
//   int n, b;
//   scanf("%d", &n);
//   int a[24] = {0, };
//   for(int i = 1; i<=n; i++) {
//     scanf("%d", &b);
//     a[b]++;
//   }
//   for(int i = 1; i<=23; i++) {
//     printf("%d ", a[i]);
//   }
// }

// 91번
// #include <stdio.h>
// int main() {
//   int n, b;
//   scanf("%d", &n);
//   int a[10005] = {0, };
//   for(int i = 1; i<=n; i++) {
//     scanf("%d", &b);
//     a[i] = b;;
//   }
//   for(int i = n; i>=1; i--) {
//     printf("%d ", a[i]);
//   }
// }

// 92번
// #include <stdio.h>
// int main() {
//   int n, min = 25;
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     int b;
//     scanf("%d", &b);
//     if(min>b) min = b;
//   }
//   printf("%d\n", min);
// }

// 93번
// #include <stdio.h>
// int main() {
//   int n, a, b;
//   int arr[20][20] = {0, };
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     scanf("%d %d", &a, &b);
//     arr[a][b] = 1;
//   }
//   for(int i = 1; i<=19; i++) {
//     for(int j = 1; j<=19; j++)
//       printf("%d ", arr[i][j]);
//     printf("\n");
//   }
// }

// 94번
// #include <stdio.h>
// int main() {
//   int n, a, b;
//   int arr[20][20];
//   for(int i = 1; i<=19; i++) for(int j = 1; j<=19; j++) scanf("%d", &arr[i][j]);
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     scanf("%d %d", &a, &b);
//     for(int j = 1; j<=19; j++) {
//       arr[a][j] = !arr[a][j];
//       arr[j][b] = !arr[j][b];
//     }
//   }
//   for(int i = 1; i<=19; i++) {
//     for(int j = 1; j<=19; j++) printf("%d ", arr[i][j]);
//     printf("\n");
//   }
// }

// 95번
// #include <stdio.h>
// int main() {
//   int w, h, n;
//   int arr[101][101];
//   scanf("%d %d", &w, &h);
//   scanf("%d", &n);
//   for(int i = 1; i<=n; i++) {
//     int l, d, x, y;
//     scanf("%d %d %d %d", &l, &d, &x, &y);
//     for(int j = 0; j<l; j++) {
//       if(d == 0) arr[x][y+j] = 1;
//       else arr[x+j][y] = 1;
//     }
//   }
//   for(int i = 1; i<=h; i++) {
//     for(int j = 1; j<=w; j++) printf("%d ", arr[i][j]);
//     printf("\n");
//   }
// }

// 96번
// #include <stdio.h>
// int main() {
//   int x = 2, y = 2;
//   int a[11][11];
//   for(int i = 1; i<=10; i++)
//     for(int j = 1; j<=10; j++)
//       scanf("%d", &a[i][j]);
//   a[2][2] = 9;
//   while(1) {
//     if(a[x][y+1]==2) {
//       a[x][y+1] = 9;
//       break;
//     } else if(a[x][y+1]==0) a[x][++y] = 9;
//     else {
//       if(a[x+1][y]==2) {
//         a[x+1][y] = 9;
//         break;
//       } else if(a[x+1][y]==0) a[++x][y] = 9;
//       else break;
//     }
//   }
//   for(int i = 1; i<=10; i++) {
//     for(int j = 1; j<=10; j++) printf("%d ", a[i][j]);
//     printf("\n");
//   }
// } OR THE BETTER CODE
// #include <stdio.h>
// int main() {
//   int x = 2, y = 2, i, j;
//   int a[11][11];
//   for(i = 1; i<=10; i++)
//     for(j = 1; j<=10; j++)
//       scanf("%d", &a[i][j]);
//   while(a[x][y] == 0) {
//     a[x][y] = 9;
//     if(a[x][y+1] != 1) y++;
//     else x++;
//   }
//   if(a[x][y] == 2) a[x][y] = 9;
//   for(i = 1; i<=10; i++) {
//     for(j = 1; j<=10; j++) printf("%d ", a[i][j]);
//     printf("\n");
//   }
// }
