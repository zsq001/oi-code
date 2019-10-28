#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
const int e=1e3+5;
int s[e][e],n,m,ans,ru[e],vis[e],tot,pd[e][e];
queue<pii>q;
vector<int>g[e];
inline int getint()//读入优化
{
    char ch;
    int res=0;
    while(ch=getchar(),ch<'0'||ch>'9');
    res=ch-48;
    while(ch=getchar(),ch>='0'&&ch<='9')
    res=(res<<3)+(res<<1)+ch-48;
    return res;
}
inline void bfs()//拓扑排序 
{
    int i;
    for(i=1;i<=n;i++)
    if(ru[i]==0)
    q.push(make_pair(i,1));//没有入度，级别最低 
    ans=1;
    while(!q.empty())
    {
        int u=q.front().first,val=q.front().second;
        //队列中的每个元素有2个关键字，第一个是车站编号，第二个是级别
        q.pop();
        for(i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            ru[v]--;
            if(ru[v]==0)
            {
                q.push(make_pair(v,val+1));//递推，当前点的级别为val+1 
                ans=max(ans,val+1);//ans记录最高级别，也就是不同级别的数量 
            }
        }
    }
}
int main()
{
    int i,j,x;
    n=getint();
    m=getint();
    for(i=1;i<=m;i++)
    {
        s[i][0]=getint();//s[i][0]为车次i停靠的车站数量 
        memset(vis,false,sizeof(vis));
        for(j=1;j<=s[i][0];j++)
        {
            x=getint();
            s[i][j]=x;//s[i][j]表示车次i停靠的第j个车站 
            vis[x]=true;//当前车次有停靠x 
        }
        for(j=s[i][1];j<=s[i][s[i][0]];j++)//枚举经过的所有车站（不一定停靠） 
        {
            if(vis[j])continue;//这条路上所有不停靠的必须比所有停靠的级别低 
            for(int k=1;k<=s[i][0];k++)
            if(!pd[j][s[i][k]])//pd判断这条边是否还没连 
            {
                ru[s[i][k]]++;//入度+1 
                g[j].push_back(s[i][k]);
                //j向s[i][k]连边，表示j的级别必须比s[i][k]低 
                pd[j][s[i][k]]=true;//标记为连过的边 
            }
        }
    }
    bfs();
    cout<<ans<<endl;
    return 0;
}
