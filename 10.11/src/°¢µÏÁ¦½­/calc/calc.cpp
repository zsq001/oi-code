#include <cstdio>
#include <cstring>
char A[2001];
int work ( int a, int b, int c, int d)
{
    int ii, jj, S=0, T=0;

    for( ii= a, jj= b; ii<= b, jj>= a; ii++, jj--)
        if( A[ii] != A[jj]) S=1;

    for( ii= c, jj= d; ii<= d, jj>= c; ii++, jj--)
        if( A[ii] != A[jj]) T=1;

    if( !S && !T ) return 1;
        else return 0;
}
int main ()
{
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    int i, j, k, l, sum=0, len;
    scanf("%s", A+1);
    len = strlen(A+1);
    for( i= 1; i<= len - 1; i++)
        for( j= i; j<=len - 1; j++)
            for( k= j+1; k<= len; k++)
                for( l= k; l<= len; l++)
                    sum+=work( i, j, k, l);
    printf("%d", sum);
    getchar();
    getchar();
    return 0;
}
