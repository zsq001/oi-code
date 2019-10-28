#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef int int_;
#define int long long
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
const int mod=19260817;
struct Mat{
	int A[5][5];
	int x,y;
	void init(bool flag){
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++)
				A[i][j]=0;
		if(flag) for(int i=1;i<=x;i++) A[i][i]=1;
	}
	Mat(int x_,int y_){
		x=x_;y=y_;
		init(0);
	}
	Mat operator *(Mat b){
		Mat a=*this;
		Mat c(a.x,b.y);
		c.init(0);
		for(int i=1;i<=a.x;i++){
			for(int j=1;j<=b.y;j++)
				for(int k=1;k<=a.y;k++){
					c.A[i][j]+=a.A[i][k]*b.A[k][j];
					c.A[i][j]%=mod;
				}
		}
		return c;
	}
	Mat operator ^(int b){
		
		Mat ret(x,x),a=*this;
		ret.init(1);
		while(b){
			if(b&1) ret=ret*a;
			b>>=1;
			a=a*a;
		}
		return ret;
	}
};
int_ main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	int n;
	read(n);
	if(n<=3){
		if(n==3) printf("2\n");
		else printf("0\n");
		return 0;
	}
	else {
		Mat pcr(3,1),f(3,3);
		pcr.init(0);
		f.init(0);
		f.A[1][1]=f.A[1][2]=2;
		f.A[2][2]=f.A[2][3]=f.A[3][3]=1;
		pcr.A[1][1]=2;
		pcr.A[2][1]=2;
		pcr.A[3][1]=1;
		f=f^(n-3);
		pcr=f*pcr;
		printf("%lld",pcr.A[1][1]);
	}
	return 0;
}
