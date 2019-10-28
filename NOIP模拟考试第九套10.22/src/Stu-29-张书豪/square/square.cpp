#include <cstdio>
int a[200005],sum[2];
int main()
{
 freopen("square.in","r",stdin);
 freopen("square.out","w",stdout);
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  sum[i%2]+=a[i];
 }
 int ans=0;
 for(int i=1;i<=n;i++)
  if((sum[0]-(i%2==0)*a[i])==(sum[1]-(i%2==1)*a[i]))ans++;
 printf("%d\n",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
