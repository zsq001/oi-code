#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 1000000009

struct node{
	int next,to,val;
	int num,dis;
	friend bool operator < (node a,node b){
		return a.dis > b.dis;
	}
};
node v[20050];
node e[20050];
priority_queue<node> q;
int n,m,t,s,X;
int s2,to,ans,cnt,head[20050];
void add(int from,int toto,int val){
	e[++cnt].next=head[from];
	e[cnt].to=toto;
	e[cnt].val=val;
	head[from]=cnt;
}

void dijstra(int start){
	for(int i=1;i<=n;i++){
		v[i].num=i;
		v[i].dis=inf;
	}
	v[start].dis=0;
	q.push(v[start]);
	while(!q.empty()){
		node temp=q.top();q.pop();
		if(v[temp.num].dis != temp.dis) continue;
		int o=temp.num;
		for(int i=head[o];i!=0;i=e[i].next){
			int x=e[i].to;
			if(v[x].dis > v[o].dis+e[i].val){
				v[x].dis=v[o].dis+e[i].val;
				q.push(v[x]);
			}
		}
	}
}

int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&m,&t,&s,&X);
	scanf("%d",&s2);
	scanf("%d",&to);
	for(int i=1;i<=m;i++){
		int tp1,tp2,tp3,tp4;
		scanf("%d %d %d %d",&tp1,&tp2,&tp3,&tp4);
		add(tp1,tp2,tp3);
		add(tp2,tp1,tp4);
	}
	dijstra(s);
	ans+=v[s2].dis;
	dijstra(s2);
	ans+=v[to].dis;
	printf("%d",ans);
}

