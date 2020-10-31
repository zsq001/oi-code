#include <cstdio>
int n,m,q,x[1000001],y[1000001],z[1000001],mp[1001][1001];
bool h[1001],l[1001];
int in()
{
	char ch=getchar();
	int tmp=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		tmp*=10;
		tmp+=ch-'0';
		ch=getchar();
	}
	return tmp;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=in();m=in();q=in();
	for(int i=1;i<=q;i++)
	{
		x[i]=in();
		y[i]=in();
		z[i]=in();
	}
	for(int i=q;i>=1;i--)
	{
		if(x[i]==1)
		{
			if(h[y[i]])continue;
			h[y[i]]=true;
			for(int j=1;j<=m;j++)
				if(mp[y[i]][j]==0)mp[y[i]][j]=z[i];
		}
		if(x[i]==2)
		{
			if(l[y[i]])continue;
			l[y[i]]=true;
			for(int j=1;j<=n;j++)
				if(mp[j][y[i]]==0)mp[j][y[i]]=z[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",mp[i][j]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
