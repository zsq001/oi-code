#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

bool vis[maxn],ok[maxn];
int n,k,cnt,head[maxn],eaten_num=0;

struct node{
	int v,next;
}e[maxn];

struct q{
	int val,pos,bh;
}son[maxn];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs1(int x,int fa){
	son[x].pos=n+1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,x);
		if(son[v].val>son[x].val||(son[v].val==son[x].val&&son[v].pos<son[x].pos)){
			son[x].pos=son[v].pos;
			son[x].val=son[v].val;
			son[x].bh=v;
		}
	}
	if(!son[x].val)son[x].pos=x;
	son[x].val++;
	return ;
}

void update(int x,int fa){
	son[x].val=0,son[x].pos=n;
	int no=son[x].bh;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].v;
		if(v==fa) continue;
		if(v==no) update(v,x);
		else if(son[v].val>son[x].val||(son[v].val==son[x].val&&son[v].pos<=son[x].pos)){
			son[x].pos=son[v].pos;
			son[x].val=son[v].val;
			son[x].bh=v;
		}
	}
	return ;
}


int main(){
	int a;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		son[i].bh=-1;
		add(i,a);
		add(a,i);
	}
	printf("%d\n",k);
	eaten_num++;
	dfs1(k,-1);
	while(eaten_num<=n){
		printf("%d\n",son[k].pos);
		eaten_num+=son[k].val;
		update(k,-1);
	}
}
