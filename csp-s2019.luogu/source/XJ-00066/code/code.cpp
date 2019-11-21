#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long n, k, len, flag, temp;

long long poww(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) ret *= a;
		b >>= 1;
		a *= a;
	}
	return ret;
}

int main() {
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	temp = n;
	long long kkk = poww(2, temp - 1);
	while(len < n) {
		len++;
		if(len != 1) {
			kkk /= 2;
		}
		if(k <= kkk - 1) {
			if(flag == 0) {
				printf("0");
				flag = 0;
			}
			else if(flag == 1) {
				flag = 0;
				printf("1");
			}
		}
		else {
			if(flag == 0) {
				printf("1");
				flag = 1;
				k -= kkk;
			}
			else if(flag == 1) {
				printf("0");
				flag = 1;
				k -= kkk;
			}
		}
		temp--;
	}
	return 0;
}
