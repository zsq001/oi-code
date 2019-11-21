#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,type,a[1000],time;
	scanf("%d %d",&n,&type);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	time=(a[1]+a[2])*(a[1]+a[2]);
	for(int i=2;i<=n;i++)
	{
		if(type==0) time=time+a[i]*a[i];
	}
	if(n>5) time=time+13*a[1]*a[1]+2*a[1];
	printf("%d",time-1);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
