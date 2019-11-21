#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100005;
const unsigned long long seed=998244353;
int n,cnt[2],ans[maxn];
unsigned long long ha[2][maxn];
vector<int>g[2],son[2][maxn];
int info[2][maxn],nx[2][maxn<<1],v[2][maxn<<1];
void add(int u1,int v1,int k){nx[k][++cnt[k]]=info[k][u1];info[k][u1]=cnt[k];v[k][cnt[k]]=v1;}
bool cmp0(int a,int b){return ha[0][a]<ha[0][b];}bool cmp1(int a,int b){return ha[1][a]<ha[1][b];}
int yousa(int x,int f,int k)
{
	int S,T;
	scanf("%a",&T);
	scanf("%a",&S);
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
    int sz=1,flag=1;
    for(int i=info[k][x],del;i;i=nx[k][i])if(v[k][i]!=f)
    sz+=(del=yousa(v[k][i],x,k)),flag&=((del<<1)<=n);
    flag&=(((n-sz)<<1)<=n);if(flag)g[k].push_back(x);
    return sz;
}
void VR(int x,int f,int k)
{
    son[k][x].clear();
    for(int i=info[k][x];i;i=nx[k][i])
    {
        if(v[k][i]!=f)
        VR(v[k][i],x,k),son[k][x].push_back(v[k][i]);
    }
    if(k==0)sort(son[k][x].begin(),son[k][x].end(),cmp0);
    if(k==1)sort(son[k][x].begin(),son[k][x].end(),cmp1);
    ha[k][x]=1;
    for(int i=son[k][x].size()-1;i>=0;i--)ha[k][x]=ha[k][x]*seed^ha[k][son[k][x][i]];
    ha[k][x]*=seed*seed;
}
void solve(int a,int b){ans[a]=b;for(int i=son[0][a].size()-1;i>=0;i--)solve(son[0][a][i],son[1][b][i]);}
int main()
{
    scanf("%d",&n);
    for(int k=0;k<=1;k++)for(int i=1,u1,v1;i<n;i++)
    scanf("%d%d",&u1,&v1),add(u1,v1,k),add(v1,u1,k);
    yousa(1,0,0);yousa(1,0,1);
    for(int i=0,lim=g[0].size();i<lim;i++)
    {
        VR(g[0][i],0,0);
        for(int j=0,lim=g[1].size();j<lim;j++)
        {
            VR(g[1][j],0,1);
            if(ha[0][g[0][i]]==ha[1][g[1][j]])
            {
                puts("YES");solve(g[0][i],g[1][j]);
                for(int k=1;k<=n;k++)printf("%d%c",ans[k],k==n?'\n':' ');
                return 0;
            }
        }
    }
    puts("NO");
}
