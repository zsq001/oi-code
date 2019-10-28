#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long long tree[100010 << 2];
int n, m;

void pushup(int o)
{
	tree[o] = tree[o << 1] + tree[o << 1 | 1];
}

void build(int o, int l, int r)
{
	if(l == r) 
	{
		scanf("%d", &tree[o]);
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	pushup(o); 
}

void update(int o, int l, int r, int ql, int qr)
{
	if(ql <= l && qr >= r)//只能开最多7次方 
	{
		if(tree[o] == r - l + 1)
			return ;
	}
	if(l == r)
	{
		tree[o] = (long long)sqrt(tree[o]);
		return ;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) update(o << 1, l, mid, ql, qr);
	if(qr > mid) update(o << 1 | 1, mid + 1, r, ql, qr);
	pushup(o);
}

long long query(int o, int l, int r, int ql, int qr)
{
	if(ql <= l && qr >= r) return tree[o];
	int mid = (l + r) >> 1;
	long long ret = 0;
	if(ql <= mid) ret += query(o << 1, l, mid, ql, qr);
	if(qr >= mid + 1) ret += query(o << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}

int main() {
	freopen("sculpture.in", "r", stdin);
	freopen("sculpture.out", "w", stdout);
	scanf("%d", &n);
	build(1, 1, n);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int temp, a, b;
		scanf("%d%d%d", &temp, &a, &b);
		if(temp == 1)
			printf("%lld\n", query(1, 1, n, a, b));
		else 
			update(1, 1, n, a, b);
	}
	return 0;
}
