#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

stack<int> s;
struct node{
	int next,to;
};
node e[2000050];
int n,m,op,cnt,tot,root,ans;
int head[500050];
int vis[500050],cd[500050],is[500050],dfn[500050],low[500050];

void add(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}


void tarjan(int o,int fx){
	dfn[o]=low[o]=++cnt;
	int xxx=0;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		cd[o]++;
		if(x==fx) continue;
		if(dfn[x]==0){
			tarjan(x,o);
			low[o]=min(low[o],low[x]);
			if(o==root) xxx++;
    	}
    	else{
    		low[o]=min(low[o],dfn[x]);
		}
	}
	if(o==root && xxx>=2) is[o]=1,ans++;
	else if(low[o] >= dfn[o] && cd[o]>=2) is[o]=1,ans++;
}
//完全忘记割点怎么写qaq 


int main()
{
	freopen("slime.in","r",stdin);
	freopen("slime.out","w",stdout);
   	scanf("%d %d %d",&n,&m,&op);
   	for(int i=1;i<=m;i++){
   		int tp1,tp2;
   		scanf("%d %d",&tp1,&tp2);
   		add(tp1,tp2);
   		add(tp2,tp1);
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(dfn[i]==0) root=i,tarjan(i,0);
	}
   	if(op==1){
   	    printf ("%d",n-ans);
   	    return 0;
    }
    else{
    	printf("%d",(n-ans)/2+1);
	}
   	return 0;
}

/*
8 7 1
1 2
1 3
1 4
2 5
3 6
4 7
7 8
*/



