#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 1005

inline int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}


struct node{
	int t=0,num=0;
}l[maxn],h[maxn],a[maxn][maxn];
//struct no{
//	int hl,pos,num;
//}t[maxn];

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,x,y,z,q;
	n=in();m=in();q=in();
	
	for(int i=1;i<=q;i++){
		x=in();y=in();z=in();
		if(x==1){
			h[y].t=i;h[y].num=z;
		}else {
			l[y].t=i;l[y].num=z;
		}
	}
//	for(int i=1;i<=n;i++){
//		t[h[y].t].hl=1;t[h[y].t].pos=y;t[h[y].t].pos=h[y].num;
//	}
//	for(int i=1;i<=m;i++){
//		t[l[y].t].hl=0;t[l[y].t].pos=y;t[l[y].t].pos=l[y].num;
//	}
//	for(int i=1;i<=q;i++){
//		if(!t[i].pos) continue;
//		if(t[i].hl){
//			int 
//			for(int i=1;i<=m;i++)
//		}
//	}
	for(int i=1;i<=n;i++){
		int tt=h[i].t,nn=h[i].num;
		for(int j=1;j<=m;j++){
			if((!a[i][j].num)||a[i][j].t<tt) a[i][j].t=tt,a[i][j].num=nn;
		}
	}
	for(int i=1;i<=m;i++){
		int tt=l[i].t,nn=l[i].num;
		for(int j=1;j<=n;j++){
			if((!a[j][i].num)||a[j][i].t<tt) a[j][i].t=tt,a[j][i].num=nn;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%d ",a[i][j].num);
		puts("");
	}
	return 0;
}
