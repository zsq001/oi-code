#include <stdio.h>
int dui[5][4]={{0},{0,0,0,0},{0,0,1,1},{1,1,0,0},{1,1,1,1}};
int a[100005],ans[50005];
int main()
{
	int n3=0,n2,cnt=1,tot=0;
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	while(scanf("%1d",&a[++n3])!=EOF);
	n3--;
	n2=(n3/3)*2;
	for(int i=1;i<n3;i++)
	{
		if(a[i]!=a[i+1])
		{
			cnt++;
		}
	}
	if(cnt>=n2)
		{printf("0");return 0;}
	cnt=n2-cnt;n3-=3;
	int j;
	for(int i=1;i<=n3&&cnt;i++)
	{
		for(int k=1;k<=4;k++)
		{
			for(j=0;j<4;j++)
			{
				int t=i+j;
				if(a[t]!=dui[k][j])break;
			}
			if(j>3){cnt-=2;ans[++tot]=++i;break;}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
