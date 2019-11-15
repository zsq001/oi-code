#include<stdio.h>

int h[100000],hh[100000],l[100000],ll[100000],n,m,q,x,y,z,i,j;
int main()
{
 freopen("matrix.in","r",stdin);
 freopen("matrix.out","w",stdout);
 scanf("%d %d %d",&n,&m,&q);
 for(i=1;i<=q;i++)
 {
  scanf("%d %d %d",&x,&y,&z);
  if(x==1){
  	h[y]=z;hh[y]=i;
  }
  else{
  	l[y]=z;ll[y]=i;
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   if(hh[i]>ll[j])printf("%d ",h[i]);
   else if(hh[i]<ll[j])printf("%d ",l[j]);
   else printf("0 ");
  }
  printf("\n");
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
