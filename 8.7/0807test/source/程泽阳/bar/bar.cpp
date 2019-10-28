#include<cstdio>
#include<string.h>
int map[1001][1001];
struct {
	int x,y,num;
}a[1000010];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int main()
{
	int k,t,l,xz;
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
	
		int n,nn,i,j,flag,min;
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		map[n][n]=101;
		flag=0;
		nn=2*n-2;
		int st=0,ed=0;
		a[ed].x=1;a[ed].y=1;
		a[ed].num=0;
		min=0;
		while(st<=ed)
		{
			int xx,yy;
			for(i=1;i<=4;i++)
			{  
				if(a[st].x+dx[i]>0 && a[st].x+dx[i]<=n && a[st].y+dy[i]>0 && a[st].y+dy[i]<=n )
				{
					if(map[a[st].x+dx[i]][a[st].y+dy[i]]==0)
				 {
					ed++;
					a[ed].x=a[st].x+dx[i];a[ed].y=a[st].y+dy[i];
					map[a[st].x+dx[i]][a[st].y+dy[i]]=1;
					a[ed].num=a[st].num+1;
				 }
					else if(map[a[st].x+dx[i]][a[st].y+dy[i]]==101 && flag!=1)
				 {
					flag=1;
					break;
				 }
				}
					
			}
			st++;
			if(flag==1){
				for(xz=1;xz<=nn-min;xz++)
				{
					scanf("%d%d",&xx,&yy);
				}
				printf("Yes\n");
				break;
			}
			if(a[st].num>min)
			{
				min++;
				scanf("%d%d",&xx,&yy);
				map[xx][yy]=1;
			}
		}
		if(flag==0){
		   printf("No\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
