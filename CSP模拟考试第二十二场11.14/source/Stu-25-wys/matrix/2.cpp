#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1e9 + 7;

using namespace std;

int n;

struct MAT {
	int x, y;
	int A[105][105];
	MAT(int xx, int yy) {
		x = xx, y = yy;
		for(int i = 1; i <= x; i++) {
			for(int j = 1; j <= y; j++) {
				A[i][j] = 0;
			}
		}
	}
	void init(int flag) {
		for(int i = 1; i <= x; i++) {
			for(int j = 1; j <= y; j++) {
				A[i][j] = 0;
			}
		}
		if(flag) {
			for(int i = 1; i <= x; i++) {
				A[i][i] = 1;
			}
		}
		return ;
	}
	MAT operator* (MAT b) {
		MAT a = *this;
		MAT c(a.x, b.y);
		c.init(0);
		for(int i = 1; i <= a.x; i++) {
			for(int j = 1; j <= b.y; j++) {
				for(int k = 1; k <= a.y; k++) {
					c.A[i][j] = (c.A[i][j] + a.A[i][k] * b.A[k][j]) % mod;
				}
			}
		}
		return c;
	}
	MAT operator^ (int b) {
		MAT a = *this;
		MAT ret(a.x, a.y);
		ret.init(1);
		while(b) {
			if(b & 1) {
				ret =ret * a;
			}
			b >>= 1;
			a = a * a;
		}
		return ret;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	MAT ans(1, 3), cheng(3, 3);
	cheng.A[1][2] = cheng.A[2][3] = cheng.A[3][2] = 1;
	cheng.A[3][3] = 2;
	ans.A[1][1] = 3; ans.A[1][2] = 7; ans.A[1][3] = 17;
	if(n <= 3) {
		printf("%d", ans.A[1][n]);
		return 0;
	}
	cheng = cheng ^ (n - 3);
	ans = ans * cheng;
	printf("%d", ans.A[1][3]);
	return 0;
}
