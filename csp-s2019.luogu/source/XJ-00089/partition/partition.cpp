#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#define ll long long
using namespace std;
int n,type;
int a[500010];
ll ans=9223372036854775807;
ll qzh[500010];
ll minn(ll x,ll y){
	return x<y?x:y;
}

void solve(int nowa,ll ft,ll t){
	ll sum=0;
	for(int i=nowa+1;i<=n;i++){
		sum+=a[i];
		if(sum*sum+t>ans&&sum>=ft)return;
		if(t-ft*ft+(ft+sum)*(ft+sum)>ans&&sum<ft)return;
		if(i==n){
			if(sum>=ft)
			ans=sum*sum+t;
			else{
				ans=t-ft*ft+(ft+sum)*(ft+sum);
			}
			return;
		}
		if(i<n){
			if(sum>=ft){
				solve(i,sum,t+sum*sum);
				break;
			}
			else{
				if(qzh[n]-qzh[i]>ft+sum)
				solve(i,ft+sum,t-ft*ft+(ft+sum)*(ft+sum));
			}
		}
			
		
		
	}
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&type);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		qzh[i]=qzh[i-1]+a[i];
	}
	solve(0,0,0);
	printf("%lld",ans);
	return 0;
}
