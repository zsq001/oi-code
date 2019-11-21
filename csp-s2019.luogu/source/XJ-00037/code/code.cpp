#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
int a[100010];
stack <int> S;
int ksm(int a,int x) {
	int ans = 1,base = a;
	while (x) {
		if (x & 1) {
			ans *= base;
		}
		x >>= 1;
		base = base * base;
	}
	return ans;
}

void pri(int n,int k) {
	int sum = 0;
	int kp = a[k+1];
	while (kp) {
		sum ++;
		int fl = 1;
		fl = fl & kp;
		S.push(fl); 
		kp >>= 1;
	}
	sum = n - sum;
	for (int i = 1; i <= sum; i++) {
		printf("0");
	}
	while (!S.empty()) {
		printf("%d",S.top());
		S.pop();
	}
}
int main() {
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if (k >= ksm(2,n)) return 0;
	if (n <= 10) {
		a[1] = 0;
		a[2] = 1;
		int last = 3;
		for (int i = 2; i <= n; i++) {
			int maxn = ksm(2,i-1);
			for (int z = 1; z < last; z ++) {
				int val = a[z] + maxn;
				S.push(val);
			}
			while (maxn) {
				a[last] = S.top();
				S.pop();
				last ++;
				maxn --;
			}
		}
		pri(n,k);
	}
	return 0;
}
