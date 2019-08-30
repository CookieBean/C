#include <bits/stdc++.h>
using namespace std;
queue<int> a;
map<int, int> b;
int main() {
  int n, m, k;
  scanf("%d %d", &n, &m);
  if(m == 1) {
    int min = 1000000000;
    for(int i=1;i<=n;i++) {
      scanf("%d", &k);
      if(k<min) min = k;
    }
    printf("%d", min);
  } else if(m == 2) {
    int max = 0, l = 1000000000;
    for(int i=1;i<=n;i++) {
      scanf("%d", &k);
      a.push(k);
      b.insert(pair<int, int>(k, k));
    }
    for(int i=1;i<=n;i++) {
      if(l>a.front()) l = a.front();
      b.erase(a.front());
      a.pop();
      if(b.begin()->first > max) max = b.begin()->first;
      if(l > max) max = l;
    }
    printf("%d", max);
  } else if(m>=3) {
    int max = 0, k;
    for(int i=1;i<=n;i++) {
      scanf("%d", &k);
      if(k>max) max = k;
    }
    printf("%d", max);
  }
}
