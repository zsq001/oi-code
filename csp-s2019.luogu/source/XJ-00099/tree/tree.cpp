#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int t,n,a[1000010],u,v;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v);
		for(int i=1;i<=n;i++)
			printf("%d",i);
	}
	fclose(stdin);
	fclose(stdout);
}
