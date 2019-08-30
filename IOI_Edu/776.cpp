#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
struct f {
  int cnt;
  int num;
  int div;
  bool operator<(const f &o) const {
    return div < o.div;
  }
};
priority_queue<f> q;
int main() {
  int a, b, pre;
  scanf("%d %d", &a, &b);
  if(b == 1) {
    int k, div;
    scanf("%d", &k);
    if(k%a == 0) div = k/a;
    else div = k/a+1;
    printf("%d", div);
    return 0;
  }
  for(int i=0;i<b;i++) {
    int k;
    f arr;
    scanf("%d", &k);
    arr.cnt = k;
    arr.num = 1;
    arr.div = k;
    q.push(arr);
  }
  f n = q.top();
  for(int i=1;i<=a-b;i++) {
    n.num++;
    if(n.cnt%n.num == 0) n.div = n.cnt/n.num;
    else n.div = n.cnt/n.num+1;
    if(q.top().div<n.div) continue;
    q.pop();
    q.push(n);
  }
  printf("%d", q.top().div);
}
