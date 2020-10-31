#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int n,q,f[10][10][10][10],a[205][5],tot;
void read(int &x){
	int t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='0') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
bool is_prime(int p){
	for(int i=2;i<=sqrt(p)+1;i++)
		if(p%i==0) return 0;
	return 1;
}
void div(int x){
	tot++;
	int tmp=x;
	a[tot][1]=x/1000;
	a[tot][2]=x/100%10;
	a[tot][3]=x/10%10;
	a[tot][4]=x%10;
	}
int main(){
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	read(n),read(q);
	int x,y;
	for(int o=1;o<=n;o++){
		memset(f,0x3f,sizeof(f));
		read(x),read(y);
		div(x);
		div(y);
		int I=a[o*2-1][1],J=a[o*2-1][2],K=a[o*2-1][3],L=a[o*2-1][4];
		f[a[o*2][1]][a[o*2][2]][a[o*2][3]][a[o*2][4]]=0;
		for(int i=-9;i<=9;i++){
			for(int j=-9;j<=9;j++){
				for(int k=-9;k<=9;k++){
					for(int l=-9;l<=9;l++){
						if(I+i<=9&&J+j<=9&&K+k<=9&&L+l<=9&&I+i>=1&&J+j>=0&&K+k>=0&&L+l>=0&&is_prime((I+i)*1000+(J+j)*100+(K+k)*10+(L+l)))
						f[I][J][K][L]=min(f[I+i][J+j][K+k][L+l]+abs(i)+abs(j)+abs(k)+abs(l),f[I][J][K][L]);
					}
				}
			}
		}
		printf("%d\n",f[I][J][K][L]);
	}
	
	return 0;
}	
