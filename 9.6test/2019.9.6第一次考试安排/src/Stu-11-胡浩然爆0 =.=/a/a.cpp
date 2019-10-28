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

long long x;
int qwq[3];
int T,n;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		qwq[0]=qwq[1]=qwq[2]=0;
		for(int i=1;i<=n;++i)
			read(x),++qwq[x%3];
		if(qwq[1]>qwq[2])	printf("%d\n",qwq[0]+qwq[2]+(qwq[1]-qwq[2])/3);
		else		        printf("%d\n",qwq[0]+qwq[1]+(qwq[2]-qwq[1])/3);
	}
	return 0;
}
