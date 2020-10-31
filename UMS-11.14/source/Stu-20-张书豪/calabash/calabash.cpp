#include <cstdio>
#include <cstring>
#include <queue>
#define eqs 1e-6
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[2005];
 struct node
 {
  double w;
  int u;
  node(int U,int W)
  {
   u=U,w=W;
  }
  bool operator<(const node&a)const
  {
   return w>a.w;
  }
 };
 int head[205],vis[205],s,t,cnt;
 double dis[205];
 void init(int S,int T)
 {
  s=S,t=T;
 }
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 double dijkstra(double x)
 {
  priority_queue<node> q;
  memset(vis,0,sizeof(vis));
  memset(dis,127,sizeof(dis));
  dis[s]=0;
  q.push(node(s,0));
  while(!q.empty())
  {
   int u=q.top().u;
   q.pop();
   if(vis[u])continue;
   vis[u]=1;
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v;
    double w=e[i].w-x;
    if(dis[v]>dis[u]+w)
    {
     dis[v]=dis[u]+w;
     q.push(node(v,dis[v]));
    }
   }
  }
  return dis[t];
 }
}g;
bool check(double x)
{
 return g.dijkstra(x)<0;
}
int main()
{
 freopen("calabash.in","r",stdin);
 freopen("calabash.out","w",stdout);
 int n,m;
 scanf("%d%d",&n,&m);
 g.init(0,n);
 g.addedge(0,1,0);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  g.addedge(u,v,w);
 }
 double l=0,r=1000;
 while(r-l>=eqs)
 {
  double mid=(l+r)/2;
  if(check(mid))r=mid;
  else l=mid;
 }
 printf("%g\n",l);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
