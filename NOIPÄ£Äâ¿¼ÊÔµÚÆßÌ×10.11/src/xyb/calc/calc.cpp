#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char str[5010];
long long ans;
int cnt_l[2010], cnt_r[2010];

int main() {
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		cnt_l[i]++;
		cnt_r[i]++;
		for (int j = 1; i + j < len && i - j >= 0; ++j) {
			if (str[i - j] == str[i + j]) {
				cnt_r[i + j]++;
				cnt_l[i - j]++;
			}
			else break;
		}
	}
	for (int i = 1; i < len; ++i) {
		for (int j = 1; i + j - 1 < len && i - j >= 0; ++j) {
			if (str[i - j] == str[i + j - 1]) {
				cnt_r[i + j - 1]++;
				cnt_l[i - j]++;
			}
			else break;
		}
	}
	for (int i = len - 2; i >= 0; --i) cnt_l[i] += cnt_l[i + 1];
	for (int i = 1; i < len; ++i) ans += (long long)cnt_r[i - 1] * cnt_l[i];
	printf("%I64d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
