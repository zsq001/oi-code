#include<bits/stdc++.h>
using namespace std;
int n,m,x,i,y,j,g,k,sum=0,ans=0;//i,j
int a[1001][1001],b[10001],c[10001];
int main()
{
	freopen("meal","r",stdin);
	freopen("meal","w",stdout);
	scanf("%d %d",&n,&m);
	int j1=0;
	int i1=0;
	for(int i=0;i<n*m;++i)
	b[i]=y;
	y=a[i1][j1];
	for(i1=0;i1<n;++i1)
	for(j1=0;j1<m;++j1)
	scanf("%d",&y);
	
//	if(b[0];b[0]!=0;--i)
//	{c[0]=sum+y;
//	}
	do
	c[i]=c[i+1];
	for(b[i];b[i]!=0;--i)
	{c[i]=sum+y;
	}
	while(c[i]=0)
	for(int i=0;i<m;++i)
	{x=b[y];b[y]=b[y+1];++ans;
	}
	
	/*x==a[i1][j1];
	for(int c=0;c<m;++c)
	{
	   if(a[i1][j1]==x)
 	  {a[j1]==a[j1+1];++g;
	  }
    }   
	while(a[i1]!=a[i1+1]&&g<=(1/2)*i1*j1)
    {++ans;
    }
	*/cout<<ans;
	return 0;
}

