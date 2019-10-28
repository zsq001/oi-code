#include <stdio.h>
#include <algorithm>
using namespace std;

int a[45000],ans[310];
int main() {
	int n;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	int end = n*(n-1)>>1;
	for (int i = 1; i <= end; i ++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+end);
	int sum = a[1] + a[end],sum1 = 0;
	for (int i = 1; i < n ; i ++) {
		sum1 += a[i];
	}
	ans[1] = (sum1 - sum)/2;
	ans[2] = a[1] - ans[1];
	ans[3] = a[2] - ans[1];
	ans[4] = a[3] - ans[1];
	printf("1\n");
	for (int i = 1; i <= n; i ++) {
		printf("%d ",ans[i]);
	}
	return 0;
}

