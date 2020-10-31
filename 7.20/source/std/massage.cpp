#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
queue<int>q;
int dis[12000];
int vis[12000];
int ans;
int first[12000],cnt,tot;
struct node{
	int to,next,val;
}edge[22000];
int prime[12000];
int fa[12000],ANS[12000],top;
void add(int u,int v,int val){
	edge[++cnt].to = v;
	edge[cnt].next = first[u];
	edge[cnt].val = val;
	first[u] = cnt;
}
bool isprime(int n){
	for(int i = 2; i*i <= n;i++)
		if(n%i==0)return 0;
	return 1;
}
void getprime(){
	for(int i = 1000; i <= 9999; i++){
		if(isprime(i))prime[++tot] = i;
	}
}
int check(int a,int b){
	int a1,a2,a3,a4;
	int b1,b2,b3,b4;
	a1 = a/1000,a2 = (a/100)%10,a3 = (a%100)/10,a4 = a%10;
	b1 = b/1000,b2 = (b/100)%10,b3 = (b%100)/10,b4 = b%10;
	if(a1==b1&&a2==b2&&a3==b3&&a4!=b4)return abs(a4-b4);
	if(a1==b1&&a2==b2&&a3!=b3&&a4==b4)return abs(a3-b3);
	if(a1==b1&&a2!=b2&&a3==b3&&a4==b4)return abs(a2-b2);
	if(a1!=b1&&a2==b2&&a3==b3&&a4==b4)return abs(a1-b1);
	return 0;
}
int spfa(int s,int e) {
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(q.size()){
		int x = q.front();
		q.pop();vis[x] = 0;
		for(int i = first[x];i;i = edge[i].next){
			int to = edge[i].to;
			if(dis[to]>dis[x]+edge[i].val){
				fa[to] = x;
				dis[to] = dis[x]+edge[i].val;
				if(!vis[to]){
					q.push(to);
					vis[to] = 1; 
				}
			}
		}
	}
	return dis[e];
}
int T,Q;
int main(){
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout); 
	scanf("%d%d",&T,&Q);
	getprime();
	for(int i = 1; i <= tot; i++)
		for(int j = i+1; j <= tot; j++){
			int val;
			if(val = check(prime[i],prime[j])){
				add(prime[i],prime[j],val);
				add(prime[j],prime[i],val);
			}
		}
	int s,e;
	while(T--){
		scanf("%d%d",&s,&e);
		ans = spfa(s,e);
		if(ans<1000000000)printf("%d\n",ans);
		else {
			printf("impossible\n");
			continue;
		}
		if(Q){
			fa[s] = 0;
			int ct = e;
			ANS[0] = e;
			while(ct){
				ANS[++top] = fa[ct];
				ct = fa[ct];
			}
			printf("%d",ANS[top-1]);
			for(int i = top-2;i>=0 ;i--)printf("-%d",ANS[i]);
			printf("\n");
			memset(ANS,0,sizeof ANS);
			memset(fa,0,sizeof fa);
			top = 0;
		}
		
	}
} 
