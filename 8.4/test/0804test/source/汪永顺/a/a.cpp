#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#define maxn 200020

using namespace std;

template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}

int n, m, dp[maxn], flag;

struct node{
	int val, next, last;
	bool vis;
}a[maxn];

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	read(n);
	read(m);
	read(a[1].val), a[1].next = 2, a[1].last = n;
	for(int i = 2; i < n; i++)
	{
		read(a[i].val);
		a[i].last = i - 1;
		a[i].next = i + 1;
	}
	read(a[n].val), a[n].last = n - 1, a[n].next = 1;
	if(m > (n / 2))
	{
		printf("Error!");
		return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		flag = 0;
		for(int j = 1; j <= n; j++)
		{
			if(a[a[j].next].vis == false && a[a[j].last].vis == false && a[j].vis == false)
			{
				if(dp[i - 1] + a[j].val > dp[i])
				{
					dp[i] = dp[i - 1] + a[j].val;
					flag = j;
				}
			}
		}
		a[flag].vis = true;
	}
	printf("%d", dp[m]);
	return 0;
}
