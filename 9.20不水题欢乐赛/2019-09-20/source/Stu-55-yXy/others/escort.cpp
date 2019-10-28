#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

const int N=10005;

int th[10]={1,3,9,27,81},tn[10]={0,1,10,100,1000,10000,100000};
int n,m,S,T,v;
struct edge{int to,next,val;}e[N<<1];
int head[N],tot;
int stt[N],edd[N];
int d[N][255],mp[255];
struct node{
	int x,s;
};
queue<node>q;
bool vis[N][255];

void init(){
	for(int a1=0;a1<3;a1++)
	 for(int a2=0;a2<3;a2++)
	  for(int a3=0;a3<3;a3++)
	   for(int a4=0;a4<3;a4++)
	    for(int a5=0;a5<3;a5++)
		 mp[a1*th[0]+a2*th[1]+a3*th[2]+a4*th[3]+a5*th[4]]=a1+a2*10+a3*100+a4*1000+a5*10000;
//	for(int i=0;i<243;i++)printf("%d %d\n",i,mp[i]);
}

void add(int x,int y,int w){
//	printf("%d %d\n",x,y);
	e[++tot].to=y; e[tot].next=head[x]; e[tot].val=w; head[x]=tot;
}

int num(int x,int y){return x/tn[y]%10;}

void spfa(){
	memset(d,0x3f,sizeof(d));
	int x,y,s,c,w,t=0;
	for(int i=0;i<n;i++)
		if(stt[S]&(1<<i))t+=th[i+1];
	d[S][t]=0; node now,nxt;
	now.x=S; now.s=t;
	q.push(now);
	while(!q.empty()){
		now=q.front(); q.pop();
		x=now.x; s=now.s; vis[x][s]=0;
//		printf("x:%d %d-%d   d:%d\n",x,s,mp[s],d[x][s]);
		for(int i=head[x];i;i=e[i].next){
			y=e[i].to; c=0;
			if(stt[y]){
				for(int j=0;j<n;j++)if(stt[y]&(1<<j)){
					t=num(s,j+1);
					if(t)continue;
					c+=th[j]*1;
				}
			}
			if(edd[y]){
				for(int j=0;j<n;j++)if(edd[y]&(1<<j)){
					t=num(s,j+1);
					if(t!=1)continue;
					c+=th[j]*2-1;
				}
			}
			c+=s;
			if(d[y][c]>d[x][s]+e[i].val){
				d[y][c]=d[x][s]+e[i].val;
//				printf("   y:%d %d-%d\n",y,c,mp[c]);
				if(!vis[y][c]){
					nxt.x=y; nxt.s=c;
					vis[y][c]=1; q.push(nxt);
				}
			}
		}
	}
}

int main(){
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	init();
	scanf("%d%d%d%d%d",&n,&m,&S,&T,&v);
	int x,y,t;
	for(int i=1;i<=T;i++){
		scanf("%d",&t);
		stt[t]|=1<<(i-1);
	}
	for(int i=1;i<=T;i++){
		scanf("%d",&t);
		edd[t]|=1<<(i-1);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&t);
		add(x,y,t); scanf("%d",&t); 
		add(y,x,t);
	}
	spfa();
	t=1e9; x=0;
	for(int i=1;i<=T;i++)x+=th[i-1]*2;
	for(int i=1;i<=n;i++)t=min(t,d[i][x]);
	printf("%d\n",t);
	return 0;
}
