#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#define inf 1<<29
#define maxn 200010
using namespace std;
typedef long long ll;
int ne[maxn],vis[maxn],rd[maxn],n,ans=inf;
stack<int>S;
void dfs1(int x)
{
    vis[x]=1;
    int v=ne[x];
    rd[v]--;
    if(!rd[v]) dfs1(v);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&ne[i]),rd[ne[i]]++;
    for(int i=1;i<=n;++i) if(!rd[i]) S.push(i);
    while(!S.empty()){
        int x=S.top();
        S.pop();
        dfs1(x);
    }
    for(int i=1;i<=n;++i) if(!vis[i]) {
        int st=i,now=i,cnt=1;
        while(ne[now]!=st){
            vis[now]=1;
            now=ne[now];
            cnt++;
        }
        ans=min(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}
