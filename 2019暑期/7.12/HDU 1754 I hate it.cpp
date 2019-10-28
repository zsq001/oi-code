#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define len 800010 
using namespace std;
int tree[len],arr[len],cnt,n,m,a,b; 
char tmp;
int Max(int x,int y){
    return x>y?x:y;
}
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
    tree[o]=Max(tree[o<<1],tree[o<<1|1]); 
}
void build(int o,int l,int r)
{
    if(l==r){
        tree[o]=arr[l]; 
        return; 
    }
    int mid=(l+r)>>1; 
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r); 
    pushup(o);
}
void update(int o,int l,int r,int x,int v)
{
    if(l==r){
        tree[o]=v;
        return; 
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(o<<1,l,mid,x,v);
    else update(o<<1|1,mid+1,r,x,v); 
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr) return tree[o];
    int mid=(l+r)>>1;
    int ret1=0,ret2=0;
    if(ql<=mid) ret1=query(o<<1,l,mid,ql,qr);
    if(qr>mid) ret2=query(o<<1|1,mid+1,r,ql,qr);
    return Max(ret1,ret2); 
}
int main()
{
    while((scanf("%d%d",&n,&m))!=EOF){
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;++i) arr[i]=read(); 
        build(1,1,n); 
        for(int i=1;i<=m;++i){
            scanf(" %c",&tmp);
            a=read();b=read();  
            if(tmp=='Q') printf("%d\n",query(1,1,n,a,b));
            else update(1,1,n,a,b); 
        }
    }
    return 0; 
}
