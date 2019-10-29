#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long int n,x;
double ans,num;
long long int p;
float a[100005],a1[100005],t[100005],t1[100005];
bool cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	long long int i,j;
	scanf("%lld",&n);
	for(i=0;i<n;++i)
	{
		scanf("%f%f",&a[i],&t[i]);
		a1[i]=a[i];
		t1[i]=t[i];
	}
	for(i=0;i<n;++i)
	{
		x=x+a[i]*t[i];
		ans+=x*t[i]+0.5*a[i]*t[i]*t[i];
	}
	x=0;
	sort(a1,a1+n,cmd);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a1[i]==a[j])
			{
				t1[i]=t[j];
				a[j]=0;
				break;
			}
		}
	}
	for(i=0;i<n;++i)
	{
		x=x+a1[i]*t1[i];
		num+=x*t1[i]+0.5*a1[i]*t1[i]*t1[i];
	}
	printf("%.1lf",num-ans);
	return 0;
}
