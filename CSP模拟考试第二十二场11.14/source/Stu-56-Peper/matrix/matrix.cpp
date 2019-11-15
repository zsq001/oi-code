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

struct qwq{
	int num,dfn;
}a[100007],b[100007];

int n,m,q,x,y,z;

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=q;++i){
		read(x),read(y),read(z);
		if(x==1) a[y].num=z,a[y].dfn=i;
		else	 b[y].num=z,b[y].dfn=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",a[i].dfn>b[j].dfn?a[i].num:b[j].num);
		}
		printf("\n");
	}
	return 0;
}
