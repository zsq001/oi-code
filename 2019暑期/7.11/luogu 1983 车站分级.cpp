#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define maxn 1010
#define inf 1<<29
using namespace std;
typedef long long ll;
vector<int>Edge[maxn];
stack<int>S;
int ans,n,m,st,ed,num,rec[maxn],tmp[maxn];
bool vis[maxn][maxn];
inline int read()
{
    char ch=getchar();
    int x(0);
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void dfs(int x){
    if(rec[x]) return;
    rec[x]=1;
    for(int i=0;i<Edge[x].size();++i){
        dfs(Edge[x][i]);
        rec[x]=max(rec[x],rec[Edge[x][i]]+1);
    }
    ans=max(ans,rec[x]);
}
int main()
{
    cin>>n>>m;
    while(m--){
        num=read();
        for(int i=1;i<=num;++i) tmp[i]=read();
        for(int i=1;i<num;++i) 
			for(int j=tmp[i]+1;j<tmp[i+1];++j) 
				for(int k=1;k<=num;++k) 
					if(!vis[j][tmp[k]]) 
						Edge[j].push_back(tmp[k]),vis[j][tmp[k]]=1;
    }
    for(int i=1;i<=n;++i)
		if(!rec[i])
			dfs(i);
    cout<<ans;
    return 0;
}
