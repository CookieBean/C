#include <stdio.h>

int main(void){
  int f, cnt = 0;
  char a[13];
  f = scanf("%s", a);
  while(a[cnt] != '\0') cnt++;
  cnt--;
  while(cnt>=0) {
    printf("%c\n", a[cnt]);
    cnt--;
  }
}
