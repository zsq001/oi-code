#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int T,n;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		int a,n,tot = 0,cnt1 = 0,cnt2 = 0;
		scanf("%d",&n);
		for (int i = 1; i <= n ; i++) {
			scanf("%d",&a);
			a = a % 3;
			if (a == 0) {
				tot ++;
			} else if (a == 1) {
				cnt1 ++;
			} else {
				cnt2++;
			}
		}
		int in;
		if (cnt1 < cnt2) {
			in = cnt1;
			cnt1 = 0;
			cnt2 -= cnt1;
		} else {
			in = cnt2;
			cnt2 = 0;
			cnt1 -= cnt2;
		}
		tot += in;
		if (cnt1 == 0) {
			tot += cnt2/3;
		} else if (cnt2 == 0) {
			tot += cnt1/3;
		}
		printf("%d\n",tot);
	}
	return 0;
}
