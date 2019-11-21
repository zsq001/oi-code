#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod=998244353;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,ans,cnt[5];
int a[105][2005];
//void solve1()
//{
//	
//}
bool check()
{
	cnt[4]=cnt[1]+cnt[2]+cnt[3];
	if(cnt[4]==0) return 0;
	for(int i=1;i<=3;++i)
		if(cnt[i]>((int)(cnt[4]/2.))) return 0;
	return 1;
}
void dfs(int x,int y)
{
	if(check()) ++ans;
	if(x>n||y>m) return;
	for(int i=1;i<=a[x][y];++i)
	{
		cnt[y]+=i;
		dfs(x+1,1);
		cnt[y]-=i;
	}
	dfs(x,y+1),dfs(x+1,1);
}
void solve2()
{
	dfs(1,1);
	printf("%d\n",ans);
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(a[i][j]);
	if(n<=10) solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
