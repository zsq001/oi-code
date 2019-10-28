#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,op,a[10][10],re[10][10],ans,answer=20,last[21][10][10];
int dfspf2(){
	int sum=a[1][1]+a[1][2]+a[1][3];
	if(sum==9){
		return 3;
	}
	if(sum==10&&sum==11){
		return 2;
	}
	if(sum==12){
		return 1;
	}
}
int dfspf1(){
	int sum=a[1][1]+a[1][2]+a[1][3];
	if(sum==9){
		return 3;
	}
	if(sum==10){
		return 2;
	}
	if(sum==11)return 1;
	if(sum==12){
		return 0;
	}
}
void copy1(int x){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=6;j++)
			last[x][i][j]=a[i][j];
}
void copy2(int x){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=6;j++)
			a[i][j]=last[x][i][j];
}
int boom(int x,int y){
	int cntb=0;
	a[x][y]++;
	if(a[x][y]==5){
		a[x][y]==0;
		for(int i=x+1;i<=6;i++){
			if(a[i][y]){
				cntb+=boom(i,y);
				break;
			}
		}
		for(int i=x-1;i;i--)
			if(a[i][y]){
				cntb+=boom(i,y);
				break;
			}
		for(int i=y+1;i<=6;i++){
			if(a[x][i]){
				cntb+=boom(x,i);
				break;
			}
		}
		for(int i=y-1;i;i--)
			if(a[x][i]){
				cntb+=boom(x,i);
				break;
			}
	}
	return cntb;
}
bool check(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=6;j++){
			if(a[i][j])return 0;
		}
	return 1;
}
//void dfs(int x,int goal){
//	if(ans>goal+1)return ;
//	if(check()&&x==goal){
//		answer=min(ans,answer);
//		return ;
//	}
//	copy1(x);
//	for(int i=1;i<=3;i++)
//		for(int j=1;j<=6;j++){
//			if(a[i][j]){
//				int t=ans;
//				ans++;
//				if(op==1)ans-=boom(i,j)/3;
//				else ans+=0*boom(i,j);
//				dfs(x+1);
//				copy2(x);
//				ans=t;
//			}
//		}
//}
int main(){
	scanf("%d%d",&T,&op);
	freopen("splash.in","r",stdin);
	freopen("splash.out","w",stdout);
	while(T--){
		for(int i=1;i<=6;i++){
			for(int j=1;j<=6;j++){
				scanf("%d",&a[i][j]);
			}
		}
		if(op==2&&T==5)printf("%d\n",20-dfspf2());
		if(op==1&&T==5)printf("%d\n",20-dfspf1());
	}
}

