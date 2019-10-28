#include<cstdio>
#include<cstring>
#include<algorithm>
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
	void init(){
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				A[i][j]=0;
			}
		}
	}
	MAT operator*(MAT b){
		MAT a=*this;
		MAT c(a.x,b.y);
		c.init();
		for(int i=1;i<=a.x;++i){
			for(int j=1;j<=b.y;++j){
				for(int k=1;k<=a.y;++k){
					c.A[i][j]+=a.A[i][k]*b.A[k][j];
				}
			}
		}
		return c;
	}
	void output(){
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				printf("%d ",A[i][j]);
			}
			puts("");
		}
	}
}; 
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	MAT a(n,m),b(m,k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a.A[i][j]);
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=k;++j){
			scanf("%d",&b.A[i][j]);
		}
	}
	MAT c=a*b;
	
	c.output();
}
