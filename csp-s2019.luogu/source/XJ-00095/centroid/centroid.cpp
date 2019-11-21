#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct edge
{
 int v,next;
}e[600005];
int head[300005],t[300005],cnt,n;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
namespace subA
{
 int p[300005];
 bool check()
 {
  bool flag=true;
  for(int i=1;i<=n;i++)
   flag&=(t[i]<=2);
  return flag;
 }
 void dfs(int d,int u,int fa)
 {
  p[d]=u;
  for(int i=head[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(v!=fa)dfs(d+1,v,u);
  }
 }
 int calc(int x,int y)
 {
  if((x+y)%2==0)return p[(x+y)/2];
  else return p[(x+y)/2]+p[(x+y)/2+1];
 }
 void solve()
 {
  int r;
  for(int i=1;i<=n;i++)
   if(t[i]==1)
   {
    r=i;
    break;
   }
  dfs(1,r,0);
  long long ans=0;
  for(int x=1;x<n;x++)
  {
   int y=x+1;
   ans+=calc(1,x)+calc(y,n);
  }
  cout<<ans<<endl;
 }
}
namespace sub1
{
 void solve(){}
}
int main()
{
 freopen("centroid.in","r",stdin);
 freopen("centroid.out","w",stdout);
 ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  memset(t,0,sizeof(t));
  memset(head,0,sizeof(head));
  cnt=0;
  cin>>n;
  for(int i=1;i<n;i++)
  {
   int u,v;
   cin>>u>>v;
   t[u]++,t[v]++;
   addedge(u,v);
   addedge(v,u);
  }
  if(n<=7)sub1::solve();
  if(subA::check())subA::solve();
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
