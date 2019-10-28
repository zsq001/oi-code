#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, m, S=1000000000LL, i, j, k;
int main() 
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%I64d", &n);
	for( i=1; i*i*i<= n; i++)
    {
		if( n % i != 0) continue;
		m = n / i;
		for( j=i; j*j<= m; j++)
        {
			if(m%j != 0) continue;
            k = m / j;
			S = min ( S, 2 * (i*j + j*k + k*i));
		}
	}
	printf("%I64d", S);
	getchar();
	getchar();
	return 0;
}
