#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

struct event
{
    int x,y,d;
};
int x[10000]={0},y[10000]={0};
int n;

bool s[5000][5000]={0};
bool r[5000][5000]={0};

void inp()
{
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(s,0,sizeof(s));
    memset(r,0,sizeof(r));

    int i;
    scanf("%d",&n);
    for(i=1;i<=2*n-2;i++)
        scanf("%d%d",&x[i],&y[i]);
}

void bfs()
{
    event now,tmp;
    queue <event> q;
    int dep=1;
    tmp.x=1,tmp.y=1,tmp.d=1;
    q.push(tmp);

    while(!q.empty())
    {
        while(!q.empty() && q.front().d==dep)
        {
            now=q.front(),q.pop();
            if(now.x==n && now.y==n) goto ok;

            if(r[now.x][now.y]==1) continue;
            r[now.x][now.y]=1;
            //printf("now:x=%d y=%d d=%d\n",now.x,now.y,now.d);

            if(s[now.x+1][now.y]==0 && r[now.x+1][now.y]==0 && now.d<=2*n-2)
                tmp.x=now.x+1,tmp.y=now.y,tmp.d=now.d+1,q.push(tmp);
            if(s[now.x][now.y+1]==0 && r[now.x][now.y+1]==0 && now.d<=2*n-2)
                tmp.x=now.x,tmp.y=now.y+1,tmp.d=now.d+1,q.push(tmp);
        }
        s[x[dep]][y[dep]]=1;
        dep++;
    }
    printf("No\n");
    return;

    ok:
    printf("Yes\n");
}

int main(void)
{
    freopen("bar.in","r",stdin);
    freopen("bar.out","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        inp();
        bfs();
    }
    return 0;
}