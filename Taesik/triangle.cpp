#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  for(int i=1;i<=n/3;i++) {
    for(int j=i;j<=(n-i)/2;j++) {
      if(j+i>n-i-j) cnt++;
    }
  }
  printf("%d", cnt);
}
