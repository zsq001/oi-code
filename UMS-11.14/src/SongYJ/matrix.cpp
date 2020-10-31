#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int color,time;
}l[1010],h[1010];
int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x;  
} 
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,p,x,y,z;
	n=read();m=read();p=read();
	for(int i=1;i<=p;i++)
	{
		x=read();y=read();z=read();
		if(x==1)
		{
			h[y].color=z;
			h[y].time=i;
		}
		else 
		{
			l[y].color=z;
			l[y].time=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=m;j++)
	    {
		    if(l[j].time>h[i].time)printf("%d ",l[j].color);
		    else printf("%d ",h[i].color);
	    }
	    printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
