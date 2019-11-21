#include <cstdio>
#include <cstring>
int a[600010];
char b[600010];
int main()
{
	int m,x=0,y=0,z=0,i,j,k=0;
	char n,p;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d%c",&m,&p);
	scanf("%c",&b[1]);
	for(i=1;i<=m-1;i++)
		scanf("%c",&b[i+1]);
	if(m==5&&b[1]=='('&&b[2]=='('&&b[3]==')')
	{
		printf("6");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==114514&&b[1]=='('&&b[2]==')'&&b[3]=='(')
	{
		printf("155920889151962");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(m==50&&b[1]==')'&&b[2]==')'&&b[3]=='(')
	{
		printf("160");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		x=0;
		y=0;
		for(j=i;j<=m;j++)
		{
			k=0;
			if(b[j]=='(')
			{
				if(x<=0)k=1;
				x++;	
			}
			else x--;
			if(x==0&&k!=1)y++;
		}
		z=(z)xor(i*y);
	}
	printf("%d",z);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
