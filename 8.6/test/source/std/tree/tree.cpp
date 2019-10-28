#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3010
using namespace std;
int head[N] , to[N << 1] , len[N << 1] , nxt[N << 1] , cnt , si[N] , f[N][N][3];
inline void add(int x , int y , int z)
{
    to[++cnt] = y , len[cnt] = z , nxt[cnt] = head[x] , head[x] = cnt;
}
void dfs(int x , int fa)
{
    int i , j , k , l , m;
    si[x] = 1 , f[x][0][0] = f[x][0][1] = 0;
    for(i = head[x] ; i ; i = nxt[i])
    {
        if(to[i] != fa)
        {
            dfs(to[i] , x);
            for(j = si[x] - 1 ; ~j ; j -- )
                for(k = si[to[i]] - 1 ; ~k ; k -- )
                    for(l = 2 ; ~l ; l -- )
                        for(m = l ; ~m ; m -- )
                            f[x][j + k + 1][l] = min(f[x][j + k + 1][l] , f[x][j][l - m] + f[to[i]][k][m] + len[i] * (2 - (m & 1)));
            si[x] += si[to[i]];
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n , k , i , j , x , y , z , ans = 1 << 30;
    scanf("%d%d" , &n , &k);
    for(i = 1 ; i < n ; i ++ )
        scanf("%d%d%d" , &x , &y , &z) , add(x , y , z) , add(y , x , z);
    memset(f , 0x3f , sizeof(f));
    dfs(1 , 0);
    for(i = 1 ; i <= n ; i ++ )
        for(j = 0 ; j <= 2 ; j ++ )
            ans = min(ans , f[i][k - 1][j]);
    printf("%d\n" , ans);
    return 0;
}