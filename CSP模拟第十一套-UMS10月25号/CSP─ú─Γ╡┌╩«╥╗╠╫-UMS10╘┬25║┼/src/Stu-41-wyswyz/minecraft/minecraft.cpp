#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int B, n, d, m, cnt;

struct node {
	int a, b, c;
}loc[100007];

int cmp(const node s1, const node s2) {
	return s1.a < s2.a;
}

int cmp2(const node s1, const node s2) {
	if(s1.a != s2.a) return s1.a < s2.a;
	else return s1.b < s2.b;
}

int cmp3(const node s1, const node s2) {
	if(s1.a != s2.a) return s1.a < s2.a;
	else if(s1.b != s2.b) return s1.b < s2.b;
	else return s1.c < s2.c;
}

int main() {
	freopen("minecraft.in", "r", stdin);
	freopen("minecraft.out", "w", stdout);
	scanf("%d%d%d%d", &B, &n, &d, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= B; j++) {
			if(j == 1) scanf("%d", &loc[i].a);
			else if(j == 2) scanf("%d", &loc[i].b);
			else if(j == 3) scanf("%d", &loc[i].c);
		}
	}
	if(B == 1) {	
		sort(loc + 1, loc + 1 + n, cmp);
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(loc[i].a - loc[j].a) <= d) {
					cnt++;
				}
			}
		}
		printf("%d", cnt);
	}
	if(B == 2) {
		sort(loc + 1, loc + 1 + n, cmp2);
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(loc[i].a - loc[j].a) + abs(loc[i].b - loc[j].b) <= d) {
					cnt++;
				}
			}
		}
		printf("%d", cnt);
	}
	if(B == 3) {
		sort(loc + 1, loc + 1 + n, cmp3);
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(loc[i].a - loc[j].a) + abs(loc[i].b - loc[j].b) + abs(loc[i].c - loc[i].c) <= d) {
					cnt++;
				}
			}
		}
		printf("%d", cnt);
	}
	return 0;
}
