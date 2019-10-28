#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int T,n,a[105],cnt[5],ans;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			if(a[i]) cnt[a[i]%3]++;
		}
		ans=cnt[0];
		if(cnt[1]>=cnt[2]) ans+=cnt[2]+(int)((cnt[1]-cnt[2])/3);
		else ans+=cnt[1]+(int)((cnt[2]-cnt[1])/3);
		printf("%d\n",ans);
	}
	return 0;
}
