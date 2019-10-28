#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long

const int mod = 100000007;

using namespace std;

int pri[200000], cnt;
LL temp = 1, ans = 1;
bool vis[100000000], flag;

inline void shai(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i])
		{
			pri[++cnt] = i;
			for(int j = i; j <= n; j += i)
			{
				vis[j] = 1;
				if(flag == 0)
				{
					temp = ((temp % mod) * i % mod) % mod;
					if(temp > n)
					{
						flag = 1;
						temp /= i;
					}
					else if(j + i >= n)
						flag = 1;
				}
			}
			if(flag == 1)
			{
				ans = (ans * (temp % mod)) % mod;
				flag = 0;
				temp = 1;
			}
		}
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n;
	scanf("%d", &n);
	shai(n);
	printf("%lld", ans);
}
