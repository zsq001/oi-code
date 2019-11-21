#include <bits/stdc++.h>
const int MAXN = 100050;
using namespace std;
struct node {
	int l, r;
}res[MAXN];
int n, cnt, fa, ans;
char s[MAXN];
bool cmp(node a, node b) {
	if(a.l == b.l)
		return a.r < b.r;
	return a.l < b.l;
}
bool check1(int x, int y) { return res[x].l <= y; }
bool check2(int x, int y) { return res[x].r <= y; }
int solve(int yyy) {
	int l = 1, r = cnt, ans1 = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check1(mid, yyy)) {
			ans1 = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	if(ans1 == -1)
		return 0;
	l = 1, r = ans1;
	int ans2 = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check2(mid, yyy)) {
			ans2 = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	if(ans2 == -1)
		return 0;
	return ans2;
}
int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d %s", &n, s + 1);
	if(s[1] == ')') {
		cout << "0" << endl;
		return 0;
	}
	for(int i = 1; i <= n - 1; i++)
		scanf("%d", &fa);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i++) {
		for(int j = i + 1; j <= len; j++) {
			if(s[i] == '(' && s[j] == ')') {
				res[++cnt] = (node){i, j};
			}
		}
	}
	sort(res + 1, res + cnt + 1, cmp);
	for(int i = 1; i <= n; i++) {
		int ress = solve(i);
		ans ^= (i * ress);
	}
	cout << ans << endl;
	return 0;
}
