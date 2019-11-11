#include<cstdio>
#include<algorithm>
using namespace std;

int t,n,k;

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int tp;
			scanf("%d",&tp);
		}
		printf("%d\n",(k+1)/2);
	}
	return 0;
}
