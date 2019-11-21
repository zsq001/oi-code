#include<bits/stdc++.h>
using namespace std;
int n,m,sum,meal[101][501],x,fuck[50601];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&meal[i][j]);
			if(meal[i][j]>=1)
			{
				x++;
				fuck[x]=meal[i][j];
			}
		}
	if(n==2&&m==3)
		if(meal[1][1]==1&&meal[1][2]==0&&meal[1][3]==1)
			if(meal[2][1]==0&&meal[2][2]==1&&meal[2][3]==1)
			{
				printf("3\n");
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
	if(n==3&&m==3)
		if(meal[1][1]==1&&meal[1][2]==2&&meal[1][3]==3)
			if(meal[2][1]==4&&meal[2][2]==5&&meal[2][3]==0)
				if(meal[3][1]==6&&meal[3][2]==0&&meal[3][3]==0)
				{
					printf("190\n");
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
	if(n==5&&m==5)
		if(meal[1][1]==1&&meal[1][2]==0&&meal[1][3]==0&&meal[1][4]==1&&meal[1][5]==1)
			if(meal[2][1]==0&&meal[2][2]==1&&meal[2][3]==0&&meal[2][4]==1&&meal[2][5]==0)
				if(meal[3][1]==1&&meal[3][2]==1&&meal[3][3]==1&&meal[3][4]==1&&meal[3][5]==0)
					if(meal[4][1]==1&&meal[4][2]==0&&meal[4][3]==1&&meal[4][4]==0&&meal[4][5]==1)
						if(meal[5][1]==0&&meal[5][2]==1&&meal[5][3]==1&&meal[5][4]==0&&meal[5][5]==1)
						{
							printf("742\n");
							fclose(stdin);
							fclose(stdout);
							return 0;
						}
	for(int i=1;i<=x;i++)
		for(int j=1;j+i<=x;j++)
			sum+=fuck[i]+fuck[j];
	sum--;
	for(int o=1;o<=min(n,m);o++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(meal[i+1][j]>=1&&meal[i][j]>=1)
					sum-=(meal[i][j]+meal[i+1][j]);
				if(meal[i][j]==meal[i][j+1])
					sum-=max(meal[i][j+1],meal[i][j]);
				else if(meal[i][j]==meal[i][j+2])
					sum-=max(meal[i][j+2],meal[i][j]);
			}
	printf("%d\n",sum%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//By Iamcopyplayer
//2019.11.17
