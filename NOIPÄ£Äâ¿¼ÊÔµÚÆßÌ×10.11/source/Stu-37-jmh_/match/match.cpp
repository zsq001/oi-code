#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 1000000009

struct node{
	int next,to,val;
}e[40000050];

int n,m,dx,dy,start,towhere=500005,tot,cnt=1,maxflow;
int ye[100050],bl[100050];
int head[500050],late[500050],dis[500050];
int tree[400050];
queue<int> q;

void add(int from,int to,int val){
	e[++cnt].next=head[from];
	e[cnt].val=val;
	e[cnt].to=to;
	head[from]=cnt;
}

bool check1(int o,int now){
	if(bl[o]>=now) return true;
	else return false;
}
bool check2(int o,int now){
	if(bl[o]>now) return true;
	else return false;
}


void build(int o,int l,int r){
	tot=max(tot,o);
	if(l==r){
		add(o,towhere,1);
		add(towhere,o,0);
		return ;
	}
	int mid=(l+r)>>1;
	add(o,o<<1,mid-l+1);
	add(o<<1,o,0);
	build(o<<1,l,mid);
	add(o,o<<1|1,r-mid);
	add(o<<1|1,o,0);
	build(o<<1|1,mid+1,r);
}

void query(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l && r<=qr){
		add(x,o,1);
		add(o,x,0);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) query(o<<1,l,mid,ql,min(qr,mid),x);
	if(qr>mid) query(o<<1|1,mid+1,r,max(mid+1,ql),qr,x);
}

void cls(){
	for(int i=0;i<=tot;i++){
		dis[i]=inf;
		late[i]=head[i];
	}
	dis[towhere]=inf;
	late[towhere]=head[towhere];
	dis[start]=0;
	queue<int> empty;
	swap(empty,q);
}

bool bfs(int st,int to){
	cls();
	q.push(st);
	while(!q.empty()){
		int o=q.front();
		q.pop();
		for(int i=head[o];i!=0;i=e[i].next){
			int x=e[i].to;
			if(e[i].val>0 && dis[x]>dis[o]+1){
				dis[x]=dis[o]+1;
				q.push(x);
			}
		}
	}
	return dis[to]<inf;
}

int dfs(int o,int limit){
	if(limit==0 || o==towhere) return limit;
	int flow=0;
	for(int i=late[o];i!=0;i=e[i].next){
		late[o]=i;
		int x=e[i].to;
		if(dis[x]==dis[o]+1){
			int water=dfs(x,min(limit,e[i].val));
			limit-=water;
			flow+=water;
			e[i].val-=water;
			e[i^1].val+=water;
		}
		if(limit==0) break;
	}
	return flow;
}

void dinic(int st,int to){
	while(bfs(st,to)){
		maxflow+=dfs(st,inf);
	}
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&dx,&dy);
	for(int i=1;i<=n;i++){
		scanf("%d",&ye[i]);
	}
	bl[0]=-inf;
	bl[m+1]=inf+inf;
	for(int i=1;i<=m;i++){
		scanf("%d",&bl[i]);
	}
	build(1,1,m);
	for(int i=1;i<=n;i++){
		add(start,tot+i,1);
		add(tot+i,start,0);
		int ql,qr,l=1,r=m;
		int tp=max(ye[i]-dx,1);
		while(l<=r){
			int mid=(l+r)>>1;
			if(check1(mid,tp)) r=mid-1;
			else l=mid+1;
		}
		ql=l;
		tp=min(ye[i]+dy,inf);
		l=1,r=m;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check2(mid,tp)) r=mid-1;
			else l=mid+1;
		}
		qr=r;
		query(1,1,m,ql,qr,tot+i);
	}
	tot+=n;
	dinic(start,towhere);
	printf("%d",maxflow);
	return 0;
}


