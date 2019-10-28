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

int T, ans;

int main() {
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	read(T);
	while(T--)
	{
		ans = 0;
		int n;
		scanf("%d", &n);
		if(n == 7) ans = 3, n = 0;
		ans +=  2 * (n / 11);
		n = n - (n / 11) * 11;
		if(n != 0)
		{
			if(n >= 1 && n <= 5) ans += 1;
			else if(n >= 6 && n <= 10) ans += 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
