#include<cstdio>
#include<algorithm>
using namespace std;
int a[10001],sum1[10001],sum2[10001];
int main(){
	int T,n;
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=2;i<=n;i++){
			sum1[i+1]=sum1[i-1]+a[i+1];
			sum2[i]=sum1[i-2]+a[i];
		}
		if(n<=3){
			if(n==1){
				printf("%d\n",a[1]);
				return 0;
			}
			if(n==2){
				printf("%d\n",abs(a[1]-a[2]));
			}
			if(n==3){
				int b=max(a[1],max(a[2],a[3])),s=min(a[1],min(a[2],a[3])),h=a[1]+a[2]+a[3];
				printf("%d\n",2*b+2*s-h);
			}
		}
	}
}
