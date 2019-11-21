#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

long long n,qwq;
long long k;

int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read(n),read(k);
	qwq=1ll<<n;
	while(n--){
		qwq>>=1;
		if(k>=qwq){
			printf("1");
			k-=qwq;
			k=qwq-k-1;
		}
		else{
			printf("0");
	
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
