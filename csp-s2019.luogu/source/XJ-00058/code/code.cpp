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
int n;
long long k;
long long p=1;
long long o[65];
void pppp(int q,long long e)
{
	if(q==1&&e==0){
		printf("0");
		return;
	}
	else if(q==1&&e==1){
		printf("1");
		return;
	}
	if(e<=o[q]){
		printf("0");
		pppp(q-1,e);
	}
	else {
		printf("1");
		pppp(q-1,o[q]-(e-o[q])+1);
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read(n);
	read(k);
	o[1]=0;
	for(int i=1;i<=n-1;++i)
	{
		p*=2;
		o[i+1]=p-1;
	}
	pppp(n,k);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
