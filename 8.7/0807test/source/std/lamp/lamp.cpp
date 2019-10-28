#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n,k,ans;
int w[(1<<20) + 5];
queue <int> q;

void bfs()
{
    int x,tar;

    while(!q.empty())
    {
        x = q.front();q.pop();
        ans = max(ans,w[x]);

        for(int i=0;i<k;i++)
        {
            tar = x ^ (1<<i);

            if(!w[tar])
            {
                w[tar]=w[x]+1;
                q.push(tar);
            }
        }
    }

    printf("%d\n",ans-1);
}

void inp()
{
    int x,i,j;
    char s[30];

    scanf("%d%d",&n,&k);
    
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);

        for(j=x=0;j<k;j++)
            x += (s[j]-'0')*(1<<(k-j-1));

        w[x]=1;
        q.push(x);
    }
}

int main(void)
{
    freopen("lamp.in","r",stdin);
    freopen("lamp.out","w",stdout);

    inp();
    bfs();

    return 0;
}