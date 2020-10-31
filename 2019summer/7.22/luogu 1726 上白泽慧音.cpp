#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<cstdlib>
#define maxn 100010
using namespace std;
struct Edge{
    int u,v,ne;
}e[maxn];
stack<int>S;
int cnt,tot,n,m,jh[maxn],siz[maxn],low[maxn],dfn[maxn],vis[maxn],hl[maxn],maxsiz,id;
void add(int u,int v)
{
    e[++cnt].u=u;
    e[cnt].v=v;
    e[cnt].ne=hl[u];
    hl[u]=cnt;
}
void tarjan(int x)
{
    vis[x]=1;
    low[x]=dfn[x]=++cnt;
    S.push(x);
    for(int i=hl[x];i;i=e[i].ne){
        int v=e[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(vis[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        ++tot;
        while(1){
            int tp=S.top();
            S.pop();
            siz[tot]++;
            jh[tp]=tot;
            vis[tp]=0;
            if(tp==x) break;
        }
    } 
}
int getfst(int ID){for(int i=1;i<=n;++i) if(jh[i]==ID) return i;}
int main()
{
    int x,y,op;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&op);
        if(op==1) add(x,y);
        else{
            add(x,y);
            add(y,x);
        }
    }
    cnt=0;
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=tot;++i){
        if((siz[i]>maxsiz)||((siz[i]==maxsiz)&&(getfst(i)<getfst(id)))){
            maxsiz=siz[i];
            id=i;
        }
    }
    printf("%d\n",maxsiz);
    for(int i=1;i<=n;++i) if(jh[i]==id) printf("%d ",i);
    return 0;
}
