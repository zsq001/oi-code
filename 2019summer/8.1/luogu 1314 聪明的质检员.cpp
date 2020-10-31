#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cmath>
#define ll long long
#define maxn 200010
using namespace std;
int n,m,w[maxn],v[maxn],L[maxn],R[maxn];
ll s,tmp,t1[maxn],t2[maxn],ans=1ll<<62;
ll cal(int line)
{
	for(int i=1;i<=n;++i){
		t1[i]=t1[i-1];
		t2[i]=t2[i-1];
		if(w[i]>=line){
			t1[i]+=v[i];
			t2[i]++;
		}
	}
	ll ret=0;
	for(int i=1;i<=m;++i) ret+=(t2[R[i]]-t2[L[i]-1])*(t1[R[i]]-t1[L[i]-1]);
	return ret;
}
int main()
{
	int l=0,r=0;
	scanf("%d%d%lld",&n,&m,&s);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&w[i],&v[i]);
		r=max(r,w[i]+1);
	}
	for(int i=1;i<=m;++i) scanf("%d%d",&L[i],&R[i]);
	while(l<=r){
		int mid=(1ll*l+r)>>1;
		tmp=cal(mid);
		if(tmp==s){
			ans=0;
			break;
		}
		if(tmp>s){
			l=mid+1;
			ans=min(ans,tmp-s);
		}
		else{
			r=mid-1;
			ans=min(ans,s-tmp);
		}
	}
	printf("%lld",ans);
	return 0;
}
