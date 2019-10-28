#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template <class T> void read(T &x){
	char s=getchar();int t=0;x=0;
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
//void init(){
//	skt[1]=1;
//	for(int i=2;i<=n;i++)
//		skt[i]=skt[i-1]*i;
//}
int zhs(int lowt){
	return (lowt*(lowt-1))/2;
}
int n,m,p,ans,tmp,a,b,c[505];
int main(){
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	read(n),read(m),read(p);
//	init();
	int lim=(p+1)/2;
	while(n--){
		read(a),read(b);
		tmp=abs(a-b);
		if(tmp>lim) tmp=p-tmp;
		c[tmp]++;
	}
	for(int i=1;i<=lim;i++)
		if(c[i]) ans+=zhs(c[i]);
	printf("%d",ans);
	return 0;
}
