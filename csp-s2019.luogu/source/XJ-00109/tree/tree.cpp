#include<bits/stdc++.h>
#define maxn (2010)
using namespace std;

struct node{
	int x,y;
	bool visit;
}E[maxn];

int a[maxn],s[maxn];
int T,n;

void check()
{
	/*for(int i=1;i<=n;i++)
	    printf("%d ",a[i]);
	printf("\n");*/
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>s[i])
		{
			flag=false;
			break;
		}
		if(a[i]<s[i])
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		    s[i]=a[i];
	}
	return;
}

void dfs(int x)
{
	if(x==0)
	{
		check();
		return ;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(E[i].visit)continue;
		int xs=a[E[i].x];
		int ys=a[E[i].y];
		swap(a[E[i].x],a[E[i].y]);
		E[i].visit=true;
		dfs(x-1);
		E[i].visit=false;
		a[E[i].x]=xs;
		a[E[i].y]=ys;
	}
}

int main ( )
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int b;
		memset(a,0,sizeof(a));
		memset(s,9,sizeof(s));
		for(int i=1;i<=maxn;i++)
		{
			E[i].x=0;
			E[i].y=0;
			E[i].visit=false;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b);
			a[b]=i;
		}
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d %d",&E[i].x,&E[i].y);
		}
		dfs(n-1);
		for(int i=1;i<=n;i++)
		    printf("%d ",s[i]);
		printf("\n");
	}
	//想不到吧都是错的
	//但我还是要交
	//#快乐分母的基本素养（不是 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
