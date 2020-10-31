#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
typedef int int_;
#define int long long 
using namespace std;
int a[105];
int_ main(){
	int n,m,ans=0;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(m<=a[2]-a[1])ans+=a[1]+m;
	else if(m>a[2]-a[1]){
		ans+=a[2];
		for(int i=2;i<=n;i++)a[i]-=ans;
		m-=a[2]-a[1];
		sort(a+1,a+n+1);
		if(m<=a[2]-a[1])ans+=a[1]+m;
		else            ans+=a[2];
	}
	printf("%lld",ans);
	return 0;
}
