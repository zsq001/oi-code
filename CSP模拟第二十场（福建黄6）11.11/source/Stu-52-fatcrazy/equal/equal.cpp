#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
struct node{
	int v;
	int next;
}e[100010<<1];
int tot;
int n,m,c;
int head[100010],de[100010],fa[100010][25];
int si[100010],ca,len,ans,f,v,u,q;
void add(int u,int v)
{
	e[++tot].next=head[u];
	e[tot].v=v;
	head[u]=tot;
}
void dfs(int u,int f)
{
	fa[u][0]=f;
	for(int i=1;i<=20;++i)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].v!=f){
			de[e[i].v]=de[u]+1;
			dfs(e[i].v,u);
			si[u]+=si[e[i].v];
		}
	}
}
int  ll(int x,int y)
{
	if(de[x]<de[y])swap(x,y);
	for(int i=20;i>=0;--i)
	{
		if((1<<i)&(de[x]-de[y]))x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;--i)
	 if(fa[x][i]!=fa[y][i]){
	 	x=fa[x][i];
	 	y=fa[y][i];
	 }
	 return fa[x][0];
}
int main()
{
	freopen("equal.in","r",stdin);
 	freopen("equal.out","w",stdout);
	read(n);
	int qq;
	int ww;
	for(int i=1;i<n;++i)
	{
		read(qq);
		read(ww);
		add(qq,ww);
		add(ww,qq);
	}
	for(int i=1;i<=n;++i)
	{
		si[i]=1;
	}
	de[1]=0;
	dfs(1,0);
	read(m);
	while(m--)
	{
		read(qq);
		read(ww);
		if(qq==ww){
			printf("%d\n",n);
			continue;
		}
		c=ll(qq,ww);
		len=de[qq]+de[ww]-de[c]*2;
		if(len&1){
			printf("0\n");
			continue;
		}
		if(de[qq]<de[ww])swap(qq,ww);
		int d=len/2;
		if(de[qq]==de[ww]){
			q=qq;
			f=ww;
			for(int i=20;i>=0;--i)
			 if((d-1)&(1<<i))q=fa[q][i];
			for(int i=20;i>=0;--i)
			 if((d-1)&(1<<i))f=fa[f][i];
			ans=n-si[q]-si[f];
		}
		else {
			q=f=qq;
			for(int i=20;i>=0;--i)
			 if(d&(1<<i))q=fa[q][i];
			for(int i=20;i>=0;--i)
			 if((d-1)&(1<<i))f=fa[f][i];
			ans=si[q]-si[f];
		}
		printf("%d\n",ans);
	}
	return 0;
}
