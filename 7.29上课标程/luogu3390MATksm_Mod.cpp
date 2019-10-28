#include<cstdio>
#include<cstring>
#include<algorithm>
typedef int int_; 
#define int long long
const int Mod=1e9+7;
struct MAT{
	int A[110][110];
	int x,y;
	MAT(int x_,int y_){
		x=x_,y=y_;
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				A[i][j]=0;
			}
		}
	}
	void init(bool flg){
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				A[i][j]=0;
			}
		}
		if(flg){
			for(int i=1;i<=x;++i) A[i][i]=1;
		}
	}
	MAT operator*(MAT b){
		MAT a=*this;
		MAT c(a.x,b.y);
		c.init(0);
		for(int i=1;i<=a.x;++i){
			for(int j=1;j<=b.y;++j){
				for(int k=1;k<=a.y;++k){
					c.A[i][j]+=a.A[i][k]*b.A[k][j];
					c.A[i][j]%=Mod;
				}
			}
		}
		return c;
	}
	MAT operator^(int b){
		MAT a=*this;
		MAT ret(x,x);
		ret.init(1);
		while(b){
			if(b&1) ret=ret*a;
			b>>=1;
			a=a*a;
		}
		return ret;
	}
	void output(){
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				printf("%lld ",A[i][j]);
			}
			puts("");
		}
	}
}; 
int_ main(){
	int n,m,k;
	scanf("%lld%lld",&n,&k);
//	printf("n=%lld\n",n);
	MAT a(n,n);
	a.init(0);
//	puts("qwqwq");
//	printf("n=%lld\n",n);
	for(int i=1;i<=n;++i){
	//	puts("QAQ");
		for(int j=1;j<=n;++j){
			scanf("%lld",&a.A[i][j]);
		}
	}
	MAT c=a^k;
	c.output();
}
