#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int b,n,d,m,p[100005][3],ans;
int calc(int x,int y)
{
	int del=0;
	for(int i=0;i<b;++i) del+=abs(p[x][i]-p[y][i]);
	return del;
}
void solve1()
{
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(calc(i,j)<=d) ++ans;
	printf("%d\n",ans);
}
int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	read(b),read(n),read(d),read(m);
	for(int i=1;i<=n;++i)
		for(int j=0;j<b;++j)
			read(p[i][j]);
	if(n<=100) solve1();
	return 0;
}
