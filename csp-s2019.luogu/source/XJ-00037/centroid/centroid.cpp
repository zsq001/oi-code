#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int tree[250030],num[250030];
int main() {
	int T,n;
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i = 1; i < n; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			tree[u] = i;
			tree[v] = i+1;
		}
		for (int i = 1;i <= n; i++) {
			num[tree[i]] = (long long)i;
		}
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			long long lm = (i+1) >>1;
			ans += (long long)num[lm];
			if ((i+1)&1) ans += (long long)num[lm+1];
			long long lr = (i+1+n) >>1;
			ans += (long long)num[lr];
			if ((i+1+n)&1) ans += (long long)num[lr+1];
//			printf("%d\n",num[lm]);
//			printf("%d\n",num[lr]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
11
7 8
8 6
6 10
10 3
3 5
5 4
4 9
9 1
1 11
11 2


*/
