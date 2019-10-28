#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll v,ans1=214748365,ans2=214748365;
void solve()
{
	ll k,tmp;
	for(ll i=1;i<=v;i++)
		for(ll j=1;i*j<=v&&i*j>0;j++)
		{
			tmp=i*j;
			if(v%tmp)continue;
			k=v/tmp;
			if(2*i*j+2*i*k+2*j*k<ans1)ans1=2*i*j+2*i*k+2*j*k;
		}
}
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%I64d",&v);
	//freopen("data2.txt","w",stdout);
	//for(ll v=1;v<=10000;v++){
		//ans1=ans2=0;
	if(v<=1000)solve();
	ans2=2*v+2*v+2;
	if(v<=1000)printf("%I64d\n",max(ans1,ans2));
	else printf("%I64d\n",ans2);
	//if(v<=1000)printf("%I64d %I64d\n",v,max(ans1,ans2));
	//else printf("%I64d %I64d\n",v,ans2);}
	//fclose(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
