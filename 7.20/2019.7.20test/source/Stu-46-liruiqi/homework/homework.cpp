#include<cstdio>
using namespace std;
#include<bits/stdc++.h>
int n1,n2,k1,k2;
int main()
{
	freopen("homework.in" ,"r",stdin);
	freopen("homework.out ","w",stdout);
	scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
	if(k1==0)
	printf("%d",0);
	if(k2>=n2)
	printf("%d",1);
	else
	printf("%d",0);
	return 0;
}
