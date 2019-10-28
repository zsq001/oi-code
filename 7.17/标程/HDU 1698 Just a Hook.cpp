#include<cstdio>
#include<iostream>
#include<algorithm>
#define inf 200000
using namespace std;
int tree[inf<<2],arr[inf],lazy[inf<<2],n,T,q;
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void pushup(int o)
{
    tree[o]=tree[o<<1]+tree[o<<1|1];
}
void pushdown(int o,int l,int r)
{
    if(lazy[o]){
        int mid=(l+r)>>1;
        lazy[o<<1]=lazy[o<<1|1]=lazy[o];
        tree[o<<1]=lazy[o]*(mid-l+1);
        tree[o<<1|1]=lazy[o]*(r-mid);
        lazy[o]=0;
    }
}
void update(int o,int l,int r,int ql,int qr,int v)
{
    if(l>=ql&&r<=qr){
        lazy[o]=v;
        tree[o]=lazy[o]*(r-l+1);
        return;
    }
    pushdown(o,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
    if(qr>mid) update(o<<1|1,mid+1,r,ql,qr,v);
    pushup(o);
}
void build(int o,int l,int r)
{
    if(l==r){
        tree[o]=1;
        return;
    }
    lazy[o]=0;
    int mid=(l+r)>>1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    pushup(o);
}
int main()
{
    int x,y,z;
    T=read();
    for(int i=1;i<=T;++i){
        n=read();
        q=read();
        build(1,1,n);
        while(q--){
            x=read();
            y=read();
            z=read();
            update(1,1,n,x,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n",i,tree[1]);
    }
    return 0;
}
