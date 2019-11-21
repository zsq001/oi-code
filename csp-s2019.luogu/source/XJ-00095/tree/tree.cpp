#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v;
}e[2005];
int a[2005],b[2005],tot[2005],n;
namespace sub1
{
 int vis[15],tmp[15],tmp1[15],res[15];
 bool cmp()
 {
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    if(tmp[j]==i)tmp1[i]=j;
  for(int i=1;i<=n;i++)
   if(tmp1[i]>res[i])return false;
   else if(tmp1[i]<res[i])return true;
  return false;
 }
 void dfs(int d)
 {
  if(d==n)
  {
   if(cmp())memcpy(res,tmp1,sizeof(tmp1));
   return;
  }
  for(int i=1;i<n;i++)
   if(!vis[i])
   {
    vis[i]=1;
    swap(tmp[e[i].u],tmp[e[i].v]);
    dfs(d+1);
    vis[i]=0;
    swap(tmp[e[i].u],tmp[e[i].v]);
   }
 }
 void solve()
 {
  memcpy(tmp,a,sizeof(tmp));
  for(int i=1;i<=n;i++)
   res[i]=n;
  dfs(1);
  for(int i=1;i<=n;i++)
   printf("%d ",res[i]);
  puts("");
 }
}
int main()
{
 freopen("tree.in","r",stdin);
 freopen("tree.out","w",stdout);
 int t;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&b[i]);
   a[b[i]]=i;
  }
  for(int i=1;i<n;i++)
  {
   scanf("%d%d",&e[i].u,&e[i].v);
   tot[e[i].u]++,tot[e[i].v]++;
  }
  if(n==1)puts("1");
  else if(n<=10)sub1::solve();
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
