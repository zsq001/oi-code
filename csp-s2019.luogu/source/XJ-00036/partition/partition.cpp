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
const int maxn=5003;
const LL inf=1ll<<62;
LL qr(LL x){return x*x;}
LL sum[maxn],a[maxn];
int n;
namespace sub1
{
    LL f[403][403];
    void work()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)f[i][j]=inf;
        for(int i=1;i<=n;i++)f[i][1]=qr(sum[i]);
        for(int i=2;i<=n;i++)
        {
            for(int k=i-1;k>=1;k--)
            {
                LL s=sum[i]-sum[k],q=qr(s);
                for(int p=k;p>=1;p--)
                {
                    if(sum[k]-sum[p-1]>s)break;
                    f[i][k+1]=std::min(f[i][k+1],f[k][p]+q);
                }
            }
        }
        LL ans=1ll<<62;
        for(int i=1;i<=n;i++)ans=std::min(ans,f[n][i]);
        printf("%lld\n",ans);
    }
}
namespace sub2
{
    LL f[5003][5003];
    void work()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)f[i][j]=inf;
        for(int i=1;i<=n;i++)f[i][1]=qr(sum[i]);
        for(int i=2;i<=n;i++)
        {
            int pos=1;
            for(int k=1;k<i;k++)
            {
                LL s=sum[i]-sum[k],q=qr(s);
                while(pos<=k&&sum[k]-sum[pos-1]>s&&f[k][pos+1]!=inf)pos++;
                while(sum[k]-sum[pos-1]<=s&&f[k][pos]!=inf)f[i][k+1]=std::min(f[i][k+1],f[k][pos]+q),pos++;
                pos--;
            }
        }
        LL ans=1ll<<62;
        for(int i=1;i<=n;i++)ans=std::min(ans,f[n][i]);
        printf("%lld\n",ans);
    }
}
int main()
{
    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);
    int type;
    read(n);read(type);
    for(int i=1;i<=n;i++)
    {
        read(a[i]);sum[i]=sum[i-1]+a[i];
    }
    if(n<=400)sub1::work();
    else if(n<=5000)sub2::work();
    return 0;
}
