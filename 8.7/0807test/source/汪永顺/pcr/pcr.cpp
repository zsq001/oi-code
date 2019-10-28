#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
typedef int int_;
#define int long long
const int mod = 19260817;

using namespace std;

int n;

struct MAT{
	int A[110][110];
	int x, y;
	MAT(int x_, int y_)
	{
		x = x_;
		y = y_;
		for(int i = 1; i <= x; i++)
			for(int j = 1; j <= y; j++)
				A[i][j] = 0;
	}
	
	void init(bool flg)
	{
		for(int i = 1; i <= x; i++)
			for(int j = 1; j <= x; j++)
				A[i][j] = 0;
		if(flg)
		{
			for(int i = 1; i <= x; i++)	A[i][i] = 1;
		}
	}
	
	MAT operator*(MAT b)
	{
		MAT a = *this;
		MAT c(a.x, b.y);
		c.init(0);
		for(int i = 1; i <= a.x; i++)
			for(int j = 1; j <= b.y; j++)
				for(int l = 1; l <= a.y; l++)
				{
					c.A[i][j] += (a.A[i][l] % mod * b.A[l][j] % mod) % mod;
					c.A[i][j] %= mod;
				}
		return c;
	}
	
	MAT operator^(int b)
	{
		MAT ret(x, x), a = *this;
		ret.init(1);
		while(b)
		{
			if(b & 1) ret = ret * a;
			b >>= 1;
			a = a * a;
		}
		return ret;
	}
};

int_ main() {
	freopen("pcr.in", "r", stdin);
	freopen("pcr.out", "w", stdout);
	scanf("%lld", &n);
	if(n <= 3)
	{
		if(n == 1 || n ==2)
		{
			printf("0");
			return 0;
		}
		else if(n == 3)
		{
			printf("2");
			return 0;
		}
	}
	MAT ans(3, 3), chen(3, 1);
	ans.A[1][1] = ans.A[1][2] = 2;
	ans.A[2][2] = ans.A[2][3] = ans.A[3][3] = 1;
	chen.A[1][1] = 0, chen.A[2][1] = chen.A[3][1] = 1;
	ans = ans ^ (n - 2);
	chen = ans * chen;
	printf("%lld", chen.A[1][1]);
	return 0;
}
