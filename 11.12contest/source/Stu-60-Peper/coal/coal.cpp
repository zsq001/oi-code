#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x*10)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
int n,w;
int a[100007],type[100007];
double k,c;
double f[100007];
int main(){
    freopen("coal.in","r",stdin);
    freopen("coal.out","w",stdout);
	read(n),read(k),read(c),read(w);
	k=(100-k)/100.0,c=(100+c)/100.0;
    for(int i=1;i<=n;++i)
    	read(type[i]),read(a[i]);
    for(int i=n;i>=1;--i){
    	if(type[i]==1) f[i]=max(f[i+1],f[i+1]*k+a[i]);
    	else		   f[i]=max(f[i+1],f[i+1]*c-a[i]);
	}
    printf("%.2lf",f[1]*w);
    return 0;
}
