#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#define l 10010
using namespace std;
stack<int>S;
struct X{
    int next,v;
}e[50010];
int cnt,num,n,m,ans,hl[l],vis1[l],vis2[l],dfn[l],low[l],own[l],jh[l],HL[l];
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void tarjan(int x)
{
    vis1[x]=vis2[x]=1;
    dfn[x]=low[x]=++cnt;
    S.push(x);
    int i=hl[x];
    while(i){
    	int v=e[i].v;
        if(!vis1[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]); 
        }
        else if(vis2[v]) low[x]=min(low[x],low[v]);
        i=e[i].next;
    }
    if(dfn[x]==low[x]){
        num++;
        int now=-1;
        while(now!=x){
            now=S.top();
            S.pop();
            vis2[now]=0;
            jh[now]=num;
            ++own[num];
        }
    }
}
void rebuild()
{
    cnt=0;
    for(int i=1;i<=n;++i){
        int j=hl[i];
        while(j){
            if(jh[i]!=jh[e[j].v]) HL[jh[i]]=++cnt;
            j=e[j].next;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        x=read();y=read();
        e[++cnt].v=y;
        e[cnt].next=hl[x];
        hl[x]=cnt;
    }
    cnt=0;
    for(int i=1;i<=n;++i) if(!vis1[i]) tarjan(i);
    rebuild();
    for(int i=1;i<=num;++i){
        if(!HL[i]){
            if(ans){
                ans=0;break;
            }
            else ans=own[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
