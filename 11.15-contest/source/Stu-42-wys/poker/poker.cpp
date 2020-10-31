#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

long long n, m, ans;
long long c[55], vis[55];
priority_queue<long long> q;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(register int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
		q.push(c[i]);
	}
	c[n + 1] = m;
	q.push(m);
	while(q.size() > 2) {
		long long x1 = q.top(); q.pop();
		long long x2 = q.top(); q.pop();
		long long x3 = q.top(); q.pop();
		x1 -= x3;
		x2 -= x3;
		ans += x3;
		if(x1 != 0) q.push(x1);
		if(x2 != 0) q.push(x2);
	}
	printf("%lld", ans);
	return 0;
}
