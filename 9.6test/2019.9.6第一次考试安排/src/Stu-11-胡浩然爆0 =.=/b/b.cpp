#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
} 

int f[2][50007],pos=1,len=1,ans,n,T;

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
//	freopen("qwq.txt","w",stdout);
//	read(T);
	read(n);
//	for(n=1;n<=T;++n){
//		memset(f,0,sizeof(f));
//		ans=0;
//		len=pos=1;
	f[0][0]=1;
	for(;;len++) if(len*(len+1)/2>n) break;
	--len;
	for(int i=1;i<=len;++i){
		memset(f[pos],0,sizeof(f[pos]));
		for(int j=i*(i+1)/2;j<=n;++j)
			f[pos][j]=(f[pos][j-i]+f[pos^1][j-i])%1000000007;
		ans=(ans+f[pos][n])%1000000007;
		pos^=1;
	}
	printf("%d\n",ans);
//}
	return 0; 
}
