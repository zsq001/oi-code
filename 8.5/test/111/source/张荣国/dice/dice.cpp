#include<stdio.h>
#include<algorithm>
#include<string.h>
#define one 1
#define two 2
#define three 3
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
int T,n,ans,bns,lm,f[7][1000005];
int mov[4][5]={{0},{0,2,3,4,5},{0,1,3,4,6},{0,1,2,5,6}};
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		memset(f,0x3f,sizeof(f));
		ans=0;
		bns=0x7fffffff;
		
		if(n>=100) ans=(n-100)/11*2,lm=100+(n-100)%11;
		else lm=n;
		f[1][lm]=0;
		for(lm;lm>0;lm--){
			for(int i=1;i<=6;i++){
				if(i==1||i==6)
					for(int j=1;j<=4;j++){
						int w=mov[one][j];
						if(w>lm)continue;
						if(w==lm) {
							bns=min(bns,f[i][lm]+1);
							break;
						}
						else f[w][lm-w]=min(f[w][lm-w],f[i][lm]+1);
					}
				else if(i==2||i==5)
					for(int j=1;j<=4;j++){
						int w=mov[two][j];
						if(w>lm)continue;
						if(w==lm) {
							bns=min(bns,f[i][lm]+1);
							break;
						}
						else f[w][lm-w]=min(f[w][lm-w],f[i][lm]+1);
					}
				else if(i==3||i==4)
					for(int j=1;j<=4;j++){
						int w=mov[three][j];
						if(w>lm)continue;
						if(w==lm) {
							bns=min(bns,f[i][lm]+1);
							break;
						}
						else f[w][lm-w]=min(f[w][lm-w],f[i][lm]+1);
					}
			}
		}
		printf("%d\n",ans+bns);
	}
	return 0;
}
