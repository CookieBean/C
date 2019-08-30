#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int i;
  for(int j=1;j<=100;j++) {
    char a[100005];
    fgets(a, sizeof(a), stdin);
    for(i=0;a[i] != '\n';i++);
    a[i] = 0;
    // printf("\nlength is %d", i);
    int c = 0;
    int arr[5];
    int end[5];
    while(a[c] >= '0' && a[c] <= '9') c++;
    // printf("\nindex c = %d inserted zero", c);
    a[c] = 0;
    end[0] = c;
    c++;
    while(a[c] == ' ') c++;
    arr[0] = c;
    while(a[c] != ' ') c++;
    // printf("\nindex c = %d inserted zero", c);
    a[c] = 0;
    end[1] = c;
    c++;
    while(a[c] == ' ') c++;
    if(a[c]<'a') {
      arr[1] = c;
      int k=1;
      while(a[c] < 'a') c++;
      c--;
      while(a[c] == ' ') c--;
      a[++c] = 0;
      // printf("\nindex c = %d inserted zero", c);
      end[2] = c;
      c++;
      while(a[c] == ' ') c++;
    } else arr[1] = end[1];
    arr[2] = c;
    while(a[c] >= 'a' && a[c] <= 'z') c++;
    a[c] = 0;
    end[3] = c;
    // printf("\nindex c = %d inserted zero", c);
    c++;
    while(a[c] == ' ' && c<i) c++;
    while(a[c] != ' ' && c<i) c++;
    while(a[c] == ' ' && c<i) c++;
    arr[3] = c;
    // printf("\nThe last word starts in %d", c);
    printf("\n%s=%s=%s=%s=%s", a, a+arr[0], a+arr[1], a+arr[2], a+arr[3]);
  }
}
