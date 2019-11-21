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
	int l1;
	int l2;
	int nn;
}a[2001];
int t;
int he;
int n,m;
int b[2001];
int k[2001];
bool pp[2001][2001];
int oo;
int o=1;
void dfs(int p)
{
	if(a[p].l2==0&&p!=he)return;
	b[o]=a[p].nn;
	if(b[o]==1)oo=o;
	++o;
	k[p]=1;
	if(k[a[p].l1]==0)dfs(a[p].l1);
	else dfs(a[p].l2);
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	read(t);
	while(t!=0)
	{
		--t;
		read(n);
		for(int i=1;i<=n;++i)
		{
			int r;
			read(r);
			a[r].nn=i;	
		}
		for(int i=1;i<n;++i)
		{
			int xx,yy;
			read(xx);
			read(yy);
			if(a[xx].l1==0)a[xx].l1=yy;
			else a[xx].l2=yy;
			if(a[yy].l1==0)a[yy].l1=xx;
			else a[yy].l2=xx;
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i].l1==0||a[i].l2==0){
				he=i;
				break;
			}
		}
		dfs(he);
		printf("1 ");
		for(int i=1;i<=n;++i)
		{
			if(b[i]!=1)printf("%d ",a[i].nn);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
