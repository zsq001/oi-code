#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
#define ll long long
#define lson (o<<1)
#define rson (o<<1|1)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int maxn=1e6+5,maxm=0+5,inf=2e9+7,mod=1e9+7;
const ll INF=1LL<<60;
const double eps=1e-9,pi=acos(-1);
inline int read(){
	char ch=getchar();int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char _____team[100];
void print(ll x,char ch='\n'){
	if(x==0){putchar('0');putchar(ch);return;}
	if(x<0)putchar('-'),x=-x;
	//if(x<0){printf("9223372036854775808");putchar(ch);return;}
	int _____top=0;
	while(x){_____team[++_____top]=(x%10)+'0';x/=10;}
	REP(i,_____top,1)putchar(_____team[i]);putchar(ch);
}
int t[maxn];
int main(){
	freopen("huazhong.in","r",stdin);
	freopen("huazhong.out","w",stdout);
	int n=read(),cnt=0;
	for(int i=1;i<n;++i)++t[read()],++t[read()];
	for(int i=1;i<=n;++i)if(t[i]>1)++cnt;
	ll tt=1,ans=0;
	for(int i=1;i<=cnt;++i)tt=(tt<<1)%mod;
	ans=tt*cnt%mod;
	if(n>1)tt=(tt<<1)%mod;
	ans=(ans+tt*(n-cnt)%mod)%mod;
	print(ans);
}