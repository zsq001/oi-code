#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500050
using namespace std;
int n,m,k,x,s,ans,minn=maxn;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
	int nowm,nows,nowh,t,nowm1;
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&x,&s);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&d[i]);
	}
	nowh=n;
	for(int i=1;i<=m;i++)
	{
		nowm=s;
		nows=x;
		if(nowm>=b[i])
		{
			nowm-=b[i];
			nows=a[i];
		}
		nowm1=nowm;
		for(int j=1;j<=k;j++)
		{
			
			if(nowm>=d[j])
			{
				nowm-=d[j];
				nowh-=c[j];
			}
			t=nowh*nows;
			if(t<minn)
			{
				minn=t;
			}
			nowh=n;
			nowm=nowm1;
		}
	}
	printf("%d",minn);
}
