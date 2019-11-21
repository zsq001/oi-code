#include <bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;
#define foru(i,a,b) for(ll i=a;i<=b;i++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
ll n,k,cnt(0);

string ans;

void half_search(ll lpc,ll wsm,int sign)
{
	if(cnt==n)return;
	ll t=pow(2,lpc-1);
	if(wsm<t)
	{
		if(!sign){ans[cnt]='0';cnt++;;half_search(lpc-1,wsm,0);}
		else {ans[cnt]='1';cnt++;half_search(lpc-1,wsm,0);}
	}
	else 
	{
		if(!sign){ans[cnt]='1';cnt++;half_search(lpc-1,wsm-t,1);}
		else {ans[cnt]='1';cnt++;half_search(lpc-1,wsm-t,1);}
	}

}

void write()
{
	foru(i,0,n-1)putchar(ans[i]);
	return;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	
	cin>>n>>k;
	half_search(n,k,0);
	write();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
