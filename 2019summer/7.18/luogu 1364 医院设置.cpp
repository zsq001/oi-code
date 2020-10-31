#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define inf 1<<28
using namespace std;
int w[110],mp[110][110],ans=inf,n,l,r;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) mp[i][j]=inf;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&w[i],&l,&r);
        mp[i][l]=0,mp[i][r]=0;
    }
    for(int i=1;i<=n;++i) mp[i][i]=0;
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) if(!mp[i][j]) mp[i][j]=mp[j][i]=1;
    for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    for(int i=1;i<=n;++i){
        int tmp=0;
        for(int j=1;j<=n;++j) tmp+=mp[i][j]*w[j];
        ans=min(ans,tmp);
    }
    printf("%d",ans);
    return 0;
}
