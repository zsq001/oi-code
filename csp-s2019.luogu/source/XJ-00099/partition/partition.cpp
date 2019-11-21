#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
long long n,m,a[1000001],ans,f[1000001],sum[1000001];
void dp(long long x,long long op){
	if(op==0){
		f[x]=f[x-1]+a[x]*a[x];
		if(f[x]>f[x-2]+(a[x-1]+a[x])*(a[x-1]+a[x])&&f[x-1]+(a[x+1]+
		   a[x])*(a[x+1]+a[x])>f[x-2]+(a[x-1]+a[x])*(a[x-1]+a[x]))
		{
			f[x]=f[x-2]+(a[x-1]+a[x])*(a[x-1]+a[x]);
			f[x-1]=f[x-2];	
			a[x]=a[x-1]+a[x];
			a[x-1]=a[x-2];
		}
		else if(f[x]>f[x-1]+(a[x+1]+a[x])*(a[x+1]+a[x])&&f[x-2]+(a[x-1]+
			    a[x])*(a[x-1]+a[x])>f[x-1]+(a[x+1]+a[x])*(a[x+1]+a[x]))
		{
			f[x+1]=f[x-1]+(a[x+1]+a[x])*(a[x+1]+a[x]);
			f[x]=f[x-1];
			a[x+1]=a[x]+a[x+1];
			a[x]=a[x-1];
		}
	}
	else{
		if(f[x-1]+(a[x+1]+a[x])*(a[x+1]+a[x])>
		   f[x-2]+(a[x-1]+a[x])*(a[x-1]+a[x]))
		{
			f[x]=f[x-2]+(a[x-1]+a[x])*(a[x-1]+a[x]);
			f[x-1]=f[x-2];	
			a[x]=a[x-1]+a[x];
			a[x-1]=a[x-2];
		}
		else 
		{
			f[x+1]=f[x-1]+(a[x+1]+a[x])*(a[x+1]+a[x]);
			f[x]=f[x-1];
			a[x+1]=a[x]+a[x+1];
			a[x]=a[x-1];
		}
	}
		
}


void solve(long long x){
	for(int i=x;i<=n;i++){
		if(a[i]<a[i-1]) 
			dp(i,1);
		else dp(i,0);
	}
}


int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int op;
	scanf("%lld%lld",&n,&op);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	solve(1);
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
