#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T,n,k;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++){
			int x;
			scanf("%d",&x);
		}
		printf("%d\n",(n+1)/2);
	}
	return 0;
}
