#include <stdio.h>
int map[1010][1010];
int h[1010][2],l[1010][2];
int main()
{
  freopen ("matrix.in","r",stdin);
	freopen ("matrix.out","w",stdout);
	int n,m,q;
	int x,y,z;
	scanf ("%d %d %d",&n,&m,&q);
	for (int i=1;i<=q;i++)
	{
		scanf ("%d %d %d",&x,&y,&z);
		if (x==1)
		{
			h[y][0]=i;
			h[y][1]=z; 
			
		}
		else 
		{
			l[y][0]=i;
			l[y][1]=z;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (h[i][1]!=0) 
		{
			for (int j=1;j<=m;j++)
			{
				map[i][j]=h[i][1];
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (l[i][1]!=0) 
		{
			for (int j=1;j<=n;j++)
			{
			   if (map[j][i]==0) map[j][i]=l[i][1];
			   else
			   {
			   	if (l[i][0]>h[j][0]) map[j][i]=l[i][1];
			   }
			}
		}
	}
	int hh,ll;
	for (hh=1;hh<=n;hh++)
	{
		for (ll=1;ll<=m;ll++)
		{
			printf ("%d ",map[hh][ll]);
		}
		printf ("\n");
	}
	return 0;
}
