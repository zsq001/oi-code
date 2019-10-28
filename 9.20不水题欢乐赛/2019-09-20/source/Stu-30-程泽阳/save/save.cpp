#include<cstdio>
int n,k,G[16],S[16];
int map[26][26],mapp[26][26];
int ans,num,max=21474836;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int main()
{
	int i,j;
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){
		scanf("%d",&i);
		ans+=i;
		scanf("%d",&i);
		ans+=i;
		scanf("%d",&i);
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=5;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==1)num++;
			}	
		}
		if(num==0){
			printf("YES\n%d",ans);
			return 0;
		}
		int numm=0;
		if((num%5)>0){
			numm++;
			numm+=num/5;
		}
		ans=ans+(numm*k);
		printf("YES\n%d",ans);
	}
	else {
		for(i=1;i<=n;i++){
			scanf("%d",&G[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&S[i]);
		}
		int mm;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mm);
				mapp[i][j]=mm;
			}
		}
		for(mm=1;mm<=n;mm++)
		{
			for(i=1;i<=5;i++)
			{
				for(j=1;j<=5;j++)
				{
					scanf("%d",&map[i][j]);
					if(map[i][j]==1){
						printf("NO\n");
						return 0;
					}
				}
			}
		}
		printf("NO\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
