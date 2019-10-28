#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 400050;
using namespace std;
char s[MAXN];
int p[MAXN], cnt = 1, len, num, n, ans[MAXN];
int main() {
	freopen("key.in", "r", stdin);
	freopen("key.out", "w", stdout);
	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i < len - 1; i++) {
		if(s[i] != s[i + 1]) {
			p[i] = 1;
			cnt++;
		}
	}
	n = len / 3;
	if(cnt >= (n << 1)) {
		cout << "0" << endl;
		return 0;
	}
	for(int i = 1; i < len - 1; i++) {
		if(p[i] == 1) {
			if(p[i - 1] == 0 && p[i + 1] == 0) {
				ans[++num] = i + 1;
			//	a[i] ^= 1;
			//	a[i + 1] ^= 1;
				cnt += 2;
				p[i - 1] = p[i + 1] = 1;
			}
		}
		else if(p[i] == 0) {
			if(p[i - 1] == 0 && p[i + 1] == 0) {
				p[i] = p[i + 1] = 1;
			//	a[i] ^= 1;
			//	a[i + 1] ^= 1;
				cnt += 2;
				ans[++num] = i + 1;
			}
		}
		if(cnt >= (n << 1)) {
			printf("%d\n", num);
			for(int i = 1; i <= num; i++) {
				printf("%d ", ans[i]);
			}
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
