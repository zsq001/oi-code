#include <cstdio>
int a[100005];
int main()
{
 freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 int n,m,x,y;
 scanf("%d%d%d%d",&n,&m,&x,&y);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int cur=1,ans=0;
 for(int j=1;j<=m;j++)
 {
  int p;
  scanf("%d",&p);
  while(cur<=n&&p>a[cur]+y)
   cur++;
  if(cur>n||p>a[cur]+y)continue;
  ans++,cur++;
 }
 printf("%d\n",ans);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
