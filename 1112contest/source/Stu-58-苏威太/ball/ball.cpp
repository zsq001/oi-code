#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define inf 1e18
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
void print(long long x)
{
	if(x>10)print(x/10);
	putchar(x%10+'0');
}
long long n;
long long ans;
long long mm[60];
char s[60];
int main()
{
	read(n);
	scanf("%s",s+1);
	mm[0]=1;
	for(int i=1;i<=51;++i)
	 mm[i]=mm[i-1]<<1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='B'){
			ans+=mm[i-1];
			if(ans>inf){
				printf("-1");
				return 0;
			}
		}
	}
//  	print(ans); 
	printf("%lld",ans);
}	
