#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
stack <int> S;
long long a[500010];
int main() {
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,typ;
	scanf("%d%d",&n,&typ);
	if (typ == 1) {
		return 0;
	} else {
		for (int i = 1; i <=n; i++) {
			scanf("%lld",&a[i]);
		}
	}
	a[n+1] = 1<<29;
	S.push(a[1]); 
	for (int i = 2; i <= n; i ++) {
		int l = S.top();
		if (l <= a[i]) {
			S.push(a[i]);
		} else {
			if (l+a[i] < a[i]+a[i+1]) {
				int k = S.top();
				k += a[i];
				S.pop();
				S.push(k);
				continue;
			} else {
				int k = S.top();
				int kp = 0;
				while (kp < k) {
					kp += a[i];
					i ++;
				}
				i--;
				S.push(kp);
				continue;
			}
		}
	}
	long long fans = 0;
	while(!S.empty()) {
		long long pran = S.top();
		fans +=  pran * pran;
		S.pop();
	}
	printf("%lld",fans);
	return 0;
}

/*
5 0
5 1 7 9 9

10 0
5 6 7 7 4 6 2 13 19 9

*/
