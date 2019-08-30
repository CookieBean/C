#include <stdio.h>
int used[100005];
int inf[100005][3];
int ans[100005];
int brr[100005];
// int main() {
//   int n, m, top = 0;
//   scanf("%d %d", &n, &m);
//   for(int i=1;i<=m;i++) {
//     scanf("%d %d", &inf[i][1], &inf[i][2]);
//   }
//   for(int i=1;i<=n;i++) {
//     int cnt = 1, sum = 1, j;
//     for(j=1;j<=m;j++) {
//       if(inf[j][1] == i) cnt++;
//     }
//   j = 1;
//   while(sum<=cnt) {
//   if(!used[j]) sum++;
//   j++;
//   }
//     used[--j] = 1;
//     ans[++top] = j;
//   }
//   for(int i=1;i<=m;i++) {
//     if(ans[inf[i][1]]<ans[inf[i][2]]) {
//       puts("-1");
//       return 0;
//     }
//   }
//   for(int i=1;i<=top;i++) printf("%d ", ans[i]);
// }
int main() {
  int n, m, top = 0, x, y;
  scanf("%d %d", &n, &m);
  for(int i=1;i<=m;i++) {
    scanf("%d %d", &inf[i][1], &inf[i][2]);
    brr[inf[i][1]]++;
  }
  printf("%d\n", brr[3]);
  for(int i=1;i<=m;i++) {
    int j = 1, sum = 1;
    while(sum<=brr[i]) {
      if(!used[i]) sum++;
      j++;
      printf("j increased : %d\n", j);
    }
    used[j] = i;
    ans[++top] = j;
    printf("used[%d] = %d, ans[%d] = %d\n", j, i, top, j);
  }
  for(int i=1;i<=m;i++) {
    if(ans[inf[i][1]]<ans[inf[i][2]]) {
      puts("-1");
      return 0;
    }
  }
  for(int i=1;i<=top;i++) printf("%d ", ans[i]);
}
