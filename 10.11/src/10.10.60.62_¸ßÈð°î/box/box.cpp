#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,zhan[10000001],top,q,minn=2147483647,vis[10000001],a[3]={1,1,1};

void dfs(int x)
{
 
 if(x==2)
 {for(int i=1;i<=top;i++)
  {
   if(!vis[i])a[2]*=zhan[i];	
  }
  minn=min(2*a[0]*a[1]+2*a[1]*a[2]+2*a[0]*a[2],minn);	
  a[2]=1; return;
 
 }  	
 for(int i=0;i<=top;i++)	
 {
  if(vis[i]&&i!=0)continue;	
  else
  {
   vis[i]=1;
   a[x]*=zhan[i];
   dfs(x+1);	
   vis[i]=0;
   a[x]/=zhan[i];
  }

 }	
}
int main()
{freopen("box.in","r",stdin);
 freopen("box.out","w",stdout);
 zhan[0]=1;
 scanf("%d",&n);
 q=(int)sqrt(n);	
 while(1)
 if(n%2==0)zhan[++top]=2,n/=2;
 else break;
 int nn=n;
 for(int i=3;i<=q;)	
 {
  if(n%i==0)zhan[++top]=i,n/=i;	
  else i+=2;
 } 	
 if(n==nn)zhan[++top]=n;
 dfs(0);
 printf("%d",minn);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
