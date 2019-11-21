#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

#define ll long long
#define maxn 500005

const ll base=1e9;

int read(){
	int ret=0;char ch=getchar();bool ff=0;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=1; ch=getchar();}
	while(ch>='0'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ff?-ret:ret;
}

int a[maxn],n,p[maxn];
ll ans=1ll<<62;

ll sum(int x){
	ll ret=0;
	for(int i=1;i<=x;i++){
		ret+=1ll*p[i]*p[i];
	}
	return ret;
}

void dfs(int h,int now,int pos){
	if(now==n+1) {
		ans=min(sum(pos),ans);
		return ;
	}
	if(p[pos-1]<h){
		p[pos-1]+=a[now];
		dfs(h,now+1,pos);
	}else {
		if(a[now]<h){
			p[pos-1]+=a[now];
			dfs(p[pos-1],now+1,pos);
			p[pos-1]-=a[now];
			p[pos]=a[now];
			dfs(p[pos-1],now+1,pos+1);
			p[pos]-=a[now];
		}
		else{
			p[pos]=a[now];
			dfs(p[pos],now+1,pos+1);
			p[pos]=0;	
		}
	}
}

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	n=read();int type=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	dfs(0,1,1);
	printf("%lld",ans);
	return 0;
}
