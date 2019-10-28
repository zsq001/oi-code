#include <cstdio>
#include <algorithm>
using namespace std;
int barx[2005],bary[2005],num[1010];
int main() {
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	while (T--) {
		int flag=0;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) num[i] = i;
		for (int i = n+1; i <= ((n<<1)-1); i++) num[i] = num[i-1]-1;
		for (int i = 1; i <= (n<<1)-2; i++) {
			scanf("%d%d",&barx[i],&bary[i]);
			if (i == ((n<<1)-1)) break;
			if (flag) continue;
			int k=barx[i]+bary[i]-1;
			for (int j = k; j <= (n<<1)-1; j++) num[j]--;
			if (num[k] <= 0 && i < k-1) {
				flag = 1;
				continue;
			}
		}
		if (flag) {
			printf("No\n");
			continue;
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
