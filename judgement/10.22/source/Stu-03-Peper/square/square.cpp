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

int J,O,n,ans;
int j[200007],o[200007],a[200007];

int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	read(n);
	read(a[1]);
	j[1]=a[1];
	for(int i=2;i<=n;++i){
		read(a[i]);
		if(i&1) j[i]=j[i-2]+a[i],J=j[i];
		else 	o[i]=o[i-2]+a[i],O=o[i];
	}
	for(int i=1;i<=n;++i)
		if((i&1&&j[i]-a[i]+O-o[i-1]==o[i-1]+J-j[i])||(!(i&1)&&o[i]-a[i]+J-j[i-1]==j[i-1]+O-o[i]))     
			ans++;
	printf("%d",ans);
	return 0;
}
