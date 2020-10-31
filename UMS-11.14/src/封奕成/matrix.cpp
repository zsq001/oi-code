#include <stdio.h>
int n,m,q;
struct pack{long long w;int num;} h[1010],l[1010];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		int x,y;
		long long z;
		scanf("%d%d%I64d",&x,&y,&z);
		if(x==1) h[y].w=z,h[y].num=i;
		else l[y].w=z,l[y].num=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!h[i].w&&!l[j].w) printf("0 ");
			else if(!h[i].w) printf("%d ",l[j].w);
			else if(!l[j].w) printf("%d ",h[i].w);
			else{
				if(h[i].num>l[j].num) printf("%d ",h[i].w);
				else printf("%d ",l[j].w);
			}
		}
		printf("\n");
	}
	return 0;
}
