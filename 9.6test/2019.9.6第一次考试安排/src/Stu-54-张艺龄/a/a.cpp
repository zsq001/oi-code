#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 1050;
using namespace std;
int t, n, x, cnt, num, num1, sum, a[MAXN], b[MAXN];
bool vis[MAXN];
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
void init() {
	cnt = num = num1 = sum = 0;
	memset(a, 0, sizeof(a));
	memset(vis, false, sizeof(vis));
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	t = read();
	while(t--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			x = read();
			if(x % 3 == 0) {
				cnt++;
				continue;
			}
			a[++num] = x;
		}
		sort(a + 1, a + num + 1);
		for(int j = num; j > 1; j--) {
			for(int i = 1; i < j; i++) {
				if(!vis[i] && (a[i] + a[j]) % 3 == 0) {
					vis[i] = vis[j] = true;
					cnt++;
					break;
				}
			}
		}
		for(int i = 1; i <= num; i++) {
			if(!vis[i])
				b[++num1] = a[i];
		}
		sum = b[1];
		for(int i = 2; i <= num1; i++) {
			sum += b[i];
			if(sum % 3 == 0) {
				cnt++;
				sum = 0;
			}
		}
		cout << cnt << endl;
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
