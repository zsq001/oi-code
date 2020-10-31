#include <bits/stdc++.h>
#define mset(a,b) memset(a,(b),sizeof(a))
#define scan(a) scanf("%d",&a)
#define debug puts("Hello,world.")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int init(){
    int x = 0,f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c=='-')f = -1;
        c = getchar();
    }
    while(isdigit(c))x = ((x<<1)+(x<<3))+c-'0',c = getchar();
    return x*f;
}
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
struct edge{
    int to,ne;
}e[maxn<<1];
int head[maxn],cnt;
void put(int x,int y){
    e[++cnt] = (edge){y,head[x]};
    head[x] = cnt;
    e[++cnt] = (edge){x,head[y]};
    head[y] = cnt;
}
int size[maxn],top[maxn],id[maxn],hson[maxn],fa[maxn],beg[maxn],end[maxn],dep[maxn];
int w[maxn],n,m;
int s[maxn],cur[maxn];
bool vis[maxn];
void dfs_1(){
    int t = 0;
    s[++t] = 1;
    size[1] = 1,dep[1] = 1;
    memcpy(cur,head,sizeof head);
    while(t){
        int u = s[t];
        while(cur[u]&&e[cur[u]].to==fa[u])cur[u] = e[cur[u]].ne;
        if(!cur[u]){
            --t;
            if(fa[u]){
                size[fa[u]]+=size[u];
                if(size[u]>size[hson[fa[u]]])hson[fa[u]] = u;
            }
            continue;
        }
        int v = e[cur[u]].to;
        s[++t] = v;
        fa[v] = u,size[v] = 1,dep[v] = dep[u]+1;
        cur[u] = e[cur[u]].ne;
    }
}
void dfs_2(){
    int t = 0,tot = 0;
    s[++t] = 1;
    top[1] = 1,beg[1] = id[1] = ++tot;
    memcpy(cur,head,sizeof(head));
    while(t){
        int u = s[t];
        if(!vis[u]){
            vis[u] = 1;
            if(hson[u]){
                int v = hson[u];
                s[++t] = v;
                top[v] = top[u],beg[v] = id[v] = ++tot;
            }
            continue;
        }
        while(cur[u]&&(e[cur[u]].to==fa[u]||e[cur[u]].to==hson[u]))cur[u] = e[cur[u]].ne;
        if(!cur[u]){
            --t;
            end[u] = tot;
            continue;
        }
        int v = e[cur[u]].to;
        s[++t] = v;
        top[v] = v,beg[v] = id[v] = ++tot;
        cur[u] = e[cur[u]].ne;
    }
}
namespace tree{
    #define ls (o<<1)
    #define rs (o<<1|1)
    ll sum[maxn<<2],lazy[maxn<<2];
    void push_up(int o){
        sum[o] = sum[ls]+sum[rs];
    }
    void push_down(int o,int l,int r){
        if(lazy[o]&&l!=r){
            int mid = (l+r)>>1;
            lazy[ls] += lazy[o];
            lazy[rs] += lazy[o];
            sum[ls] += lazy[o]*(mid-l+1);
            sum[rs] += lazy[o]*(r-mid);
            lazy[o] = 0;
        }
    }
    void update(int o,int l,int r,int L,int R,ll d){
        push_down(o,l,r);
        if(L<=l&&r<=R){
            sum[o]+=d*(r-l+1);
            lazy[o] += d;
            return;
        }
        int mid = (l+r)>>1;
        if(L<=mid)update(ls,l,mid,L,R,d);
        if(R>mid)update(rs,mid+1,r,L,R,d);
        push_up(o);
    }
    ll query(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[o];
        push_down(o,l,r);
        int mid = (l+r)>>1;
        ll ret = 0;
        if(L<=mid)ret+=query(ls,l,mid,L,R);
        if(R>mid)ret+=query(rs,mid+1,r,L,R);
        return ret;
    }
    #undef ls
    #undef rs
}
ll query(int u){
    ll ret = 0;
    while(top[u]!=1){
        ret += tree::query(1,1,n,id[top[u]],id[u]);
        u = fa[top[u]];
    }
    ret += tree::query(1,1,n,1,id[u]);
    return ret;
}
int main(){
	freopen("tree.in", "r", stdin);
  	freopen("tree.out", "w", stdout);
    
    n = init(),m = init();
    for(int i = 1;i<=n;++i)w[i] = init();
    for(int i = 1;i<n;++i)put(init(),init());
    dfs_1();
    dfs_2();
    for(int i = 1;i<=n;++i)tree::update(1,1,n,id[i],id[i],w[i]);
    int op,x,a;
    while(m--){
        op = init();
        if(op==1)x = init(),a = init(),tree::update(1,1,n,id[x],id[x],a);
        else if(op==2)x = init(),a = init(),tree::update(1,1,n,beg[x],end[x],a);
        else x = init(),printf("%lld\n",query(x));
    }
    return 0;
}
