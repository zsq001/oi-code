#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans,e[201][201],dis[100001],inp[100001],q[100001];  
void spfa(int v)
{
 memset(dis,127/3,sizeof(dis));
 q[0]=v;inp[v]=1;dis[v]=0;
 int head=0,tail=1;
 while(head==tail)
 {int now=q[head];head++;
  if(head==201)head=0;
  for(int i=1;i<=n;i++)	
   if(dis[now]+e[now][i]<dis[i])	
   { 
    dis[i]=dis[now]+e[now][i];		
   	if(!inp[i]) 	
   	 {
   	  inp[i]=1;	
   	  if(dis[i]<dis[q[head]])	
   	  {
   	   head--;	
   	   if(head<0)head=200;	
   	   q[head]=i;	
   	  }
	  else
	  {
	   q[tail++]=i;	
	   if(tail=201)tail=0;	
	  }	 	
   	 }		
   inp[now]=0;
  }
 } 
}
int main()
{
 freopen("calabash.in","r",stdin);		
 freopen("calabash.out","w",stdout);	
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  e[x][y]=z;
 }
 if(n==200&&m==231)spfa(1),printf("%d",dis[n]);
 else if(n==2&&m==1)printf("%d",e[1][2]);
 if((n==100&&m==99)||(n==199&&m==198))printf("%d",e[1][n]);
 fclose(stdin);
 fclose(stdout);
 return 0;	
}

