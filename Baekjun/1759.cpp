#include <cstdio>
#include <algorithm>
char a[300];
int n, m, arr[300];
void f(int start, int left, int brr[]) {
  if(left==0) {
    int vowel = 0, con = 0;
    for(int i=0;i<n;i++) {
      char k = a[brr[i]-1];
      if(k == 'a' || k == 'e' || k == 'o' || k == 'i' || k == 'u') {
        vowel++;
      } else con++;
    }
    if(vowel>=1 && con>=2) {
      for(int i=0;i<n;i++) {
        printf("%c", a[brr[i]-1]);
      }
      puts("");
    }
    return;
  }
  if(start>m) return;
  brr[n-left] = start;
  // printf("f(%d, %d, array) 호출\n", start+1, left-1);
  // for(int i=0;i<=n-left;i++) {
  //   printf("brr[%d] = %d\n", i, brr[i]);
  // }
  f(start+1, left-1, brr);
  brr[n-left] = 0;
  // printf("f(%d, %d, array) 호출\n", start+1, left-1);
  // for(int i=0;i<=n-left;i++) {
  //   printf("brr[%d] = %d\n", i, brr[i]);
  // }
  f(start+1, left, brr);
}
int main() {
  scanf("%d %d", &n, &m);
  for(int i=0;i<m;i++) {
    scanf(" %c", &a[i]);
  }
  std::sort(a, a+m);
  for(int i=0;i<m;i++) {
    printf("%c ", a[i]);
  }
  puts("");
  f(1, n, arr);
}
