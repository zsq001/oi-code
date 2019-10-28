#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
const int mod=100000007;
ll n,cnt,ans=1,vis[100010],v[100010],prime[100010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=2;i<=n;i++){
		if(!vis[i]) prime[++cnt]=i,v[prime[cnt]]++;
		for(ll j=1;i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	v[1]=1;
	//for(ll i=1;i<=cnt;i++) ans=(ans*prime[i])%mod;
	for(ll i=1;i<=n;i++){
		if(v[i]){
			ans=(ans*i)%mod;
			continue;
		}
		ll flag=0,f=1,now=i;
		for(ll j=1;j<=cnt;j++){
			if(now%prime[j]!=0&&f){
				flag++;
				continue;
			}
			if(now%prime[j]==0){
				f=0;
				now/=prime[j];
			}
		}
		if(flag==cnt)ans=(ans*i)%mod;
		if(now&&now!=i) ans=(ans*now)%mod,prime[++cnt]=now;
	}
	printf("%lld",ans%mod);
}
