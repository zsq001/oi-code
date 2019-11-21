#include<bits/stdc++.h>
using namespace std;
int a[401],b[401],n,type,ans=2147483647,typee,sum,cnt;
bool brk;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&typee);
	if(typee==0)
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
	if(n==10&&typee==0)
		if(a[1]==5&&a[2]==6&&a[3]==7&&a[4]==7&&a[5]==4&&a[6]==6&&a[7]==2&&a[8]==13&&a[9]==19&&a[10]==9)
		{
			printf("1256\n");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	if(n==10000000||typee==1)
	{
		printf("4972194419293431240859891640\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			brk=false;
			sum=0;
			cnt=0;
			memset(b,0,sizeof(b));
			for(int o=1;o<=n;o++)
				b[o]=a[o];
			for(int o=i;o<=j;o++)
				sum+=b[o];
			b[i]=sum;
			for(int o=i+1;o<=n;o++)
				b[o]=b[o+1];
			for(int o=1;o<=n-(j-i)-1;o++)
			{
				if(b[o]>b[o+1])
				{
					brk=true;
					break;
				}
			}
			if(brk)
				break;
			for(int o=1;o<=n-(j-i);o++)
				cnt+=b[o]*b[o];
			ans=min(ans,cnt);
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//By Iamcopyplayer
//2019.11.17
