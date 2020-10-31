#include<cstdio>
int num,mun;
int main()
{
	int n,m;
	int x,y,z;
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			x=0;
			y=0;
			scanf("%d%d",&num,&mun);
			for(int j=1;j<=4;j++)
			{
				x+=num%10;
				num/=10;
				y+=mun%10;
				mun/=10;
			}
			if(x>y)printf("%d\n",x-y);
			else printf("%d\n",y-x);
		}
	}
	else{
		printf("²»»á´æÂ·¾¶"); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
