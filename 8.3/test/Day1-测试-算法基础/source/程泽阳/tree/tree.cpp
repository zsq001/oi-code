#include<cstdio>
int a[10010];
int aa[10010],n;
long long num;
int main()
{
	a[1]=1;
	int i,j;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("1");
		return 0;
	}
	aa[1]=1;
	aa[2]=2;
	aa[3]=4;
	for(i=2;i<=n;i++)
	{
		aa[i]=2*(i-1);
	}
	if(n<=10)
	{
		int k=2;
		for(i=2;i;i++)
		{
			for(j=1;j<=aa[i];j++)
			{
				a[k]=i;
				k++;
				if(k>n){
					printf("%d",a[n]);
//					print();
					return 0;
				}
			}
		}
	} 
	else
	{
		while(n!=0)
		{
			n=n/2;
			num++;
		}
		printf("%d",num);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
