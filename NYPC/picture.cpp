#include <bits/stdc++.h>
using namespace std;
int arr[100001];
vector<int> v;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(arr, -1, sizeof(arr));
  for(int i=1;i<=n;i++) {
    int k;
    scanf("%d", &k);
    for(int j=0;j<v.size();j++) {
      // printf("v[%d] = %d k = %d\n", j, v[j], k);
      if(v[j] == k) {
        // printf("arr[%d] = %d\n", i, j);
        arr[i] = j;
        break;
      }
    }
    if(arr[i] == -1) {
      v.push_back(k);
      arr[i] = v.size()-1;
    }
  }
  // for(int i=1;i<=n;i++) printf("%d ", arr[i]);
  for(int i=1;i<=m;i++) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    if(t == 1) {
      arr[a] = -1;
      for(int j=0;j<v.size();j++) {
        if(v[j] == b) {
          arr[i] = j;
          break;
        }
      }
      if(arr[a] == -1) {
        v.push_back(b);
        arr[a] = v.size()-1;
      }
    }
    else if(t == 2) {
      bool cnt[1000001];
      int j;
      for(j=a;j<=b;j++) {
        cnt[arr[j]] = (cnt[arr[j]]+1)%2;
      }
      for(j=a;j<=b;j++) if(cnt[arr[j]] == 1) break;
      printf("%d\n", v[arr[j]]);
    }
  }
}
