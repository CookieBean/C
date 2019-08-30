#include <stdio.h>
char arr[300];
int k, len;
int f() {
  int cnt = 1;
  k = 0;
  for(int i=0;i<len;i++) {
    int c = arr[i];
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c == '-' || c == '.') cnt *= 1;
    else if(c == '@' && i != 0 && i != len-1) {
      k++;
    }
    else {
      cnt *= 0;
    }
  }
  return cnt+10*k;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    scanf("%s", arr);
    for(len=0;arr[len];len++);
    if(f()/10 == 1 && f()%10 == 1) puts("Yes");
    else puts("No");
  }
}
