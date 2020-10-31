#include<bits/stdc++.h>
const int INF=1<<30;
using namespace std;
int t[220],f[220][220],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&t[i]);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) 
            f[i][j]=INF;
    int u,v,w;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        f[u][v]=f[v][u]=w;
    }
    int q,r=0;
    t[n]=INF;
    scanf("%d",&q);
    while(q--)
    {
        int ti;
        scanf("%d%d%d",&u,&v,&ti);
        while(t[r]<=ti)
        {
            int k=r++;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(f[i][k]<INF&&f[k][j]<INF) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        if(t[u]>ti||t[v]>ti||f[u][v]>=INF)printf("-1\n");
        else printf("%d\n",f[u][v]);
    }
    return 0;
}
