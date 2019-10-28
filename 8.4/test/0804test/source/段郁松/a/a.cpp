#include<stdio.h>
int map[200005],mapp[200005];
int n,m;
int maxn=-10000;
long long int num=-214748364;
int read()
{
	int data=0,w=1;
	char d;
	d=getchar();
	while(d<'0'||d>'9')
	{
		if(d=='-') w=-1;
		d=getchar();
	}
	while(d>='0'||d<='9')
	{
		data=(data<<3)+(data<<1)+d-'0';
		d=getchar();
	}
	return data*w;
}
void work(int x,int d,long long maxx)
{
	int i,j,k;
	if(d>=m)
	{
		if(maxx>=m)
		{
			num=maxx;
		}
		return ;
	}
	if(x>n)
	{
		return ;
	}
	if(x==1&&mapp[2]==0&&mapp[1]==0&&mapp[n]==0||x==n&&mapp[n-1]==0&&mapp[1]==0&&mapp[n]==0||x>1&&x<n&&mapp[x]==0&&mapp[x-1]==0&&mapp[x+1]==0)
	{
		mapp[x]=1;
		work(x+1,d+1,maxx+map[x]);
		mapp[x]=0;
	}
	work(x+1,d,maxx);
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		map[i]=read();
		if(map[i]>maxn) maxn=map[i];
	}
	if(m>n/2) 
	{
		printf("Error!");
		return 0;
	}
	else if(m==1) 
	{
		printf("%d",maxn);
		return 0;
	}
	else 
	{
		work(1,0,0);
		printf("%lld",num);
	}
	return 0;
}
