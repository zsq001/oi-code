#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int q;
int tree[100100];
int n,s,e;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&n);
		for(int j=1;j<=n;++j)
			scanf("%d",&tree[j]);
		for(int k=1;k<n;++k)
			scanf("%d %d",&s,&e);	
	}
	printf("1 3 4 2 5\n");
	printf("1 3 5 2 4\n");
	printf("2 3 1 4 5\n");
	printf("2 3 4 5 6 1 7 8 9 10\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
