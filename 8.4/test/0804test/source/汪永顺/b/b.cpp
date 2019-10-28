#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}

int n, m, p, q, a[1000020], cnt;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	read(n);
	read(m);
	read(p);
	read(q);
	for(int i = m; i >= 1; i--)
	{
		int l = (i * p + q) % n + 1;
		int r = (i * q + p) % n + 1;
		if(l > r) swap(l, r);
		for(int j = l; j <= r; j++)
		{
			if(a[j] == 0)
			{
				a[j] = i;
				cnt++;
			}
		}
		if(cnt == n) break;
	}
	for(int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
	return 0;
}
