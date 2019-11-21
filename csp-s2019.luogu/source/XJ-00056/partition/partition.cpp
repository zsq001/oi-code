#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,type,a[500005],fa[500005],l[500005],r[500005];
long long ans,last,sum[500005];
bool vis[500005];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	read(n),read(type);
	if(type==0)
	{
		for(int i=1;i<=n;++i)
		{
			int f;
			read(a[i]),fa[i]=i,sum[i]=a[i],l[i]=i,r[i]=i;
			if(a[i]<sum[f=getfa(i-1)])
				fa[i]=f,sum[f]+=sum[i],r[f]=i;
		}
		for(int i=1;i<=n;++i)
		{
			int f=getfa(i);
			if(vis[f]) continue;
			int x=l[f],leff=getfa(l[f]-1),ff=getfa(l[leff]-1),rigf=getfa(r[f]+1),rig=r[rigf];
			while(leff&&sum[f]<sum[leff]&&getfa(leff)!=f)
			{
				int k=a[--x];
				if(sum[leff]-k<sum[ff]) break;
				sum[leff]-=k,sum[f]+=k;
				fa[x]=f,l[f]=x;
			}
			x=r[f];
			while(rigf&&sum[f]<sum[leff]&&getfa(rig)!=f)
			{
				int k=a[++x];
				sum[rigf]-=k,sum[f]+=k,fa[x]=f,r[f]=x;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)
		{
			int f=getfa(i);
			if(vis[f]) continue;
			ans+=sum[f]*sum[f],vis[f]=1;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
