#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1005
#define M 5005
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,cnt;
int f[N],head[N]; 
bool flag,mark[N];
double dis[N];
struct data{int to,next,t;double v;}e[M];
void insert(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].t=w;}
void rebuild(double x)
{
     for(int i=1;i<=n;i++)
         for(int j=head[i];j;j=e[j].next)
             e[j].v=e[j].t*x-f[e[j].to];
}
void spfa(int x)
{
     mark[x]=1;
     for(int i=head[x];i;i=e[i].next)
         if(e[i].v+dis[x]<dis[e[i].to])
         {
              if(mark[e[i].to]){flag=1;return;}
              else
              {
                   dis[e[i].to]=e[i].v+dis[x];
                   spfa(e[i].to);
              }
         }
     mark[x]=0;
}
bool jud()
{
     for(int i=1;i<=n;i++)dis[i]=mark[i]=0;
     flag=0;
     for(int i=1;i<=n;i++)
         {spfa(i);if(flag)return 1;}
     return 0;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        f[i]=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        insert(u,v,w);
    }
    double l=0,r=10000;
    while(r-l>0.001)
    {
        double mid=(l+r)/2;
        rebuild(mid);
        if(jud())l=mid;
        else r=mid;
    }
    printf("%.2lf",l);
    return 0;
}
