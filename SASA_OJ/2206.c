// #include <stdio.h>
// char a[300][3][3], final, inven[300], ans[300];
// int count[300];
// void f(int item, int num) { // num is the total need number that we shoud make. need is the number that when we make a one new item
//   int need[300] = {};
//   for(int i=0;i<3;i++) {
//     for(int j=0;j<3;j++) {
//       need[a[item][i][j]]++;
//     }
//   }
//   for(int i=97;i<123;i++) {
//     if(inven[i]) printf("inventory : %c %d\n", i, inven[i]);
//   }
//   for(int i=97;i<123;i++) {
//     int cnt = 0;
//     while(cnt<num && need[i]) {
//       if(count[i]) {
//         if(inven[i]>=need[i]) {
//           printf("needed %c but we already have that item left : %d\n", i, inven[i]-need[i]);
//           printf("char : %c, num : %d, cnt : %d\n", i, num, cnt);
//           inven[i]-=need[i];
//           cnt+=count[item];
//         } else {
//           printf("needed %c but we have no item used : %d\n", i, inven[i]);
//           printf("char : %c, num : %d, cnt : %d\n", i, num, cnt);
//           cnt+=count[item];
//           inven[i] = 0;
//           f(i, need[i]-inven[i]);
//         }
//       } else {
//         printf("needed %c and we don't have combinations so just added : %d, num : %d\n", i, need[i], num);
//         ans[i]+=need[i];
//         cnt+=count[item];
//       }
//     }
//   }
// }
// int main() {
//   int n;
//   scanf("%d", &n);
//   for(int i=0;i<n;i++) {
//     char m;
//     scanf(" %c", &m);
//     scanf("%d", &count[m]); //count is the number of combinations
//     for(int p=0;p<3;p++) {
//       for(int q=0;q<3;q++) {
//         char k;
//         scanf(" %c", &k);
//         if(k != '.') a[m][p][q] = k;
//       }
//     }
//   }
//   scanf(" %c", &final);
//   printf("%d\n", count['d']);
//   f((int)final, 1);
//   for(int i=97;i<123;i++) if(ans[i]) printf("%c %d\n", i, ans[i]);
// }

#include <stdio.h>
char final, a[128][128], b[128][128];
long long int ans[128], flag, count[128];
int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    char m, top = 0;
    scanf(" %c", &m);
    scanf("%lld", &count[m]);
    for(int p=0;p<3;p++) for(int q=0;q<3;q++) {
      char k;
      scanf(" %c", &k);
      if(k != '.') {
        a[m][k]++;
        flag = 1;
        for(int j=0;j<top;j++) if(b[m][j] == k) flag = 0;
        if(flag) {
          b[m][top] = k;
          top++;
        }
      }
    }
  }
  scanf(" %c", &final);
  ans[final]+=1LL;
  flag = 1;
  while(flag) {
    flag = 0;
    for(int i=0;i<128;i++) if(count[i] && ans[i]>0) {
      long long int loop;
      flag = 1;
      if(ans[i]%count[i]) loop = ans[i]/count[i]+1;
      else loop = ans[i]/count[i];
      for(int j=0;b[i][j]>0;j++) {
        ans[b[i][j]] += a[i][b[i][j]]*loop;
        ans[i] -= count[i]*loop;
      }
    }
  }
  for(int i=0;i<128;i++) if(ans[i]>0) printf("%c %lld\n", i, ans[i]);
}
