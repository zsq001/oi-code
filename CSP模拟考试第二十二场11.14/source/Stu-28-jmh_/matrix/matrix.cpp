#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int n,m,tim,val;
}hl[1000005];
int n,m,q,tot;
int s[1005][1005];

bool cmp(node a,node b){
	return a.tim<b.tim;
}


int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		hl[i].n=i;
	}
	for(int i=1;i<=m;i++){
		hl[i+n].m=i;
	}
	for(int i=1;i<=q;i++){
		int tp1,tp2,tp3;
		scanf("%d %d %d",&tp1,&tp2,&tp3);
		if(tp1==1){
			hl[tp2].val=tp3;
			hl[tp2].tim=i;
		}
		else{
			hl[tp2+n].val=tp3;
			hl[tp2+n].tim=i;	
		}		
	}
	sort(hl+1,hl+1+n+m,cmp);
	for(int i=1;i<=n+m;i++){
		if(hl[i].m==0 && hl[i].n!=0){
			for(int j=1;j<=m;j++){
				s[hl[i].n][j]=hl[i].val;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				s[j][hl[i].m]=hl[i].val;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
