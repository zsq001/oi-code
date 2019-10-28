#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[3];
int main(){
	int T;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n,x;
		int ans=0;
		a[1]=a[2]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x%3)a[x%3]++;
			else ans++;
		}
		if(a[1]<a[2])swap(a[1],a[2]);
		ans+=a[2]+(a[1]-a[2])/3;
		printf("%d\n",ans);
	}
	
}
