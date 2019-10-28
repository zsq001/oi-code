#include<stdio.h>
int n;
int a[200005];
int minn=999999999;
int maxn=-999999999;
double mid;
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a[i]);
		if(a[i]>maxn) maxn=a[i];
		if(a[i]<minn) minn=a[i];
	}
	int l=minn;
	int r=maxn;
	//while(r>=l)
	//{
	//	mid=(r+l)/2;	
	//}
	mid=(r+l)/2;
	printf("%.15lf",mid);
	return 0;
}
