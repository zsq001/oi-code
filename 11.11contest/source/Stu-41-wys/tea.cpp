#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int m, jd, now[1007], lost[1007];

int main() {
	freopen("tea.in", "r", stdin);
	freopen("tea.out", "w", stdout);
	scanf("%d%d", &m, &jd);
	if(m > 1000) return 0;
	for(int i = 1; i <= m; i++) {
		int op, x;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &x);
			now[x] = 1;
		}
		if(op == 2) {
			scanf("%d", &x);
			lost[x] = m;
			now[x] = 0;
		}
		if(op == 3) {
			int min = 1e9 + 7, num;
			for(int i = 1; i <= m; i++) {
				if(lost[i] > 0 && lost[i] < min) 
					min = lost[i], num = i;
			}
			now[num] = 1;
		}
		if(op == 4) {
			for(int i = 1; i <= m; i++) {
				if(now[i] == 0) {
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
