#include<cstdio>
#include<algorithm>
#include<queue>
#include<bitset>
#include<map>
#include<cstring>
using namespace std;
int mk[100005],to[100005],next[100005],head[100005],val[100005],tot,d[100005],v[100005];
int n,m,k,maxk,s,p,f,t,l1,l2,hos[100005],dog[100005];
map<int,vector<int> > mp;
void ad(int x,int y,int d){
	to[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
	val[tot]=d;
}
void add(int x,int y,int d1,int d2){
	ad(x,y,d1);
	ad(y,x,d2);
}
struct sta{
	int p,kp,l,dn;
	bitset<1000> dg/*,hs*/,cr;
};
sta st;
bool operator <(const sta &a,const sta &b){
	return a.l>b.l;
}
void spfa(int x){
	if(x==68){
		printf(" ");
	}
	mp[x].resize(n+1);
	//printf("+");
	queue<int>q;
	while(q.size())q.pop();
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[x]=0;v[x]=1;
	q.push(x);
	while(q.size()){
		int a=q.front();q.pop();
	//	printf("pop%d\n",a);
		v[a]=0;
		for(int i=head[a];i;i=next[i]){
			int b=to[i],c=val[i];
			if(d[b]>d[a]+c){
				d[b]=d[a]+c;
				if(!v[b])q.push(b),v[b]=1;
			}
		}
	}
	//printf("*");
	for(int i=1;i<=n;i++)mp[x][i]=d[i];
	//printf("#");
}
int bfs(){
	priority_queue<sta> q;
	q.push(st);
	while(q.size()){
		sta x=q.top();q.pop();
		//printf("POP%d\n",x.p); 
		if(x.dn==k){return x.l;}
		if(x.kp<maxk)for(int i=1;i<=k;i++)if(x.dg[i]){
			sta y=x;
			y.p=dog[i];
			y.kp++;
			y.cr[i]=1;
			y.l+=mp[x.p][y.p];
			y.dg[i]=0;
			q.push(y);
			//printf("push%d\n",y.p);
		}
		if(x.kp)for(int i=1;i<=k;i++)if(x.cr[i]){
			sta y=x;
			y.p=hos[i];
			y.kp--;
			y.cr[i]=0;
			y.l+=mp[x.p][y.p];
			y.dn++;
			//y.hs[i]=0;
			q.push(y);	
			//printf("push%d\n",y.p);		
		}
	}
	return -1;
}
int main(){
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout); 
	scanf("%d %d %d %d %d",&n,&m,&k,&s,&maxk);
	//sta st;
	st.p=s;
	st.kp=0;
	st.l=0;
	st.dn=0;
	for(int i=1;i<=k;i++)scanf("%d",&p),dog[i]=p,st.dg[i]=1;
	for(int i=1;i<=k;i++)scanf("%d",&p),hos[i]=p/*,st.hs[i]=1*/;
	for(int i=1;i<=m;i++)scanf("%d %d %d %d",&f,&t,&l1,&l2),add(f,t,l1,l2);
	//printf(">>>>\n");
	spfa(s),mk[s]=1;
	for(int i=1;i<=k;i++){
		if(!mk[dog[i]])spfa(dog[i]),mk[dog[i]]=1;
		if(!mk[hos[i]])spfa(hos[i]),mk[hos[i]]=1;
	}
	//printf(">>>>\n");
	printf("%d",bfs());
}
