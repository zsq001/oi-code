#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 1000005
using namespace std;
const int inf=1e9+7;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int n,a[maxn],q,k,mi,ma,cnt,nt,nti,now,nx;
int main(){
	freopen("c.in","r",stdin);  
	freopen("c.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	read(q);
	while(q--){
		read(k);
		int i=1;
		while(i<n){
			mi=inf,ma=nt=0;
			now=a[i];
			for(int j=i;j<=i+k&&j<=n;j++){
				if(a[j]>=ma){
					ma=a[j];
					nx=j;
				}
				mi=min(mi,a[j]);
				if(a[j]<now) 
					if(nt<=a[j]){
						nt=a[j];
						nti=j;
					}
					
			}
			if(now<=mi){
				i=nx;
				cnt++;
			}
			else i=nti;
		}
		printf("%d\n",cnt);
		cnt=0;
	}
	return 0;
}
