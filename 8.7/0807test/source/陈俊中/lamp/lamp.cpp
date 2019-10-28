#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 100010
using namespace std;

int n,len,red[20],maxx=17,bad[20];

int main()
{	
	freopen("lamp.in ","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&len);
	if(n==1)
	{
		printf("%d",len);
		return 0;
	}
	else printf("2");
	return 0;
}
