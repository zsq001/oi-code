#include<cstdio>
#include<iostream>
#include<algorithm>
typedef int int_;
#define int long long
using namespace std;
int a[5],x,T,ans=0,n;
int_ main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(int i=0;i<=3;i++)a[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%I64d",&x);
			a[x%3]++;
		}
		ans+=a[0];
		if(a[1]>a[2]){
			ans+=a[2];
			a[1]-=a[2];
			ans+=a[1]/3;
		}
		else {
			ans+=a[1]-a[2];
			a[2]-=a[1];
			ans+=a[2]/3;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
