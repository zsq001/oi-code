#include<stdio.h>
#include<math.h>
int main()
{
	int v,i,j,a,m,b;
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&v);
	for(i=1;;i++)
	if(i*i*i>v)break;
	a=i-1;
	for(i=a;i>=1;i--)
	{
		if(v%i!=0)continue;
		m=v/i;
		b=sqrt(m);
		for(j=b;j>=1;j--)
		{
			if(m%j!=0)continue;
			printf("%lld",2*(i*j+i*m/j+m));
			break;
		}
		if(j>=1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
