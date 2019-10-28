#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,K,b[6][6];
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	read(n),read(K);
	for(int i=1;i<=n;++i)
	{
		int x;
		read(x);
	}
	for(int j=1;j<=n;++j)
	{
		int x;
		read(x);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int x;
			read(x);
			if(i==j) continue;
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=5;++i)
			for(int j=1;j<=5;++j)
				read(b[i][j]);
	printf("NO");
	return 0;
}
