#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define mod 1000000007
int fie[1010],sum[1010],num[1001];
void init(){
	fie[1]=fie[2]=1;
	for(int i=3;i<=150;i++){
		fie[i]=(fie[i-1]+fie[i-2])%mod;
	}
}
int find(int x){
	if(fie[x])return fie[x];
	return fie[x]=(find(x-1)+find(x-2))%mod;
}
int main(){
	int n,m;
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d%d",&n,&m);
	int b=150;
	init();
//	int sq=sqrt(n*1.0);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
//		sum[i/sq+1]=(fie[num[i]]+sum[i/sq+1])%mod;
	}
	int op,l,r,z;
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=0;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%d",&z);
			for(int j=l;j<=r;j++){
//				sum[j/sq+1]-=num[j];
				num[j]+=z;
//				sum[j/sq+1]=(sum[j/sq+1]+find(num[j]))%mod;
			}
		}
		else{
		//	if((r-l+1)<sq){
				for(int j=l;j<=r;j++){
					if(num[j]>b){
						b=num[j];
						fie[num[j]]=find(num[j]);
					}
					ans=(ans+fie[num[j]])%mod;
				}
					
		//	}
//			int ql=l/sq+1+(l%sq!=0),qr=r/ql+1-((r+1)%sq!=0);
//			for(int j=ql;j<=qr;j++){
//				ans=(ans+sum[j])%mod;
//			}
//			for(int j=l;j<(ql-1)*sq;j++)
//				ans=(ans+fie[num[j]])%mod;
//			for(int j=qr*sq;j<=r;j++){
//				ans=(ans+fie[num[j]])%mod;
//			}
			printf("%d\n",ans);
		}
	}
}
