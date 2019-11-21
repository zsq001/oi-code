#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1000000009


struct node{
	int next,to,f;
}e[10005];

int t,n,cnt=1;
int head[2050];
int s[2050],anti[2050];
int tr[2050],tre[2050];

void ade(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	e[cnt].f=0;
	head[from]=cnt;
}


void dfs1(int o,int fa,int now){
	tr[o]=inf,tre[o]=0;	
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa || e[i].f) continue;
		dfs1(x,o,now);
		if(tr[x]<tr[o]) tr[o]=tr[x],tre[o]=i;
	}
	if(s[o]<tr[o]) tr[o]=s[o],tre[o]=inf;
	
}

void dfs2(int o){
	if(tre[o]==inf) return;
	int x=e[tre[o]].to;
	e[tre[o]].f=1;
	e[tre[o]^1].f=1;
	dfs2(x);
	s[x]=s[o];	
}

void work(int o){
	dfs1(o,0,o);
	if(tre[o]==inf) return ;
	dfs2(o);
	s[o]=tr[o];
}

void cleaneage(){
	for(int i=0;i<=n;i++){
		head[i]=0;
	}
	cnt=1;
}



int main()
{
	scanf("%d",&t);
	while(t--){
		cleaneage();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&s[i]);
			anti[s[i]]=i;
		}
		for(int i=1;i<n;i++){
			int tp1,tp2;
			scanf("%d %d",&tp1,&tp2);
			ade(anti[tp1],anti[tp2]);
			ade(anti[tp2],anti[tp1]);
		}
		for(int i=1;i<n;i++){
			work(i);	
		}
		for(int i=1;i<=n;i++){
			printf("%d ",s[i]);
		}
		printf("\n");
	}
	return 0;
}
