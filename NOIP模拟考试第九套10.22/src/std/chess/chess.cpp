#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;

int n,m,k;
const int N=64;
char arr[N][N];
bool flag = false;
bool visit[N][N];
int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};
void dfs(int i,int j,int pi,int pj)
{
    if(visit[i][j])
    {
        flag = true;
        return;
    }
    visit[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int nextx = i+dirx[k];
        int nexty = j+diry[k];
        if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&arr[i][j]==arr[nextx][nexty])
        {
            if(!(nextx==pi&&nexty==pj))
                dfs(nextx,nexty,i,j);
        }
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    while(scanf("%d%d", &n, &m)==2)
    {
        flag = false;
        for(int i=0;i<n;i++)
            scanf("%s", arr[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                memset(visit,0,sizeof(visit));
                dfs(i,j,-1,-1);
                if(flag) goto FINISH;
            }
        FINISH:
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
