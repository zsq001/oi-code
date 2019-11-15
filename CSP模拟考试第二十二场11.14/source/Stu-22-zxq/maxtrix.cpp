#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,q,op,x,y;
struct node{
	int k,v;
};
node a[100010],b[100010];
int main(){
	freopen("maxtrix.in","r",stdin);
	freopen("maxtrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) {
			a[x].v=y;
			a[x].k=i;
		}
		else if(op==2){
			b[x].v=y;
			b[x].k=i;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i].k>b[j].k)
				printf("%d ",a[i].v);
			else printf("%d ",b[j].v);
			if(j==m)  puts("");
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
