#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
void read(int &x)
{
	int f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,v[65],w[65],c[65],son[65][2],f[32005];
bool mark[65];
int main()
{
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;++i)
	{
		int q;
		read(v[i]),read(w[i]),read(q),c[i]=w[i]*v[i];
		if(q==0) mark[i]=1;
		else
		{
			if(son[q][0]) son[q][1]=i;
			else son[q][0]=i;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(mark[i]==0) continue;
		for(int j=n;j>=v[i];--j)
		{
			f[j]=max(f[j],f[j-v[i]]+c[i]);
			if(son[i][0]&&j>=v[i]+v[son[i][0]]) f[j]=max(f[j],f[j-v[i]-v[son[i][0]]]+c[i]+c[son[i][0]]);
			if(son[i][1]&&j>=v[i]+v[son[i][1]]) f[j]=max(f[j],f[j-v[i]-v[son[i][1]]]+c[i]+c[son[i][1]]);
			if(son[i][0]&&son[i][1]&&j>=v[i]+v[son[i][0]]+v[son[i][1]])
				f[j]=max(f[j],f[j-v[i]-v[son[i][0]]-v[son[i][1]]]+c[i]+c[son[i][0]]+c[son[i][1]]);
		}
	}
	printf("%d",f[n]);
	return 0;
}
