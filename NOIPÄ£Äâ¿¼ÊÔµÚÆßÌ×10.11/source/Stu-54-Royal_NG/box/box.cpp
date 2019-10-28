#include<stdio.h>
#include<math.h>
int v,l1,n1,n2,n3;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&v);
	for(int i=1;i<=v;i++)
	{
		if(i*i*i<=v&&(i+1)*(i+1)*(i+1)>=v)
		{
			l1=i;break;
		}
	}
	for(int i=0; ;i++)
	{
		if(v%(l1-i)==0)
		{
			n1=l1-i;
			break;
		}
	}
	v/=n1;
	for(int i=sqrt(v); ;i++)
		if(v%i==0)
		{
			n2=i;
			n3=v/i;
			break;
		}
	printf("%d",2*(n1*n2+n1*n3+n2*n3));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
