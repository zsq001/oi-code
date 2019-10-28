#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
const int mod = 1e9+7;
typedef long long LL;
using namespace std;
const int M = 400005;

struct Matrix
{
    int n;
    int m;
    long long a[3][3];
    Matrix () {};
    Matrix (int x,int y)
    {
        n=x;
        m=y;
        memset(a,0,sizeof(a));
    }
};
Matrix operator+(const Matrix &a,const Matrix &b)
{
    Matrix res (a.n,a.m);
    for(int i=0;i<a.n;++i)
        for(int j=0;j<b.m;++j)
            (res.a[i][j] += a.a[i][j] + b.a[i][j])%=mod;
    return res;
}

Matrix operator*(const Matrix &a,const Matrix &b)
{
    Matrix res (a.n,b.m);
    for(int i=0;i<a.n;++i)
        for(int j=0;j<b.m;++j)
            for(int k=0;k<a.m;++k)
                (res.a[i][j] += a.a[i][k] * b.a[k][j])%=mod;
    return res;
}

Matrix pow(Matrix a,LL b)
{
    Matrix res (a.n,a.m);
    for(int i=0;i<a.n;++i)
        for(int j=0;j<a.m;++j)
            res.a[i][j] = (i == j);
    for(;b;b>>=1,a=a*a)
        if(b&1)
            res = res * a;
    return res;
}

struct seg
{
    Matrix lazy,sum;
    bool flag;
}tr[M];

void init(Matrix &b)
{
    b.n = b.m =2;
    for(int i=0;i<b.n;++i)
        for(int j=0;j<b.m;++j)
            b.a[i][j] = (i == j);
}

Matrix fib_init_Fir(int x)
{
    Matrix res(2,2);
    res.a[0][0] = res.a[1][0] = res.a[0][1] = 1;
    return pow(res,x-1);
}

Matrix fib_init_Sec(int x)
{
    Matrix res(2,2);
    res.a[0][0] = res.a[1][0] = res.a[0][1] = 1;
    return pow(res,x);
}

void updata(int k)
{
    tr[k].sum = tr[k<<1].sum + tr[k<<1|1].sum;
}

void down(int k)
{
    if(tr[k].flag)
    {
        tr[k<<1].lazy = tr[k].lazy * tr[k<<1].lazy;
        tr[k<<1|1].lazy = tr[k].lazy * tr[k<<1|1].lazy;
        tr[k<<1].sum = tr[k<<1].sum * tr[k].lazy;
        tr[k<<1|1].sum = tr[k<<1|1].sum * tr[k].lazy;
        tr[k<<1].flag = tr[k<<1|1].flag = 1;
        tr[k].flag = 0; init(tr[k].lazy);
    }
}

inline int read()
{
    int x;
    scanf("%d", &x);
    return x;
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        int x = read();
        tr[k].sum = fib_init_Fir(x);
        init(tr[k].lazy); tr[k].flag = 0 ;
        return ;
    }
    tr[k].sum = Matrix(2,2); init(tr[k].lazy);tr[k].flag = 0;
    int mid = (l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    updata(k);
}

void change(int k,int l,int r,int x,int y,Matrix tmp)
{
    if(x <= l  && r <= y)
    {
        tr[k].lazy = tr[k].lazy * tmp;
        tr[k].flag = 1;
        tr[k].sum = tr[k].sum * tmp;
        return ;
    }   
    down(k);
    int mid = (l+r)>>1;
    if(x <= mid)change(k<<1,l,mid,x,y,tmp);
    if(y > mid) change(k<<1|1,mid+1,r,x,y,tmp);
    updata(k);
}

LL ask(int k,int l,int r,int x,int y)
{
    if(x <= l && r <= y) return tr[k].sum.a[0][0];
    int mid = (l+r)>>1;
    down(k);
    LL ans = 0;
    if(x <= mid) ans += ask(k<<1,l,mid,x,y);
    if(y > mid) ans += ask(k<<1|1,mid+1,r,x,y);
    updata(k) ;
    return ans % mod;
}
/*
void out(Matrix &a)
{
    for(int i=0;i<a.n;++i)
    {
        for(int j=0;j<a.m;++j)
            printf("%d ",a.a[i][j]);
        puts("");
    }
}
*/
int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    int n = read(), m = read();
    build(1,1,n);
//  out(tr[1].lazy);
    while(m--)
    {
        int op = read(), l = read() , r = read();
        if(op == 1)
        {
            int x = read();
            change(1,1,n,l,r,fib_init_Fir(x+1));
        }
        else printf("%lld\n",ask(1,1,n,l,r));
    }
}
