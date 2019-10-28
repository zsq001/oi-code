#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define m 19260817
struct mat{
	int aa[5][5];
	int x,y;
	mat(int a,int b){
		x=a,y=b;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				aa[i][j]=0;
			}
		}
	}
	void clear_(){
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				aa[i][j]=0;
			}
		}
	}
	void init_(){
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				aa[i][j]=0;
			}
			aa[i][i]=1;
		}
	}
	mat operator * (mat b){
		mat a=*this;
		if(a.y!=b.x) printf("err!\n");
		mat ret(a.x,b.y);
		for(int i=1;i<=a.x;i++){
			for(int j=1;j<=b.y;j++){
				for(int k=1;k<=a.y;k++){
					ret.aa[i][j]+=a.aa[i][k]*b.aa[k][j];
					ret.aa[i][j]=ret.aa[i][j]%m;
				}
			}
		}
		return ret;
	}
	mat ksm(int p){
		mat a=*this;
		if(a.x!=a.y) printf("ERR!\n");
		mat ret(a.x,a.y);
		ret.init_();
		while(p>0){
			if(p&1) ret=ret*a;
			a=a*a;
			p=p>>1;
		}
		return ret;
	}
};



int n;

int_ main()
{
	freopen("prc.in","r",stdin);
	freopen("prc.out","w",stdout);
	scanf("%lld",&n);
	mat dt(3,3);
	dt.aa[1][1]=2,dt.aa[1][2]=1,dt.aa[1][3]=0;
	dt.aa[2][1]=0,dt.aa[2][2]=1,dt.aa[2][3]=1;
	dt.aa[3][1]=0,dt.aa[3][2]=0,dt.aa[3][3]=1;
	mat d(3,1);
	d.aa[1][1]=0,d.aa[2][1]=0,d.aa[3][1]=2;
	mat D(3,3);
	D=dt.ksm(n-1);
	d=D*d;
	printf("%lld",(d.aa[1][1])%m);
	return 0;
}
