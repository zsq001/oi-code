#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100010],sum1,sum2,maxx;
bool f;
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		sum1=sum2=f=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(n==1){
				printf("%d\n",a[i]);
				f=1;
			}
			if(i%2==1) sum1+=a[i];
			if(i%2==0) sum2+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(f) continue;
		if(sum1<sum2) swap(sum1,sum2);
		printf("%d\n",sum1-sum2);
	}
	return 0;
}
