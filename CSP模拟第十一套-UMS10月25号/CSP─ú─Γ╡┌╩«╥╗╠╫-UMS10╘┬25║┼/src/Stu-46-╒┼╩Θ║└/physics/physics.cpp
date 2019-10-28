#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int a,t;
}p[100005];
bool cmp(const node&a,const node&b)
{
 return a.a>b.a;
}
int main()
{
 freopen("physics.in","r",stdin);
 freopen("physics.out","w",stdout);
 int n;
 double dist1=0,dist2=0;
 long long v=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&p[i].a,&p[i].t);
  dist1+=(double)v*p[i].t+1.0/2*p[i].a*p[i].t;
  v+=p[i].a*p[i].t;
 }
 sort(p+1,p+n+1,cmp);
 v=0;
 for(int i=1;i<=n;i++)
 {
  dist2+=(double)v*p[i].t+1.0/2*p[i].a*p[i].t;
  v+=p[i].a*p[i].t;
 }
 printf("%.1lf\n",dist2-dist1);
 return 0;
}
