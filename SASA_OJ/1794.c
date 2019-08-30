#include<stdio.h>
int main()
{
	int a[5][5]={0};
	int sum = 0;
	int max=0;
	for(int i=0;i<5;i++) for(int j=0;j<5;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			sum = 0;
			sum=a[i][j]+a[i+1][j]+a[i+2][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i][j+2]+a[i+1][j+2]+a[i+2][j+2];
			max=sum>max?sum:max;
		}
	}
	printf("%d",max);
}
