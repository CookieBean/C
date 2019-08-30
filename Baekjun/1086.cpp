#include <bits/stdc++.h>
using namespace std;
long long D[65540][101];
char arr[20][51];
int l[20], r[1000], n, k;
int elem[20]; // each remain of the member of set
int fin[101][101][101];
int top[101][101];
long long solve(int x, int y) {
	if(D[x][y] != -1) return D[x][y];
  D[x][y] = 0;
	for(int j=1;j<=n;j++) {
	  if((x | 1<<j) == x) {
      int tmp = (y-elem[j]>=0 ? y-elem[j] : k+y-elem[j]);
			// printf("D %d %d tmp : %d r[l[%d]] : %d\n", x, y, tmp, j, r[l[j]]);
			for(int i=0;i<top[r[l[j]]][tmp];i++) D[x][y] += solve(x - (1<<j), fin[r[l[j]]][tmp][i]);
		}
	}
	// printf("D %d %d val : %d\n", x, y, D[x][y]);
	return D[x][y];
}
long long fac(int n) {
  if(n == 1) return 1LL;
  return n*fac(n-1);
}
int main() {
  long long ans = 0;
  int t = 10;
  memset(D, -1LL, sizeof(D));
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
  	int len;
    scanf("%s", arr[i]);
    for(len = 0;arr[i][len];len++) arr[i][len] -= '0';
    l[i] = len;
  }
  scanf("%d", &k);
  r[0] = 1;
  for(int i=1;i<1000;i++) {
  	r[i] = t%k;
  	t = (t*10)%k;
  }
  for(int i=1;i<=n;i++) {
    for(int j=l[i]-1;j>=0;j--) {
      elem[i] = (elem[i] + arr[i][j]*r[l[i]-1-j])%k;
    }
		// printf("elem[%d] = %d\n", i, elem[i]);
		for(int m=0;m<101;m++) D[1<<i][m] = 0;
    D[1<<i][elem[i]] = 1;
  }
  memset(fin, -1, sizeof(fin));
  for(int i=1;i<=n;i++) {
    if(top[r[l[i]]][0] == 0) for(int j=0;j<k;j++) {
			fin[r[l[i]]][((r[l[i]])*j)%k][top[r[l[i]]][((r[l[i]])*j)%k]++] = j;
			// printf("fin[%d][%d][%d] = %d\n", r[l[i]], ((r[l[i]])*j)%k, top[r[l[i]]][((r[l[i]])*j)%k]-1, j);
    }
  }
  ans = solve((1<<(n+1))-2, 0);
  if(!ans) {
    printf("0/1");
    return 0;
  }
  printf("%lld/%lld", ans/__gcd(ans, fac(n)), fac(n)/__gcd(ans, fac(n)));
}
