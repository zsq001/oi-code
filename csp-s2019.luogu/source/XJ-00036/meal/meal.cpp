#include<cstdio>
#include<cstring>
#include<algorithm>
template<class T>void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    x=f?-x:x;
    return;
}
typedef long long LL;
const int maxn=103,maxm=2003,mod=998244353;
int n,m;
int a[maxn][maxm];
namespace sub1
{
    LL f2[41][41][41],f3[41][41][41][41];
    void solve2()
    {
        for(int i=0;i<=n;i++)f2[i][0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                f2[i][j][0]=(f2[i-1][j][0]+f2[i-1][j-1][0]*a[i][2])%mod;
                for(int k=1;k<=j;k++)
                    f2[i][j][k]=(f2[i-1][j][k]+f2[i-1][j-1][k-1]*a[i][1]+f2[i-1][j-1][k]*a[i][2])%mod;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j>i/2||(i-j)>i/2)continue;
                (ans+=f2[n][i][j])%=mod;
            }
        }
        printf("%d\n",ans);
    }
    void solve3()
    {
        for(int i=0;i<=n;i++)f3[i][0][0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                f3[i][j][0][0]=(f3[i-1][j][0][0]+f3[i-1][j-1][0][0]*a[i][3])%mod;
                for(int k=1;k<=j;k++)f3[i][j][k][0]=(f3[i-1][j][k][0]+f3[i-1][j-1][k-1][0]*a[i][1]+f3[i-1][j-1][k][0]*a[i][3])%mod;
                for(int k=1;k<=j;k++)f3[i][j][0][k]=(f3[i-1][j][0][k]+f3[i-1][j-1][0][k-1]*a[i][2]+f3[i-1][j-1][0][k]*a[i][3])%mod;
                for(int k=1;k<=j;k++)
                {
                    for(int p=1;p+k<=j;p++)
                        f3[i][j][k][p]=(f3[i-1][j][k][p]+f3[i-1][j-1][k-1][p]*a[i][1]+f3[i-1][j-1][k][p-1]*a[i][2]+f3[i-1][j-1][k][p]*a[i][3])%mod;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=i;j++)
                for(int k=0;k+j<=i;k++)
                    if(j>i/2||k>i/2||(i-j-k)>i/2)continue;
                    else (ans+=f3[n][i][j][k])%=mod;
        printf("%d\n",ans);
    }
    void work()
    {
        if(m==2)solve2();
        else solve3();
    }
}
int main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            read(a[i][j]);
    if(n<=40&&m<=3)sub1::work();
    return 0;
}
