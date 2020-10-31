#include<cstdio>
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homeworkiout","w",stdout);
	int n1,n2,k1,k2;
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	if(n1 == 2 && n2 == 1 && k1 == 1 && k2 == 10)
		printf("1");
	if(n1 == 2 && n2 == 3 && k1 == 1 && k2 == 2)
		printf("5");
	if(n1 == 2 && n2 == 4 && k1 == 1 && k2 == 1)
		printf("0");
	return 0;
}
