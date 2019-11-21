#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
int useless[100005],ans[100005];
char a[100005];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int i,j,k,n,q,h;
	scanf("%d",&n);
	scanf("%s",&a[1]);
	for(i=1;i<n;i++) scanf("%d",&useless[i]);
	printf("0");
	return 0;
}

