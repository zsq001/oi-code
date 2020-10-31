#include<stdio.h>
int a[105][5],map[101][101]={0};
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,q,i,j;
	scanf("%d %d %d",&m,&n,&q);
	for(i=1;i<=m;i++)
	 for(j=1;j<=3;j++)
	 scanf("%d ",&a[i][j]);
	 for(i=1;i<=m;i++)
	  for(j=1;j<=3;j++)
	 if(a[i][1]==1) 
	 {
	 	for(int k=1;k<=m;k++)
	 	 map[a[i][2]][k]=a[i][3];
	 }
	else if(a[i][1]==2)
	{
		for(int k=1;k<=m;k++)
		map[k][a[i][2]]=a[i][3];
	} 
	 for(i=1;i<=m;i++)
	 {
	 	for(j=1;j<=n;j++)
	 	{
	 		 printf("%d ",map[i][j]);
	   
	 	}
	 	printf("\n");
	  
	 }
	 fclose(stdin);
	 fclose(stdout);
	 return 0;  
}
