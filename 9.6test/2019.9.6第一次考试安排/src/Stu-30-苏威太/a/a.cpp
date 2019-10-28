#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
bool cmp(int x,int y)
{
	return x>y;
}
int n;
int t;
int a[101];
int b[11];
int ans;
void pan()
{
	int u;
	if(b[1]!=0&&b[2]!=0){
			u=min(b[1],b[2]);
			ans+=u; 
			b[1]-=u;
			b[2]-=u; 
		}
	if(b[1]!=0&&b[5]!=0){
			u=min(b[1],b[5]);
			ans+=u;
			b[1]-=u;
			b[5]-=u; 
		}
	if(b[1]!=0&&b[8]!=0){
			u=min(b[1],b[8]);
			ans+=u;
			b[1]-=u;
			b[8]-=u; 
		}
	if(b[2]!=0&&b[4]!=0){
			u=min(b[2],b[4]);
			ans+=u;
			b[2]-=u;
			b[4]-=u; 
		}
	if(b[2]!=0&&b[7]!=0){
			u=min(b[2],b[7]);
			ans+=u;
			b[2]-=u;
			b[7]-=u; 
		}
	if(b[4]!=0&&b[5]!=0){
			u=min(b[4],b[5]);
			ans+=u;
			b[4]-=u;
			b[5]-=u; 
		}
	if(b[4]!=0&&b[8]!=0){
			u=min(b[4],b[8]);
			ans+=u;
			b[4]-=u;
			b[8]-=u; 
		}
}
void p1()
{
	if(b[1]==2&&b[4]!=0){
		++ans;
		b[1]-=2;
		--b[4];
	}
	if(b[1]==2&&b[7]!=0){
		++ans;
		b[1]-=2;
		--b[7];
	}
	if(b[2]==2&&b[8]!=0){
		++ans;
		b[2]-=2;
		--b[8];
	}
	if(b[2]==2&&b[5]!=0){
		++ans;
		b[2]-=2;
		--b[5];
	}
	if(b[4]==2&&b[1]!=0){
		++ans;
		b[4]-=2;
		--b[1];
	}
	if(b[4]==2&&b[7]!=0){
		++ans;
		b[4]-=2;
		--b[7];
	}
	if(b[5]==2&&b[2]!=0){
		++ans;
		b[5]-=2;
		--b[2];
	}
	if(b[5]==2&&b[8]!=0){
		++ans;
		b[5]-=2;
		--b[8];
	}
	if(b[7]==2&&b[1]!=0){
		++ans;
		b[7]-=2;
		--b[1];
	}
	if(b[7]==2&&b[4]!=0){
		++ans;
		b[7]-=2;
		--b[4];
	}
	if(b[8]==2&&b[2]!=0){
		++ans;
		b[8]-=2;
		--b[2];
	}
	if(b[8]==2&&b[5]!=0){
		++ans;
		b[8]-=2;
		--b[5];
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(t);
	while(t!=0)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		--t;
		read(n);
		int nn=n;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			read(a[i]);
			a[i]%=10;
			if(a[i]%3==0){
				++ans;
				a[i]=0;
				--nn;
			}
		}
		sort(a+1,a+nn+1,cmp);
		for(int i=1;i<=nn;++i)
		{
			++b[a[i]];
		}
		pan();
		for(int i=1;i<=9;++i)
		{
			while(b[i]>=3)
			{
				++ans;
				b[i]-=3;
			}
		}
		p1();
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
