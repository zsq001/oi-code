#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mod 1000000007


int n;

int minn(int x){
	return (sqrt(1+8*x)-1)/2;
}

int f(int x,int ext){
	int ret=0;
	int mi=minn(x);
	for(int i=min(x,ext);i>=mi;i--){
		if(x-i == 0) ret++;
		else{
			ret+=f(x-i,min(ext,i)-1);
	        ret%=mod;
		}
	}
	return ret%mod;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	int ans=f(n,n+1)%mod;
	printf("%d",ans);
	return 0;
}
