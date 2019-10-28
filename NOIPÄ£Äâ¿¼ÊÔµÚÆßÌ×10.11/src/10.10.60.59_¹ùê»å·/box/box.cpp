#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long v;
long long s = 2147483647 ;

typedef long long LL ; 

LL gmin ( const LL x , const LL y ) { return x > y ? y : x ; }

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%I64d",&v);
	for(int i = 1;i *i *i <= v;++i)
	{
		if(v%i == 0)
		{
			int tmp = sqrt ( v / i ) ; 
			
			for(int k = i;k<=tmp ;++k)
			{
				if((v/i)%k == 0)
				{
					int g = v/i/k;
					s = gmin((v/i) + (v/k) + (v/g),s);
				}
			}
		}
	}
	printf("%I64d",2*s);
	return 0;
}
//  i j v/(i*j) i*j+v¡¢ 
