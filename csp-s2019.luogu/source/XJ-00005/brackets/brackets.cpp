#include<stdio.h>
char a[600100];
int fa[600100],anss,ans,tot,c[600100];
int  check(int l,int r)
{
    int num=0;
    for(int i=r;i>=l;i--)
    {
            if(c[i]=='(')num++;
            else         num--;
            if(num<0)return -1;
    }
    if(num>0)return 0;
    return 1;
}
void find(int now)
{
    for(int i=now-1;i>=1;i--)
    {
         int pd=check(i,now);
         if(pd==1)ans++;
         if(pd==-1)return;
    }
}
int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int n;
    char z;
    scanf("%d%c",&n,&z);
    for(int i=1;i<=n;i++)
            scanf("%c",&a[i]);
    for(int i=2;i<=n;i++)
    {
            scanf("%d",&fa[i]);
    }
    fa[1]=0;
    anss=0;
    for(int i=2;i<=n;i++)
    {
        int k=i,que=0,rec=1,acc=0;
        tot=0,ans=0;
        while(k){c[++tot]=a[k];k=fa[k];}
        for(int j=tot;j>=1;j--)
          find(j);
        anss=anss xor (i*ans);
    }
    printf("%d",anss);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
