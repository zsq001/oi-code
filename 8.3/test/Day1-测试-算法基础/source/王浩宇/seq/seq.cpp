#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 500050
using namespace std;
const int eps=1e-6;
int n,minn=maxn;
double a[maxn],ans=maxn;
double cheak(double x)
{
	int l=1,r=n;
	double sum=0,num;
	for(int i=1;i<=n;i++)
	{
		a[i]-=x;
	}
	double max=0;
	for(int i=l;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum+=a[j];
			num=abs(sum);
			if(num>max)
			max=num;
		}
		sum=0;
	}
	for(int j=1;j<=n;j++)
	{
		a[j]+=x;
	}
	return max;
}
int main()
{
	
	int l=0,r=0,mid,mmid,now;
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]>r)
		{
			r=a[i];
		}
		if(a[i]<minn)
		{
			minn=a[i];
		}
	}
	if(minn==r)
	{
		printf("0.000000");
		return 0;
	}
	while(mid!=mmid)
	{
		mid=(l+r)/2;
		mmid=(mid+r)/2; 
		if(cheak(mid)>=cheak(mmid))l=mid;
		else r=mmid;
		
	}
	double dmid=mid;
	if(cheak(dmid+0.000001)<cheak(dmid))
	{
		dmid+=0.000001;
	}
	else if(cheak(dmid-0.000001)<cheak(dmid))
	{
		dmid-=0.000001;
	}
	printf("%.7lf",cheak(dmid));
	return 0;
}
