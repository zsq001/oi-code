#include<cstdio>
int n,m;
char mapp[1010][1010];
int read()
{
	int date=0,w=1;char c=0;
	while(c<'0' || c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0' && c<='9'){date=(date<<1)+(date<<2)+c-'0';c=getchar();}
	return date*w;
}
int main()
{
	int x1,x2,y1,y2;
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		x1=read();y1=read();x2=read();y2=read();
//		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i=x1;i<=x2;i++)
		{
			int l=y1;
			int r=y2;
		/*	while(l<=r)
			{
				mapp[i][l]++;
				mapp[i][r]++;
				l++;
				r--;
			} */
			
			 for(int j=y1;j<=y2;j++)
			{
				mapp[i][j]++;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",mapp[i][j]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
