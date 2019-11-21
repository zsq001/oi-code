#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int ccf,ans=0,n,m,map[110][2010],way[2010],food[2010];//!
bool flag=1;
void sb(int x,int y,int cnt,int st)
{
//	cout<<"cao"<<endl;
	food[x]++;way[y]++;
	if(st==0)
	{
		int a=0,b=0;
		for(int i=1;i<=n;i++)if(a<food[i])a=food[i];
		for(int i=1;i<=m;i++)if(b<way[i])b=way[i];
		if(a/2<=ccf/2&&b/2<=ccf)ans+=cnt;
		return ;
	}
	for(int i=x+1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]==0)continue;
			sb(i,j,cnt*map[x][y],st-1);
		}
	food[x]--;way[y]--;
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
			way[j]+=map[i][j];	
			if(map[i][j]!=1&&map[i][j]!=0)flag=0;
		}
	}
	if(n<=10)
	{
		if(m==2||m==3)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=j+1;k<=m;k++)
				{
					ans+=way[j]*way[k];
			//		cout<<"卢本伟nb"<<endl;
				}
			}//cout<<ans<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=j+1;k<=m;k++)
					{
						ans-=map[i][j]*map[i][k];
					}
				}
			}
		}
		cout<<ans;
	fclose(stdin);fclose(stdout);return 0;
	}
	if(flag)
	{
		
	}
	for(int s=2;s<=n;s++)
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			memset(way,0,sizeof(way));
			memset(food,0,sizeof(food));
			ccf=s;
			sb(i,j,1,s);//ij位置 1权值 s步 
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);return 0;
}
