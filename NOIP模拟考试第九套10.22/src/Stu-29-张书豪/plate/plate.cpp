#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
int a[505][505];
int main()
{
 freopen("plate.in","r",stdin);
 freopen("plate.out","w",stdout);
 int n,m,p;
 scanf("%d%d%d",&n,&m,&p);
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   scanf("%d",&a[i][j]);
  sort(a[i]+1,a[i]+m+1);
  int tmp=a[i][1];
  for(int j=1;j<=m;j++)
   a[i][j]-=tmp;
 }
 int ans=0;
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
  {
   bool flag=true;
   for(int k=1;k<=m;k++)
    if(a[i][k]!=a[j][k])
    {
     flag=false;
     break;
    }
   ans+=flag;
  }
 printf("%d\n",ans);
 //printf("Time: %.3lf s\n",(double)clock()/CLOCKS_PER_SEC);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
