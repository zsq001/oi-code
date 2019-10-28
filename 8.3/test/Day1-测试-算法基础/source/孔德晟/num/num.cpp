#include<stdio.h>
typedef int int_;
#define int long long
int num[1000010];
int_ main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
//	if(n<=10000&&m<=10000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				num[i*j]++;
		int hh=0,cnt=0;
		while(hh<k){
			hh+=num[++cnt];
		}
		printf("%lld",cnt);
//	}
	return 0;
}
