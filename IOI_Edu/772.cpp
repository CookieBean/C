#include <stdio.h>
#define N 21
#define M 10001
long long n, coin[N], t;
unsigned long long int d[M];

int main(){
	long long i, j;
	scanf("%lld", &n);
	for(i=1;i<=n;i++) scanf("%lld", &coin[i]);
	scanf("%lld", &t);
	long long s;
	d[0]=1;
	for(i=1;i<=n;i++){
		s=coin[i];
		for(j=1;j<=t;j++){
			if(j<s)continue;
			d[j]+=d[j-s];
		}
	}
	printf("%llu", d[t]);
	return 0;
}
