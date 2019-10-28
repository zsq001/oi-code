#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,head[N],tot,rd[N];
struct node{
    int to,nxt;
}e[N];
void add(int u,int v){e[++tot].to=v,e[tot].nxt=head[u],head[u]=tot;}
queue<int>Q;
int cnt;
int tsort(){
    for(int i=1;i<=n;i++) if(!rd[i]) Q.push(i);
    while(!Q.empty()){
        int u=Q.front();Q.pop();++cnt;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            rd[v]--;
            if(!rd[v]) Q.push(v);
        }
    }
	return cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int a,b,i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        add(a,b);rd[b]++;
    }
    if(tsort()!=n) printf("T_T\n%d",n-cnt);
    else printf("o(กษ_กษ)o\n");
    return 0;
}
