#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=255;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,c,v[N],f[2][N][N];
int main()
{
	freopen("roadtoll.in","r",stdin);
	freopen("roadtoll.out","w",stdout);
	read(n),read(m),read(c);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			f[0][i][j]=1<<30,f[1][i][j]=-1;
	for(int i=1;i<=n;++i) read(v[i]);
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		read(x),read(y),read(z);
		if(f[0][x][y]>z+max(v[x],v[y]))
		{
			f[0][x][y]=f[0][y][x]=z+max(v[x],v[y]);
			f[1][x][y]=f[1][y][x]=max(v[x],v[y]);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==j) continue;
			for(int k=1;k<=n;++k)
			{
				if(k==i||k==j) continue;
				if(f[0][i][j]>f[0][i][k]-f[1][i][k]+f[0][k][j]-f[1][k][j]+max(f[1][i][k],f[1][k][j]))
				{
					f[0][i][j]=f[0][j][i]=f[0][i][k]-f[1][i][k]+f[0][k][j]-f[1][k][j]+max(f[1][i][k],f[1][k][j]);
					f[1][i][j]=f[1][j][i]=max(f[1][i][k],f[1][k][j]);
				}
			}
		}
	while(c--)
	{
		int x,y;
		read(x),read(y);
		printf("%d\n",f[0][x][y]);
	}
	return 0;
}
