#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}

int T, n, l, r, x1, x2;
int a[1010], ans[3];//1a 0b

int main() {
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	read(T);
	while(T--)
	{
		l = 0, r = 0;
		ans[0] = ans[1] = 0;
		read(n);
		int l = 1, r = n;
		for(int i = 1; i <= n; i++)
			read(a[i]);
		if(n == 1)
		{
			printf("%d\n", a[1] - 0);
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			int t = i % 2;
			x1 = a[l] - max(a[r], a[l + 1]);
			x2 = a[r] - max(a[l], a[r - 1]);
			if(x1 < x2)
			{
				ans[t] += a[r];
				r--;
			}
			else if(x2 < x1)
			{
				ans[t] += a[l];
				l++;
			}
		}
		printf("%d\n", ans[1] - ans[0]);
	}
}
