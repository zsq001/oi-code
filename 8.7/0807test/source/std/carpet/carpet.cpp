#include <cstdio>
#include <cstdlib>

int a[2005][2005];
int n,m;

void set(int x1,int y1,int x2,int y2)
{
    a[x1][y1]++;
    a[x2+1][y1]--;
    a[x1][y2+1]--;
    a[x2+1][y2+1]++;
}

void inp()
{
    int i,x1,y1,x2,y2;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2),set(x1,y1,x2,y2);
}

void work()
{
    int i,j,p=0,ans=0;
    for(i=1;i<=n;i++,printf("\n"))
        for(j=1;j<=n;j++)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            printf("%d ",a[i][j]);
        }    
}

int main(void)
{
    freopen("carpet.in","r",stdin);
    freopen("carpet.out","w",stdout);

    inp();
    work();

    return 0;
}