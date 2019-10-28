#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#define maxn 100011
#define LL long long
const int mod = 1e9+7;
//xds + jc
using namespace std;

int n, m, maxx;
LL tree[maxn << 3], lazy[maxn], f[6000009];

void pushup(int o)
{
	tree[o] = tree[o << 1] + tree[o << 1 | 1];
}

void pushdown(int o, int l, int r)
{
	if(!lazy[o]) return;
	int mid = (l + r) >> 1;
	tree[o << 1] += lazy[o] * (mid - l + 1);
	tree[o << 1 | 1] += lazy[o] * (r - mid);
	lazy[o << 1] += lazy[o];
	lazy[o << 1 | 1] += lazy[o];
	lazy[o] = 0;
}

void build(int o, int l, int r)
{
	if(l == r)
	{
		scanf("%lld", &tree[o]);
		if(tree[o] > maxx) maxx = tree[o];
		return ;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	pushup(o);
}

void update(int o, int l, int r, int ql, int qr, int val)
{
	if(ql <= l && qr >= r)
	{
		tree[o] += val * (r - l + 1);
		lazy[o] += val;
		return ;
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	if(ql <= mid) update(o << 1, l, mid, ql, qr, val);
	if(qr > mid) update(o << 1 | 1, mid + 1, r, ql, qr, val);
	pushup(o);
}

LL query(int o, int l, int r, int ql, int qr)
{
	if(ql <= l && r <= qr && l == r) return f[tree[o]] % mod;
	pushdown(o, l, r);
	LL ret = 0;
	int mid = (l + r) >> 1;
	if(ql <= mid) ret += query(o << 1, l, mid, ql, qr) % mod;
	if(qr > mid) ret += query(o << 1 | 1, mid + 1, r, ql, qr) % mod;
	return ret;
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	int tmp, x, y, z;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	f[1] = 1, f[2] = 1;
	for(int i = 3; i <= 4000000; i++)
		f[i] = f[i - 2] + f[i - 1];
	while(m--)
	{
		scanf("%d", &tmp);
		if(tmp == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			update(1, 1, n, x, y, z);
		}
		else 
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", query(1, 1, n, x, y) % mod);
		}
	}
	return 0;
}
