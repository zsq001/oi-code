#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
int n,m,q,xs,ys,zs,a[1010][1010],x[1000100],y[1000100],z[1000100],cnt;
int main () {
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if(q<=2000){
		for(int i=1;i<=q;i++){
		scanf("%d%d%d",&xs,&ys,&zs);
		if(xs==1){
			for(int i=1;i<=m;i++){
				a[ys][i]=zs;
			}
		}
		if(xs==2){
			for(int j=1;j<=n;j++){
				a[j][ys]=zs;
			}
		}
	}
		for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
		}
	}
	else{
		for(int i=1;i<=q;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
		for(int i=q;i>=0;i--){
			if(x[i]==1){
				for(int exi=1;exi<=m;exi++){
					if(a[y[i]][exi]==0){
						a[y[i]][exi]=z[i];
					}
				}
			}
		
			if(x[i]==2){
				for(int exj=1;exj<=n;exj++){
					if(a[exj][y[i]]==0){
						a[exj][y[i]]=z[i];
					}
				}
			}
			for(int exi=1;exi<=m;exi++){
				for(int exj=1;exj<=n;exj++){
					if(a[exi][exj]==0) cnt++;
				}
			}
			if(cnt==0){
				for(int exi=1;exi<=m;exi++){
					for(int exj=1;exj<=n;exj++){
						printf("%d ",a[exi][exj]);
					}
					printf("\n");
				}
				return 0;
			}
			cnt=0;
		}
	}
	return 0;
}

