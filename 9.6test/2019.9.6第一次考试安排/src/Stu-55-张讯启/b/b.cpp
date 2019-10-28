#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#define MOD 1000000007
using namespace std;
long long aa[50001],vis[50001];
int solve(int m,int x){//m=2 x=3 
	if(m==1) return 1;
	if(x==1) return 1;
	if(x==0) {
		return 1;
	}
	int p=0;
	int xxx=x;
	while((xxx-=m)>=0&&!vis[m]){
		p++;
		vis[m]=1;
	}
	int k=(-1+(int)sqrt(1+4*(2*x)))/2;//k=2
	for(int j=1;j<=k;j++)
		p=(p+solve(j,x-(int)aa[j]))%MOD;
	return p;
}
int main(){
    freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	int ans=0;
	scanf("%d",&n);
	int t=(-1+(int)sqrt(1+4*(2*n)))/2;
	//int tt=n-t;
	//int maxx=(-1+(int)sqrt(1+4*(2*50000)))/2;
	for(int i=1;i<=t;i++)
	  aa[i]=aa[i-1]+(long long)i;
	for(int i=1;i<=t;i++)
	  ans=(ans+solve(i,n-(int)aa[i]))%MOD;
    ans-=1;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
