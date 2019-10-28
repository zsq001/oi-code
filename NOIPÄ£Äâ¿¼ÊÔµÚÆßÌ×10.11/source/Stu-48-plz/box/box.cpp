#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;

int v;

int main()
{
   // freopen("box.in","r",stdin);
   // freopen("box.out","w",stdout);
	ll ans=1e15,hmj;
    scanf("%d",&v);
    for(int a=v;a>=1;--a)//b==c>> b*c zuixiao
    {
        if((v/a)*a!=v)continue;
        int kk=sqrt(v/a);
        hmj=(ll )(v/a+a*2*kk);
        if(hmj<=ans||a==v)
		{
            for(int b=a;b<=a+kk;++b)
			{
                int c=v/a/b;
                if(c*a*b!=v) continue;
                ans=min(ans,(ll int)a*b+(ll int)b*c+(ll int)a*c);
            }
        }
    }
    printf("%lld",2*ans);
    return 0;
}
