#include<cstdio>
#include<algorithm>
using namespace std;
int a[12]={0,1,1,1,1,1,2,3,2,2,2};
int main() 
{
	int n,m,c,b;
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		b=m/11;
		c=m%11;
		printf("%d\n",b*2+a[c]);
	}
}
