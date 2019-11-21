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
const int MOD=998244353;
int a[101][2001];
int n,m;
int c[2001];
long long ans;
void dfs(int q,int e,long long pp,int biao)
{
	
	if(biao==q){
		int k=1;
		while(k<=m){if(c[k]>q/2)return;++k;}
		ans+=pp;
		ans%=MOD;
 		return;
	}
	if(e>n)return;
	for(int i=1;i<=m;++i)
	{
		if(a[e][i]!=0){
			++c[i];
			dfs(q,e+1,pp*a[e][i],biao+1);
			--c[i];
		}
		
	}
	if(e<n)dfs(q,e+1,pp,biao);
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		 {
		 	read(a[i][j]);
		 }
	}
	for(int i=2;i<=n;++i)
	{
		dfs(i,1,1,0);
	}
	printf("%lld",ans%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
