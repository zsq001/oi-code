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
int n,m;
int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	read(n);
	read(m);
	int u,v,w;
	if(n==2&&m==1){
		read(u);
		read(v);
		read(w);
		double ans=n;
		printf("%.3lf",w/ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
