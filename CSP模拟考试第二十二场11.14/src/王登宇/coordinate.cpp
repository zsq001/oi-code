#include<stdio.h>
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n,i;
	int shang1,shang2,bian1,bian2;
	scanf("%d",&n);
	if(n==0)
	{
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	shang1=1;
	bian1=1;
	for(i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			shang2=(shang1+2*bian1)%1000000007;
			bian2=(shang1+bian1)%1000000007;
		}
		else 
		{
			shang1=(shang2+2*bian2)%1000000007;
			bian1=(shang2+bian2)%1000000007;
		}
	}
	if(n%2==0)
	printf("%d",(shang2+2*bian2)%1000000007);
	else 
	printf("%d",(shang1+2*bian1)%1000000007);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

