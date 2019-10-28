#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxn 200010
using namespace std;
double tree[maxn<<2],dp[maxn],dp2[maxn];
double hh[maxn],n,ans,sum,cnt;
//void pushup(int o){
//	tree[o]=tree[o<<1]+tree[o<<1|1];
//}
//void build(int o,int l,int r){
//	if(l==r){
//		tree[o]=hh[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(o<<1,l,mid);
//	build(o<<1|1,mid+1,r);
//	pushup(o);
//}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%lf",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&hh[i]);
		sum+=hh[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
		hh[i]-=sum;
//	build(1,1,n);
	int l=0,r=1;
	for(int r=1;r<=n;r++){
		if(fabs(dp[r-1]+hh[r])>fabs(hh[r])) dp[r]=dp[r-1]+hh[r];
		else dp[r]=hh[r];
		ans=max(fabs(ans),fabs(dp[r]));
	}
	for(int r=1;r<=n;r++){
		if(dp2[r-1]+hh[r]>hh[r]) dp2[r]=dp2[r-1]+hh[r];
		else dp2[r]=hh[r];
		ans=max(ans,dp2[r]);
	}
//	for(int i=1;i<=n*2;i++){
//		ans=max(ans,fabs(tree[i]));
//	}
	printf("%.15lf",ans);
	return 0;
}
// 10 1 3 2 9 10 8 6 7 5 4
