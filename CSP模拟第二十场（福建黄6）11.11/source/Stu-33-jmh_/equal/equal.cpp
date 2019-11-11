#include<cstdio>
#include<algorithm>
using namespace std;


struct node{
	int next,to,val;
}e[200005];

int n,m,cnt=1;
int head[100050],dd[100050];
int deep[100050],fa[100050];
int st[100050][21];

void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}

void init_(){
	for(int i=1;i<=n;i++){
		st[i][0]=fa[i];
	}
	for(int k=1;k<=20;k++){
		for(int i=1;i<=n;i++){
			if((1<<k)>=deep[i]) continue;
			st[i][k]=st[st[i][k-1]][k-1];
		}
	}
	
}

void dfs1(int o,int f){
	fa[o]=f;
	deep[o]=deep[f]+1;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==f) continue;
		dfs1(x,o);
	}
}

int dfs(int o,int f){
	int ret=0;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==f) continue;
		ret+=e[i].val;
		if(e[i].val!=0) continue;
		e[i].val=dfs(x,o);
		ret+=e[i].val;
	}
	return ret+1;
}

int qy(int x1,int x2){
	if(x1==x2) return n-1;
	if(deep[x1]<deep[x2]) swap(x1,x2);
	int xx1=x1,xx2=x2;
    int d=deep[x1]-deep[x2];
    int dx=0;
	for(int k=20;k>=0;k--){
		if(d&(1<<k)) x1=st[x1][k],dx+=(1<<k);
	}
	if(x1 != x2){
		for(int k=20;k>=0;k--){
			if(st[x1][k]!=st[x2][k]) x1=st[x1][k],x2=st[x2][k],dx+=(1<<(k+1)); 
		}
		dx+=2;
	}
	
	if(dx%2==1) return 0;
	
	dx/=2;
	
	swap(xx1,x1),swap(xx2,x2);
	
	
	d=dx-1;
	for(int k=20;k>=0;k--){
		if(d&(1<<k)) x1=st[x1][k];
	}
	
	int flag=0;
	xx2=x2;
	if(deep[x2] <= d) flag=1;
	for(int k=20;k>=0;k--){
		if(d&(1<<k)) x2=st[x2][k];
	}
	if(fa[x2] != fa[x1]) flag=1;
	
	if(flag) x2=fa[fa[x1]];
	
	int ret=0;
	for(int i=head[fa[x1]];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==x1 || x==x2) continue;
	    ret+=e[i].val;
	}
    return ret+1;
}

int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int tp1,tp2;
		scanf("%d %d",&tp1,&tp2);
		ade(tp1,tp2);
		ade(tp2,tp1);
		dd[tp1]++;
		dd[tp2]++;
	}
	
	for(int i=1;i<=n;i++){
		if(dd[i]==1) dfs(i,0);
	}
	
	dfs1(1,0);
	
	init_();
	
	
	
	scanf("%d",&m);

	for(int i=1;i<=m;i++){
		int tp1,tp2;
		scanf("%d %d",&tp1,&tp2);
		printf("%d\n",qy(tp1,tp2));
	}
	return 0;
}
/*
4
1 2
2 3
2 4
2 
1 2
1 3

7
1 2
1 5
2 3
3 4
5 6
5 7
5
5 4
6 7
1 6
1 4
5 5

9
1 2
1 7
1 6
2 3
2 4
2 5
6 8
8 9
5
7 9
4 1
5 7
4 8
3 5


*/
