#include<cstdio>
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	n=(m/2)+1;
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
}
