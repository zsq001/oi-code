#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a[5000001];
ll b[5000001];
inline ll pow(ll a,ll b)
{
	ll ret = 1;
	while(b)
	{
		if(b&1)ret = ret * a;
		a = a * a;
		b /= 2;
    }
    return ret;
}
inline void put(int x,int n)
{
	int cnt = n;
	int bin[32];
    for(int i = 1;i <= n;i ++)
    {
    	bin[cnt--] = x%2;
    	x /= 2;
    }
    for(int i = 1;i <= n;i ++)
    {
    	printf("%d",bin[i]);
    }
}
inline void create(ll n)
{
	if(n >= 4)create(n - 1);
	ll flag = pow(2,n-1);
	ll cnt = flag;
	for(register ll i = 1;i <= flag; i++)
	{
		b[cnt--] = a[i];
	}
    for(register ll i = 1;i <= flag;i ++)
    {
    	b[i] += pow(2,n-1);
    }
    for(register ll i = 1;i <=  flag ;i ++)
    {
    	a[i + flag] = b[i];
    }
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code,out","w",stdout);
	ll n;ll k;
	scanf("%I64d %I64d",&n,&k);
	a[1] = 0,a[2] = 1,a[3] = 3,a[4] = 2,a[5] = 6,a[6] = 7,a[7] = 5,a[8] = 4;
	create(n); 
    put(a[k+1],n);
    puts("\n");
    fclose(stdin);
    fclose(stdout);
}
