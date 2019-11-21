#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
int ans,n,x;

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	read(n),read(x);
	for(int i=1;i<=n;++i)
	 read(x),ans+=x*x;
	 printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
