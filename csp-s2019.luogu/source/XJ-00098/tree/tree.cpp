#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 2005
#define ll long long

int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar();}
	while(ch<='9'&&ch>='0') {
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}
int head[maxn],rd[maxn],cnt,id[maxn],pos[maxn];
struct node{
	int v,next;
}e[maxn<<1];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

vector <int> vec[maxn];
const int inf=1<<29;

int dfs(int x,int fx){
	int ret=inf,cut=0;
	int siz=vec[x].size();
	for(int i=0;i<siz;i++){
		if(vec[x][i]==0||vec[x][i]==fx) continue;
		int tmp=dfs(vec[x][i],x);
		if(tmp<ret){
			ret=tmp;
			cut=i;
		}
		if(vec[x][i]<ret){
			ret=vec[x][i];
			cut=i;
		}
	}
	int i=cut;
	vec[x][i]=0;
	swap(id[x],id[vec[x][i]]);
	pos[id[x]]=x;
	pos[id[vec[x][i]]]=vec[x][i];
	return ret;
}
int n;
void work(){
	for(int i=1;i<n;i++){
		dfs(pos[i],0);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",pos[i]);
	}
	puts("");
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(head,0,sizeof(head));
		cnt=0;
		int v,u;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",id[i]);//节点对应的数字 
			pos[id[i]]=i;//数字对应的节点 
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		work();
		for(int i=1;i<=n;i++) vec[i].clear();
	}
	return 0;
}
