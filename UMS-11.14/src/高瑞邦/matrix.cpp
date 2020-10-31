#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,top[1001],tmp[1001];
struct node{int s,k;}zheng[1001],heng[1001];
int main()
{
 freopen("matrix.in","r",stdin);		
 freopen("matrix.out","w",stdout);	
 scanf("%d%d%d",&n,&m,&q);
 int x,y,z;
 for(int i=1;i<=q;i++)
 {
  scanf("%d%d%d",&x,&y,&z);	
  if(x==1)
  {
   heng[y].s=z;
   heng[y].k=i;
  }
  if(x==2)
  {
   zheng[y].s=z;
   zheng[y].k=i;	
  }
 }	
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
 {
  if(zheng[j].k<heng[i].k)printf("%d ",heng[i].s);
  else printf("%d ",zheng[j].s);
 }
  printf("\n");
 }
 fclose(stdin);
 fclose(stdout);
 return 0;	
}
