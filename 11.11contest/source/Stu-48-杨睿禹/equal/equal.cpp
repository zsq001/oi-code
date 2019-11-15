#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#define N 500100
#define M 5010
#define oo 214748364
typedef int int_;
#define int long long
using namespace std ;
inline int in(){
	char ch=getchar();
	int ret=0,flag=1;
	while(ch<'0' or ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*flag;
}
struct edge{
	int u,v,next,val;
}e[N];
struct node{
	int dis;
	int pos;
	bool operator < (const node &x) const {
		return x.dis<dis;
	}
};
int cnt,head[N],n,vis[N],disa[N],disb[N],num,vi5[N],du[N],flag;
void add(int u,int v,int val){
	e[++cnt].v=v;
	e[cnt].val=val;
	e[cnt].u=u;
	e[cnt].next=head[u];
	head[u]=cnt;
}
priority_queue<node> q;
void dijkstraa(int x){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		disa[i]=oo;
	}
	disa[x]=0;
	q.push((node){disa[x],x});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(disa[v]>disa[u]+e[i].val){
				disa[v]=disa[u]+e[i].val;
				if(!vis[v])
					q.push((node){disa[v],v});
			}
		}
	}
}
void dijkstrab(int x){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		disb[i]=oo;
	}
	while(!q.empty())
		q.pop();
	disb[x]=0;
	q.push((node){disb[x],x});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		if(vis[u]) continue;
		vis[u]=1;
		if(disb[u]==disa[u] and !vi5[u]) vi5[u]=1,num++;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if(disb[v]>disb[u]+e[i].val){
				disb[v]=disb[u]+e[i].val;
				if(disb[v]==disa[v] and !vi5[v]) vi5[v]=1,num++;
				if(!vis[v])
					q.push((node){disb[v],v});
			}
		}
	}
}
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	n=in();
	for(int i=1;i<=n-1;i++){
		int u=in(),v=in();
		add(u,v,1);
		add(v,u,1);
		du[v]++,du[u]++;
	}
	for(int i=1;i<=n;i++){
		if(du[i]==1) num++;
		if(num>2){
			break;
		}
	}
	if(num==2) flag=1;
	num=0;
	int m=in();
	for(int i=1;i<=m;i++){
		num=0;
		for(int j=1;j<=n;j++) vi5[j]=0;
		int a=in(),b=in();
		if(a==b){
			cout<<n<<endl;
			continue;
		}
		if(flag){
			dijkstraa(a);
			if(disa[b]%2==0) cout<<"1"<<endl;
			else cout<<"0"<<endl;
			continue;
		}
		dijkstraa(a);
		dijkstrab(b); 
		cout<<num<<endl;
	}
}
