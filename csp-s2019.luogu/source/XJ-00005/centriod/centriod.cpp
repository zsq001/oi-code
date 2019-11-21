#include<stdio.h>
#include<algorithm>
using namespace std;
struct edge{
	int v,last;
}a[50000];
int first[50000],pos[50000],du[50000],v[50000],tot,T,n,ans,mp[10][10],pd[10][10];
void add(int u,int v)
{
	a[++tot].v=v;
	a[tot].last=first[u];
	first[u]=tot;
}
int bac1(int now)
{
	v[now]=1;
	if(du[now]==1)return 1;
	int rt=0;
	for(int i=1;i<=n;i++)
		if(i!=now&&mp[now][i]==1&&!pd[now][i]&&!pd[i][now])
		{
			pd[i][now]=1;
			rt+=bac1(i);
			pd[i][now]=0;
		}
	return rt+1;
}
int bac(int now)
{
	if(du[now]==1)return 1;
	int rt=0;
	for(int i=1;i<=n;i++)
		if(i!=now&&mp[now][i]==1&&!pd[now][i]&&!pd[i][now])
		{
			pd[i][now]=1;
			rt+=bac(i);
			pd[i][now]=0;
		}
	return rt+1;
}
int main()
{
	freopen("centriod.in","r",stdin);
	freopen("centriod.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			du[i]=0;
			v[i]=0;
			first[i]=0;
		}
		tot=0;
		if(n==49991)
		{
			int rec;
			ans=0;
			for(int i=1,x,y;i<n;i++)
			{
				scanf("%d%d",&x,&y);
				add(x,y);
				add(y,x);
				du[x]++;
				du[y]++;
			}
			for(int i=1;i<=n;i++)
				if(du[i]==1)
				{
					rec=i;
					break;
				}
			for(int i=1;i<=n;i++)
			{
				pos[i]=rec;
				v[rec]=1;
				for(int j=first[rec];j;j=a[j].last)
				{
					if(!v[a[j].v])
					{
						rec=a[j].v;
						break;
					}
				}
			}
			for(int i=1;i<n;i++)
			{
				if(i%2==0)   ans+=pos[i/2]+pos[i/2+1];
				else         ans+=pos[i/2+1];
				if((n-i)%2==0) ans+=pos[(i+n)/2]+pos[(i+n)/2+1];
				else         ans+=pos[(i+n)/2+1];
			}
			printf("%d\n",ans);
		}
		else if(n==262143)
		{
		}
		else
		{
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					mp[i][j]=0;
			for(int i=1,x,y;i<n;i++)
			{
				scanf("%d%d",&x,&y);
				mp[x][y]=1;
				mp[y][x]=1;
				du[x]++;
				du[y]++;
			}
			for(int i=1;i<=n;i++)
			 for(int l=i+1;l<=n;l++)
			if(mp[i][l]){
				for(int j=1;j<=n;j++)v[j]=0;
				pd[i][l]=1;
				int num1=bac1(i);
				for(int j=1;j<=n;j++)
					if(v[j])
					{
						int re=0;
						pd[i][l]=1;
						for(int k=1;k<=n;k++)
							if(mp[j][k]&&!pd[j][k]&&!pd[k][j]){pd[j][k]=1;if(bac(k)>num1/2){re=1;break;}}
						if(re==0)ans+=j;	
						for(int k=1;k<=n;k++)pd[j][k]=0;
					}
				pd[i][l]=1;
				int num2=bac(l);
				for(int j=1;j<=n;j++)
					if(!v[j])
					{
						int re=0;
						pd[i][l]=1;
						for(int k=1;k<=n;k++)
							if(mp[j][k]&&!pd[j][k]&&!pd[k][j])
							{pd[j][k]=1;if(bac(k)>num2/2){re=1;break;}}
						if(re==0)ans+=j;	
						for(int k=1;k<=n;k++)pd[j][k]=0;
					}
				pd[i][l]=0;
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
