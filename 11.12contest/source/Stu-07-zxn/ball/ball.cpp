#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 55
const int inf=1e18;
int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

ll f[maxn];
int c[maxn];

void init(int n){
	f[1]=1ll;
	for(int i=2;i<=n;i++) f[i]=2ll*f[i-1]+1ll;
//	printf("%lld ",f[i]);
//	printf("%lld",inf);
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n=in(),ans=0;
	init(n);
	for(int i=1;i<=n;i++){
		c[i]=(getchar()=='B'?1:0);
	}
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<n&&c[now]==0) now++;
		if(now==n&&c[now]==0) break;
		ans+=f[now-1]+1;
		if(ans>inf||ans<0) {
			puts("-1");
			return 0;
		}
		c[now]=0;
	}
	printf("%d",ans);
	return 0;
}
//3
//RBR
