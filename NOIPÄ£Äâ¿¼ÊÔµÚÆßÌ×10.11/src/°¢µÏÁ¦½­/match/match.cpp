#include <cstdio>
int m, n, x, y, M, sum;
int a[100001];
int b[100001];
int main ()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for( int i= 1; i<= n; i++) scanf("%d", &a[i]);
    for( int i= 1; i<= m; i++) scanf("%d", &b[i]);
    int i = 1, j = 1;
    while( i<= n && j<= m)
    {
        if( (a[i]- x)<= b[j] && (a[i]+ y)>= b[j])
        {
            sum++;
            i++;
            j++;
        }
        else if( (a[i]+ y)< b[j] ) i++;
        else if( (a[i]- x)> b[j] ) j++;
    }
    printf("%d", sum);
    getchar();
    getchar();
    return 0;
}
