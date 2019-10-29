#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
struct x
{
    int a;
    int t;
};
int cmp(x p,x q)
{
    return p.a>q.a;
}
int main()
{
    freopen("physics.in", "r", stdin);
    freopen("physics.out", "w", stdout);
    int n;
    x a[10005];
    x b[10005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].a,&a[i].t);
        b[i].a = a[i].a;
        b[i].t = a[i].t;
    }
    sort(a,a+n,cmp);
 
    double ans = 0;
    double x1 = 0;
    double x2 = 0;
    double v1 = 0;
    double v2 = 0;
    for(int i=0;i<n;i++)
    {
        x1 = v1*a[i].t+(1.0/2)*(a[i].a)*(a[i].t)*(a[i].t);
        v1 = v1+a[i].a * a[i].t;
        x2 = v2*b[i].t+(1.0/2)*(b[i].a)*(b[i].t)*(b[i].t);
        v2 = v2+b[i].a * b[i].t;
        ans+= x1-x2;
    }
    printf("%.1f",ans);
}