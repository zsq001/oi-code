#include<stdio.h>
#include<string.h>
#define maxn (5010)
#define lenth (110)
#include<algorithm>
using namespace std;

int n,type,cnt,lens,lenans;
long long int a[maxn],b[maxn];
int s[lenth],ans[lenth],c[lenth];

void multi(int x)
{
	memset(s,0,sizeof(s));
	lens=0;
	int len=0;
	while(x)
	{
		len++;
		c[len]=x%10;
		x/=10;
	}
	lens=len*2;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			s[i+j-1]+=c[i]*c[j];
		}
	}
	int q=0;
	for(int i=1;i<=lens;i++)
	{
		s[i]+=q;
		q=s[i]/10;
		s[i]%=10;
	}
	while(s[lens]==0)lens--;
}

void add( )
{
	lenans=lens+lenans;
	for(int i=1;i<=lenans;i++)
	{
		ans[i]=ans[i]+s[i];
	}
	int q=0;
	for(int i=1;i<=lenans;i++)
	{
		ans[i]+=q;
		q=ans[i]/10;
		ans[i]%=10;
	}
	while(ans[lenans]==0)lenans--;
}

int main ( )
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&type);
	if(type==0)
	{
		for(int i=1;i<=n;i++)
		    scanf("%I64d",&a[i]);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<b[cnt])
			{
				if((a[i]+b[cnt]<=a[i]+a[i+1]&&a[i]+b[cnt]<=a[i+1])||i==n)b[cnt]+=a[i];
				else a[i+1]+=a[i];
			}
			else b[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++)
		{
			multi(b[i]);
			add();
		}
		for(int i=lenans;i>=1;i--)
		    printf("%d",ans[i]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
//我猜这是动归 但是我不会 所以写了贪心 但并不对 
