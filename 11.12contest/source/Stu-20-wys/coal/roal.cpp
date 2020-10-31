#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, last;
int ty[200005], a[200005];
double k, c, w;
double ans;

void dfs(int step, double w, double sum) {
	if(sum < 0 || (step > last && sum < ans)) return ;
	if(step == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	for(int i = 1; i >= 0; i--) {
		if(i == 1) {
			if(ty[step] == 1)
				dfs(step + 1, w * ((100.00 - k) / 100.00), sum + a[step] * w);
			if(ty[step] == 2) 
				dfs(step + 1, w * ((100.00 + c) / 100.00), sum - a[step] * w);
		}
		else dfs(step + 1, w, sum);
	}
	return ;
}

int main() {
	freopen("roal.in", "r", stdin);
	freopen("roal.out", "w", stdout);
	scanf("%d%lf%lf%lf", &n, &k, &c, &w);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &ty[i], &a[i]);
		if(a[i] == 1) last = i;
	}
	dfs(1, w, 0);
	printf("%.2lf", ans);
	return 0;
}
