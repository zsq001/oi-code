#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 1000005
#define maxm 1005
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int map[maxm][maxm];
bool vis[maxm][maxm];
struct node{
	int type,pt,val;
}st[maxn];
int n,m,q;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=q;i++)
		read(st[i].type),read(st[i].pt),read(st[i].val);
	while(q){
		if(st[q].type==1) {
			for(register int i=1;i<=m;i++){
				if(vis[st[q].pt][i]) continue;
				map[st[q].pt][i]=st[q].val;
				vis[st[q].pt][i]=1;
			}
		}
		else{
			for(register int i=1;i<=n;i++){
				if(vis[i][st[q].pt]) continue;
				map[i][st[q].pt]=st[q].val;
				vis[i][st[q].pt]=1;
			}
		}
		q--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",map[i][j]);
		puts("");
	}
	return 0;
		
}
