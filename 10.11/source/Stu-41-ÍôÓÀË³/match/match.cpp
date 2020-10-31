#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, x, y, a[100009], b[100009], num1[100009], num2[100009];

int jud(int p, int q)
{
	if(a[p] - x <= b[q] && b[q] <= a[p] + y) return 0;
	else if(b[q] < a[p] - x) return 1;
	else return -1;
}

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	if(x == 0 && y == 0) {
		int l = 1, r = 1, ans = 0;
		while(l <= n && r <= m) {
			if(a[l] == b[r]) ans++, l++, r++;
			else if(a[l] <= b[r]) l++;
			else r++;
		}
		printf("%d", ans);
	}
	else {
		int l = 1, r = 1, ans = 0;
		while(l <= n && r <= m) {
			if(jud(a[l], b[r]) == 0) ans++, l++, r++;
			else if(jud(a[l], b[r]) == 1) r++;
			else l++;
		}
		printf("%d", ans);
	}
}
