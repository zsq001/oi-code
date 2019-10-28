#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 200010
#define null 0
#include<algorithm>
using namespace std;

int fa[maxn],Left[maxn],Right[maxn],size[maxn],t[maxn];

template<class T> inline void read(T &x)
{
    x=0;
    register char c=getchar();
    register bool f=0;
    while (!isdigit(c)) f ^=c=='-',c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}

template <class T> inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar('0'+x%10);
}

void dad(int x,int y)
{
	if(t[y]==1)
	{
		t[y]=0;
		t[x]=1;
	}
	else
	{
		if(Right[fa[y]]==y)	Right[fa[y]]=x;
		else Left[fa[y]]=x;
	}
	fa[x]=fa[y];
}

void L(int x)
{
	int p=fa[x];
	dad(x,p);
	size[x]=size[p];
	size[p]=size[Left[p]]+size[Left[x]]+1;
	fa[Left[x]]=p;
	Right[p]=Left[x];
	Left[x]=p;
	fa[p]=x;
}

void R(int x)
{
	int p=fa[x];
	dad(x,p);
	size[x]=size[p];
	size[p]=size[Right[p]]+size[Right[x]]+1;
	fa[Right[x]]=p;
	Left[p]=Right[x];
	Right[x]=p;
	fa[p]=x;
}

void ping(int x)
{
	while(t[x]!=1)
	{
		int p=fa[x];
		if(t[p]==1)
		{
			if(x==Left[p]) R(x);
			else L(x);
			break;
		}
		else if(p==Right[fa[p]])
		{
			if(x==Right[p])
			{
				L(p);
				L(x);
			}
			else 
			{
				R(x);
				L(x);
			}
		}
		else 
		{
			if(x==Left[p])
			{
				R(p);
				R(x);
			}
			else
			{
				L(x);
				R(x);
			}
		}
	}
}

void acc(int x)
{
	ping(x);
	int u=fa[x];
	size[x]-=size[Right[x]];
	t[Right[x]]=1;
	Right[x]=null;
	while(u!=null)
	{
		ping(u);
		t[Right[u]]=1;
		size[u]=size[u]-size[Right[u]]+size[x];
		Right[u]=x;
		t[x]=0;
		x=u;
		u=fa[u];
	}
}


int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int n,l,r,m,p;
	memset(Right,0,sizeof(Right));
	memset(Left,0,sizeof(Left));
	size[0]=0;fa[0]=0;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(p);
		if((i+p)<=n)fa[i]=i+p;
		else fa[i]=null;
		t[i]=size[i]=1;
	}
	read(m);
	while(m--)
	{
//		Left[maxn]={0};
//		Right[maxn]={0};
		read(l);
		if(l==1)
		{
			read(r);
			r++;
			acc(r);
			ping(r);
			//if(size[Left[r]]+1==n) size[Left[r]]-=1;
			printf("%d\n",size[Left[r]]+1);
		}
		else if(l==2)
		{
			read(l);read(r);
			l++;
			ping(l);
			fa[Left[l]]=fa[l];
			t[Left[l]]=1;
			size[l]-=size[Left[l]];
			if((l+r)<=n) fa[l]=l+r;
			else fa[l]=null;
		}
	}
	return 0;
}
