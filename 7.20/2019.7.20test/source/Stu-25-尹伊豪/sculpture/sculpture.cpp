#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
struct{
	int k;
}gold[100010];
int main()
{
	freopen("sculpture.in","r",stdin);
    freopen("sculpture.out","w",stdout);
	int n,m,he=0,ans[100010],sum[100010],z[100010],op,l,r;
	scanf("%d ",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ans[i]);
		gold[i].k=ans[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&op,&l,&r);
	    for(int j=l;j<=r;j++)
		{
	    	if(op=0)
			{
	    	   sum[j]=sqrt(gold[i].k);
			   printf("");
			}
	    	else
			{
	    		he+=sum[j];
	    		printf("%d\n",he);
			}
		} 
	}
	return 0;
}
