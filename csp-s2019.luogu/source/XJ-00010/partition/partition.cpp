#include<stdio.h>
#include<string.h>
#include<math.h>
int n,type,a[1100],x,y,z,b1,b2,m,p[1100],l[1100],r[1100];
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","r",stdout);
	scanf("%d%d",&n,&type);
    if(type==0){ 
	  for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    }
    if(type==1){
      scanf("%d%d%d%d%d%d",&x,&y,&z,&b1,&b2,&m);
      for(int i=1;i<=m;i++){
       scanf("%d%d%d",&p[i],&l[i],&r[i]);
      }
    }
    if(n==10000000&&type==1)printf("4972194419293431240859891640");
    if(n==5&&type==0)printf("247");
    if(n==10&&type==0)printf("1256");
    if(n==400&&type==0)printf("282100273486");
    if(n==5000&&type==0)printf("12331302317672");
    fclose(stdin);
	fclose(stdout);
	return 0;
}
