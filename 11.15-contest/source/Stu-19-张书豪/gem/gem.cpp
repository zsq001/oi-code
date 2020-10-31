#include <cstdio>
int a[200005],n,m;
namespace sub1
{
 int d[200005];
 void solve()
 {
  while(m--)
  {
   int op;
   scanf("%d",&op);
   if(op==1)
   {
    int l,r;
    scanf("%d%d",&l,&r);
    for(int i=l+1;i<=r;i++)
     d[i]=a[i]-a[i-1];
    int ans=0,res=0;
    for(int i=l+1;i<=r;i++)
    {
     res+=d[i];
     if(ans<res)ans=res;
     if(res<0)res=0;
    }
    printf("%d\n",ans);
   }
   else
   {
    int l,r,x,y;
    scanf("%d%d%d%d",&l,&r,&x,&y);
    for(int i=l;i<=r;i++)
     a[i]=x+(i-l)*y;
   }
  }
 }
}
int main()
{
 freopen("gem.in","r",stdin);
 freopen("gem.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 if(n<=1000&&m<=1000)sub1::solve();
 fclose(stdin);
 fclose(stdout);
 return 0;
} 
