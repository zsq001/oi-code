#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#define ll long long 
#define maxn 100010
#define inf 1<<29 
using namespace std;
stack<int>S;
int n,m,c[110],u[110],mp[110][110],rd[110],cd[110],tag[110];
bool fndz()
{
    for(int i=1;i<=n;++i) if((!cd[i])&&(c[i]>0)) return false;
    return true;
}
int main()
{
    int uu,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d%d",&c[i],&u[i]);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) mp[i][j]=inf;
    while(m--){
        scanf("%d%d%d",&uu,&v,&w);
        mp[uu][v]=w;
        rd[v]++;
        cd[uu]++;
    }
    for(int i=1;i<=n;++i) if(!rd[i]) S.push(i),tag[i]=1;
    while(!S.empty()){
        int x=S.top();
        S.pop();
        if(!tag[x]) c[x]-=u[x];
        for(int i=1;i<=n;++i){
            if(mp[x][i]==inf) continue;
            rd[i]--;
            if(!rd[i]) S.push(i);
            if(c[x]<=0) continue;
            c[i]+=mp[x][i]*c[x];
        }
    }
    if(fndz()){
        puts("NULL");
        return 0;
    }
    for(int i=1;i<=n;++i) if((!cd[i])&&(c[i]>0)) printf("%d %d\n",i,c[i]); 
    return 0;
}
