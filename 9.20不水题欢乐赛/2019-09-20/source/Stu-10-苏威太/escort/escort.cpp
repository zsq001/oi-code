#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n,m,t,s,X;
int a[7000][7000],b[7000];int ans;
void dfs(int q,int z,int p)
{
	if(q==z){
		if(ans==0||ans>p)ans=p;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[q][i]!=0&&b[i]!=1){
			b[i]=1;
			dfs(i,z,p+a[q][i]); 
			b[i]=0;
		}
	}
}
int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	int uu;
	read(n);
	read(m);
	read(t);
	read(s);
	read(X);
	int q;
	int z;
	if(t==1){
		read(q);
		read(z);
		int x,y,c,v;
		for(int i=1;i<=m;++i)
		{
			read(x);
			read(y);
			read(c);
			read(v);
			a[x][y]=c;
			a[y][x]=v;
		}
		b[s]=1;
		dfs(s,q,0);
		uu=0;
		uu+=ans;
		ans=0;
		memset(b,0,sizeof(b));
		b[q]=1;
		dfs(q,z,0);
		uu+=ans; 
	}
	printf("%d",uu);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
