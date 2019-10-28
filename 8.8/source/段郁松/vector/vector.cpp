#include<stdio.h>
#include<math.h>
int t,a,b,x,y,f;
int z1[10],z2[10];
int flag=0;
int gcd(int c,int d)
{
	if(c==0) return d;
	return gcd(d%c,c);
}
int main()
{
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	int i,j;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		flag=0;
		f=gcd(a,b);
		if(x%f!=0&&y&f!=0) 
		{
			printf("N\n");
			flag=0;
			continue;
		}
		z1[1]=0;
		z2[1]=0;
		z1[2]=a;
		z2[2]=b;
		z1[3]=b;
		z2[3]=a;
		z1[4]=a+b;
		z2[4]=a+b;
		for(j=1;j<=4;++j)
		{
			if(a!=0&&b!=0&&((abs(z1[j])+abs(x))%abs(2*a)==0||(abs(z1[j])+abs(x))%2==0)&&((abs(z2[j])+abs(y))%abs(2*b)==0||(abs(z2[j])+abs(y))%2==0))
			{
				printf("Y\n");
				flag=1;
				break;
			}
			if(a==0&&b!=0&&(abs(z1[j])+abs(x))%2==0&&((abs(z2[j])+abs(y))%abs(2*b)==0||(abs(z2[j])+abs(y))%2==0))
			{
				printf("Y\n");
				flag=1;
				break;
			}
			if(a!=0&&b==0&&((abs(z1[j])+abs(x))%abs(2*a)==0||(abs(z1[j])+abs(x))%2==0)&&(abs(z2[j])+abs(y))%2==0)
			{
				printf("Y\n");
				flag=1;
				break;
			}
			if(a==0&&b==0&&(abs(z1[j])+abs(x))%2==0&&(abs(z2[j])+abs(y))%2==0)
			{
				printf("Y\n");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("N\n");
			flag=0;
		}
	}
	return 0;
}

