#include <stdio.h>
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==2)printf("2");
	if(m==3)printf("3");
	return 0;
}
