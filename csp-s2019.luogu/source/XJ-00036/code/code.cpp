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
typedef unsigned long long ull;
ull k,bin[100];
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    int n;
    read(n);read(k);
    bin[0]=1;
    for(int i=1;i<=n;i++)bin[i]=bin[i-1]<<1;
    int t=0;
    for(int i=n-1;i>=0;i--)
    {
        if(!t)
        {
            if(bin[i]&k)putchar('1'),t^=1;
            else putchar('0');
        }
        else 
        {
            if(bin[i]&k)putchar('0');
            else putchar('1'),t^=1;
        }
    }
    return 0;
}
