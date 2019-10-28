#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 19260817
typedef int int_;
#define int long long
struct MAT{
    int A[10][10];
    int x,y;
    MAT(int x_,int y_){
        x=x_,y=y_;
        for(int i=1;i<=y;++i){
            for(int j=1;j<=x;++j){
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
                    c.A[i][j]=(c.A[i][j]+a.A[i][k]*b.A[k][j])%mod;//k是竖着的那一列 
                }
            }
        }
        return c;
    }
    MAT operator^(int b){
        MAT a=*this;
        MAT ret(3,3);
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
	int n;
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	MAT a1(1,3);
	a1.A[1][1]=0;
	a1.A[1][2]=2;
	a1.A[1][3]=1;
//	for(int i=1;i<=3;i++)
//		printf("%d\n",a1.A[1][i]);
	MAT jz(3,3);
	jz.A[2][1]=jz.A[2][2]=jz.A[3][3]=1;
	jz.A[1][1]=jz.A[3][2]=2;
	MAT ans(1,3);
	jz=jz^(n-2);
	//jz.output();
	ans=a1*jz;
	printf("%lld",ans.A[1][1]);
	return 0;
}
