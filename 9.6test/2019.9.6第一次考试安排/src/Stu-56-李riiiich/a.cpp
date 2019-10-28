#include<bits/stdc++.h>
#include<cstring>
using namespace std;
typedef long long ll;
ll v[1000010];
bool vv[1000010]={0};
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ll n,m;
	scanf("%lld ",&n);
	ll tot=0;
	ll ans=0;
	ll tot1=0;
	for(int i=1;i<=n;++i){
		scanf("%lld ",&m);
		for(int j=1;j<=m;j++){
			scanf("%lld",&v[j]);
			if(v[j]<3);
			{
				vv[j]=1;
				tot1=tot1+vv[j];
			}
			if(v[j]==3) 
				ans++;
			
			if(v[j]!=3){
			tot=tot+v[j];
	    	if(tot%3==0) ans++;	
			}
		}
		if(tot1==m)
		ans=tot/3;
	printf("%lld\n",ans);
	ans=0;
	tot=0;
	tot1=0;
	}
	return 0;
}
