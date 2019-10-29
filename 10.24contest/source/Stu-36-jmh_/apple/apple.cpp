#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE{
	int next,to;
}e[50050];
int head[50050];

struct node{
	int lt,rt;
	int mx,mxt;
}tree[50050];
int lazy[50050],deep[50050],anti[50050];
int n,k,cnt,tot;
queue<int> q;


void add(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}

void pushup(int o,int fa){
	tree[o].mx=-1;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
		if(tree[x].mx > tree[o].mx || (tree[o].mx==tree[x].mx && anti[tree[o].mxt] > anti[tree[x].mxt])){
			tree[o].mx=tree[x].mx;
			tree[o].mxt=tree[x].mxt;
		}
	}
}

void pushdown(int o,int fa){
	if(lazy[o]==0) return ;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
	    tree[x].mx-=lazy[o];
	    lazy[x]+=lazy[o];
	}
	lazy[o]=0;
}

void build(int o,int fa){
	lazy[o]=0;
	deep[o]=deep[fa]+1;
	if(e[head[o]].next==0 && e[head[o]].to==fa){
		tree[o].mx=deep[o];
		tree[o].mxt=++tot;
		anti[tot]=o;
		tree[o].lt=tot;
		tree[o].rt=tot;
		return ;
	}
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
		build(x,o);
		if(i==head[o]) tree[o].lt=tree[x].lt;
		if(e[i].next==0 || (e[e[i].next].next==0 && e[e[i].next].to==fa)) tree[o].rt=tree[x].rt;
	}
	pushup(o,fa);
}



void update(int o,int val){
	lazy[o]+=val;
	tree[o].mx-=val;
}

void mnus(int o,int fa,int pos,int val){
	pushdown(o,fa);
	if(e[head[o]].next==0 && e[head[o]].to==fa){
		tree[o].mx-=val;
		return ;
	}
 	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(x==fa) continue;
		if(tree[x].lt<= pos && pos<=tree[x].rt){
			mnus(x,o,pos,val+(deep[x]!=0));
			deep[o]=0;
		}
		else update(x,val);
	}
	pushup(o,fa);
}


int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
    	int tp;
    	scanf("%d",&tp);
    	add(tp,i);
    	add(i,tp);
	}
	deep[50001]=-1;
	build(k,50001);
	
    while(tree[k].mx){
    	q.push(tree[k].mxt);
    	mnus(k,50001,tree[k].mxt,0);
	}
	printf("%d\n",k);
    while(!q.empty()){
        int tp=q.front();
        q.pop();
        printf("%d\n",anti[tp]);
	}
	return 0;
}
