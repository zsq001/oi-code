#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
//typedef int int_;
//#define int long long

using namespace std;
//40
int f[2005][2005], n, m, x, sk, k, w, ans = 1e9 + 7, bns[1005];

struct node{
	int cost, val;
}s[2005], gua[2005];

int main() {
	freopen("sword.in", "r", stdin);
	freopen("sword.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &sk);
	for(int i = 1; i <= m; i++)
		scanf("%d", &s[i].val);
	s[0].val = x;
	for(int i = 1; i <= m; i++)
		scanf("%d", &s[i].cost);
	for(int i = 1; i <= k; i++)
		scanf("%d", &gua[i].val);
	for(int i = 1; i <= k; i++)
		scanf("%d", &gua[i].cost);
	for(int i = 0; i <= k; i++)
		bns[i] = 1e9 + 7;
	for(int i = 0; i <= k; i++)
	{
		if(gua[i].cost <= sk)
		{
			w = sk - gua[i].cost;
			for(int j = 1; j <= m; j++)
			{
				if(s[j].cost <= w)
				{
					f[i][j] = (n - gua[i].val) * s[j].val;
				}
				else f[i][j] = (n - gua[i].val) * x;
				bns[i] = min(bns[i], f[i][j]);
			}
			ans = min(ans, bns[i]);
		}
	}
	printf("%d", ans);
	return 0;
}
