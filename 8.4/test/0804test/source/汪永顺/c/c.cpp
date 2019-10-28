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

int n, q, a[1000006], k[30], dp[30][1000010];

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	read(n);
	for(int i = 1; i <= n; i++)
		read(a[i]);
	read(q);
	for(int i = 1; i <= q; i++)
		read(k[i]);
	for(int i = 1; i <= q; i++)
	{
		for(int j = 1; j < n; )
		{
			for(int l = k[i]; l >= 1; l--)
			{
				if(a[j + l] < a[j] && j + l <= n)
				{
					j += l;
					dp[i][j] = dp[i][j - l];
					break;
				}
				else if(l == 1 && a[j + 1] >= a[j])
				{
					if(n - j > k[i]) 
					{
						j += k[i];
						dp[i][j] = dp[i][j - k[i]] + 1;
						break;
					}
					else
					{
						dp[i][n] = dp[i][j] + 1;
						j = n;
						break;
					}
				}
			}
		}
		printf("%d\n", dp[i][n]);
	}
	return 0;
}
