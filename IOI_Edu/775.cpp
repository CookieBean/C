#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
queue<long long int> arr[21];
int main() {
  long long int n, m, sum = 0;
  scanf("%lld %lld", &n, &m);
  char brr[20];
  for(int i=0;i<n;i++) {
    scanf("%s", brr);
    int len = strlen(brr);
    while(arr[len].size()>0 && i-arr[len].front() > m) arr[len].pop();
    sum += arr[len].size();
    arr[len].push(i);
  }
  printf("%lld", sum);
}
