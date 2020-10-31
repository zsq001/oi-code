#include<cstdio>
int n,m,q,a[1010][1010],b[1000010][3],k;
int qinput()
{
	char ans;
	int x=0;
	while(1)
	{
		ans=getchar();
		if(ans!='\n'&&ans!=' ')x=((x<<3)+(x<<1)+ans-'0');
		else return x;
	}
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=qinput();m=qinput();q=qinput();
	for(int i=1;i<=q;++i)
	{
		b[i][0]=qinput();b[i][1]=qinput();b[i][2]=qinput();
	}
	k=n*m;
	for(int i=q;i;--i)
	{
		int x=b[i][0],y=b[i][1],z=b[i][2];
		if(x==1)
		{
			for(int j=1;j<=m;++j)
				if(!a[y][j])
				{
					a[y][j]=z;
					--k;
				}
		}	
		else
		{
			for(int j=1;j<=n;++j)
				if(!a[j][y])
				{
					a[j][y]=z;
					--k;
				}
		}
		if(!k)break;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
