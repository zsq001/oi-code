#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,less<int> >q[2010];
int first[4010],next[4010],to[4010],tot=0;
int T,n,code[2010],tree[2010];
bool vis[2010];

void add(int x,int y)
{
	to[++tot]=y;
	next[tot]=first[x];
	first[x]=tot;
}

void init()
{
	memset(first,0,sizeof(first));
	memset(next,0,sizeof(next));
	memset(to,0,sizeof(to));
	memset(code,0,sizeof(code));
	memset(tree,0,sizeof(tree));
	memset(vis,0,sizeof(vis));
	
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=first[x];i;i=next[i])
	{
		int y=to[i];
		if(!vis[y])
		{
			dfs(y);
			q[x].push(tree[y]);
			vis[y]=1;
		} 
	}
	//数字在树上的节点：code
	//树上节点的数字：tree 
	while(!q[x].empty())
	{
		int y=q[x].top();
		q[x].pop();
		tree[code[y]]=tree[x];
		tree[x]=y;
		code[y]=x;
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			code[i]=a;
			tree[a]=i;
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
			printf("%d ",tree[i]);
		printf("\n");
		init();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}



//4
//5
//2 1 3 5 4
//1 3
//1 4
//2 4
//4 5
//5
//3 4 2 1 5
//1 2
//2 3
//3 4
//4 5
//5
//1 2 5 3 4
//1 2 
//1 3 
//1 4
//1 5
//10
//1 2 3 4 5 7 8 9 10 6
//1 2
//1 3
//1 4
//1 5
//5 6
//6 7
//7 8
//8 9
//9 10

