#include<iostream>
#include<queue>
using namespace std;
int zl[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1005][1005];
int xx[1005][1005];
const int INF=43241242;
struct xy
{
    int X;
    int Y;
};
int main()
{
    int X1,Y1;
    xy s;
    queue<xy> que;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            xx[i][j]=INF;
    s.X=1;
    s.Y=1;
    que.push(s);
    while(xx[n][m]==INF)
    {
        X1=que.front().X;
        Y1=que.front().Y;
        que.pop();
        for(int i=0;i<4;i++)
        {
            if(a[X1+zl[i][0]][Y1+zl[i][1]]=='.'&&xx[X1+zl[i][0]][Y1+zl[i][1]]==INF)
            {
                xx[X1+zl[i][0]][Y1+zl[i][1]]=xx[X1][Y1]+1;
                s.X=X1+zl[i][0];
                s.Y=Y1+zl[i][1];
                que.push(s);
            }
        }
    }
    cout<<xx[n][m]-INF+1;
}

