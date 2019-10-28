#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 500050
int n,m,maxx=0;
int f[maxn];
struct node{
	int v,p;
}a[maxn];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
void tx()
{
	int sum=0,x=0;
	for(int i=1;i<=n;i++)
	{
		if(x==m)break;
		if(f[a[i].p]==1)continue;
		sum+=a[i].v;
		x++;
		if((a[i].p)!=1&&(a[i].p)!=n)
		{
			f[a[i].p+1]=1;
			f[a[i].p-1]=1;
		}
		else
		{
			if((a[i].p)==1)
			{
				f[n]=1;
				f[2]=1;
			}
			if(a[i].p==n)
			{
				f[n-1]=1;
				f[1]=1;
			}
		}
	}
	if(sum>maxx)maxx=sum;
	return ;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(2*m>n)
	{
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	tx();
	printf("%d",maxx);
}
