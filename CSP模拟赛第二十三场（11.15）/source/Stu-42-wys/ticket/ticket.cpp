#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int L, c, sum;
int judyuan[30] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,};
char a[30], ans[20];

void dfs(int deep, int len, int w) {
	if(len == L + 1) {
		if(sum > 25000) exit(0);
		sum++;
		if(L - w < 2) return ;
		if(w == 0) return ;
		for(int i = 1; i <= L; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	for(int i = deep + 1; i <= c; i++) {
//		if(i <= deep) continue;
		ans[len] = a[i];
		dfs(i, len + 1, w + judyuan[a[i] - 'a']);
		ans[len] -= a[i];
	}
}

int main() {
	freopen("ticket.in", "r", stdin);
	freopen("ticket.out", "w", stdout);
	scanf("%d%d\n", &L, &c);
	for(int i = 1; i <= c; i++) {
		scanf("%c", &a[i]);
		if(i != c) scanf(" ");
	}
	sort(a + 1, a + 1 + c);
	dfs(0, 1, 0);
	return 0;
}
