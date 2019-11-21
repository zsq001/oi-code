#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mod 998244353
#define foru(i,a,b) for (ll i=a;i<=b;i++)
#define ford(i,a,b) for (ll i=a;i>=b;i--)

ll n,m,a[5][5]={0},temp=1,cnt[5]={0},tot=1,choose=1,ok[5][5],sup=1;
ll k,row,ans;

inline ll read()
{
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=getchar();
	return x;
}

void search(ll line)
{
		for(row=1;row<=m;row++)//一行落一子  标记 计数 
		{
			cnt[row]++;
			choose++;
			if(cnt[row]<=(k/2))
			{
				temp*=a[line][row];
				sup*=ok[line][row];
				ok[line][row]==1;
				break;
			}
			else 
			{
				cnt[row]--;
				choose--;
			}
		}
		for(;;)
		{
			if (!choose)return;
			if (line+tot<=n&&choose<k)search(line+tot);
			if (choose==k&&sup)
			{
				temp=temp/a[line][row];
				cnt[row]--;
				choose--;
				return;
			}
			if (choose==k)
			{
				ans+=temp;
				ans%=mod;
				temp=temp/a[line][row];
				cnt[row]--;
				choose--;
				return;
			}
			if(line+tot>n)
			{
				tot=1;
				return;
			}
			tot++;
		}
}

void solve()
{
	
	foru(h,1,k*m)tot=1,memset(cnt,0,sizeof(cnt)),choose=0,temp=1,sup=1,search(1);
	return;
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout)
	n=read();
	m=read();
	memset(ok,0,sizeof(ok));
	foru(i,1,n)foru(j,1,m)a[i][j]=read();
	for(k=2;k<=n;k++)solve();
	cout<<ans%mod/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
