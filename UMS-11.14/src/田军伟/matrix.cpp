#include<stdio.h>
int a[1010][1010];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,q,i,x,y,j,z;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=q;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)for(j=1;j<=m;j++)a[y][j]=z;
		if(x==2)for(j=1;j<=n;j++)a[j][y]=z;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)printf("%d ",a[i][j]);
	    printf("\n");
	}
}
