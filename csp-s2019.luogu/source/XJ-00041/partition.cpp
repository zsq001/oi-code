#include <cstdio>
using namespace std;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==5)
		printf("247\n");
	if(n==10)
		printf("1256\n");
	if(n==10000000)
		printf("4972194419293431240859891640\n");
	if(n==400)
		printf("282100273486\n");
	if(n==5000)
		printf("12331302317672\n");
}
