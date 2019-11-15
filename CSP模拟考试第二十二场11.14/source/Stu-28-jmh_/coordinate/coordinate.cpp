#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 1000000007

int t,ans;

void out(){
	return;
}

struct MAT{
	int n,m;
	int s[5][5];
	MAT(int x,int y){
		n=x,m=y;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				s[i][j]=0;
			}
		}
	}
	
	void init_(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				s[i][j]=0;
			}
			s[i][i]=1;
		}
	}
	
	void clear_(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				s[i][j]=0;
			}
		}
	}
	
	MAT operator * (MAT b){
		MAT a=*this;
		MAT	c(a.n,b.m);
		if(a.m!=b.n) printf("err!\n"),out();
		c.clear_();
		for(int i=1;i<=a.n;i++){
			for(int j=1;j<=b.m;j++){
				for(int k=1;k<=a.m;k++){
					c.s[i][j]+=(1ll*a.s[i][k]*b.s[k][j])%mod;
					c.s[i][j]%=mod;
				}
			}
		}
		return c;
	}
	
	MAT ksm(int q){
		MAT x=*this;
		MAT id(3,3);
		id.init_();
		while(q>0){
			if(q&1){
				id=id*x;
			}
			x=x*x;
			q>>=1;
		}
		return id;
	}
	
	void output(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",s[i][j]);
			}
			printf("\n");
		}
	}
	
};


int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&t);
	MAT A(3,1);
	A.s[1][1]=1;A.s[2][1]=1;A.s[3][1]=1;
	
	
	MAT B(3,3);B.clear_();
	B.s[1][1]=1;B.s[1][2]=1;B.s[1][3]=0;
	B.s[2][1]=1;B.s[2][2]=1;B.s[2][3]=1;
	B.s[3][1]=0;B.s[3][2]=1;B.s[3][3]=1;
	
	B=B.ksm(t-1);
	A=B*A;
	
	ans=(A.s[1][1]+A.s[2][1])%mod+A.s[3][1];
	ans%=mod;
	printf("%d",ans);
	return 0;
}
