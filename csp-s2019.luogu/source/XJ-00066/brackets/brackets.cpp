#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int n, cnt, cen;
long long anss[500005];
struct node {
	int num;
	int c;
}poi[500005];

int head[500005];
struct ed {
	int v, next;
}e[500005];

void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

stack<int> s;

int v[500005];

char t[500005];
int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", t + 1);
	for(int i = 1; i <= n; i++) {
		if(t[i] == '(') {
			poi[i].c = 1;
		}
		else poi[i].c = 0;
	}
	for(int i = 1; i < n; i++) {
		int fa;
		scanf("%d", &fa);
		add(fa, i + 1);
	}
	int maxcen = 0;
	for(int i = 1; i <= n; i++) {
		int val = poi[i].c;
		if(val == 1) {
			s.push(val);
			cen++;
			maxcen = max(maxcen, cen);
//			v[cen]++;
		}
		else {
			if(!s.empty()) {
				v[cen]++;
				cen--;
			}
		}
		for(int j = 1; j <= maxcen; j++) {
			if(v[j] == 0) continue;
			anss[i] += 1LL * ((v[j] * (v[j] + 1)) / 2);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = ans ^ (i * anss[i]);
	}
	printf("%lld", ans);
	return 0;
}
