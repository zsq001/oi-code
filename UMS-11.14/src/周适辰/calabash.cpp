#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
 int next,aim,lon;
};
node e[2005];
struct node1{long long  num,power,dep;};
node1 queue[8500000];
int point,head[400],n,m,Head,tail;
double ans=2000000.0;
void frein()
{
 freopen("calabash.in","r",stdin);
 freopen("calabash.out","w",stdout);
}
void freout()
{
 fclose(stdin);
 fclose(stdout);
}
void add(int x,int y,int z )
{
 point++;
 e[point].next=head[x];
 head[x]=point;
 e[point].aim=y;
 e[point].lon=z;
}
int main()
{
	frein();
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
{
 int x,y,z;
 scanf("%d%d%d",&x,&y,&z);
 add(x,y,z);
}
Head=1;
tail=2;
queue[Head].num=1;
queue[Head].dep=1;
while(Head<tail)
{
  if(queue[Head].num==n){Head++;continue;}
 int u=queue[Head].num;
 for(int i=head[u];i!=0;i=e[i].next)
 {
  queue[tail].num=e[i].aim;
  queue[tail].power=queue[Head].power+e[i].lon;
  queue[tail].dep=queue[Head].dep+1;
  if(queue[tail].num==n){ans=min(ans,(double)queue[tail].power/(double)queue[tail].dep);}
  tail++;
 } 
 Head++;
}
int v=(int)(ans*1000);
ans=((double)v/(double)1000);
printf("%.3lf",ans);
freout();
return 0;
} 
