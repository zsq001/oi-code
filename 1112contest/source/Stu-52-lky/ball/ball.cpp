#include<cstdio>
#include<iostream>
#include<algorithm>
typedef int int_;
#define int long long 
using namespace std;
int T,ans=0,ret=1,inf=1e18+1;
char s;
int_ main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		cin>>s;
		if(s=='B'){
			ans+=ret;
			if(ans>inf){
				printf("-1");
				return 0;
			}
		}
		ret<<=1;
	}
	printf("%lld",ans);
	return 0;
}
//50
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
