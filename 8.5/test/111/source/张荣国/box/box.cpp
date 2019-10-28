#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
int T,n,l,r,sa,sb,a[1005];
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i]);
		l=1;r=n;
		sa=sb=0;
		for(int i=1;i<=n;i++){
			if(l==r){
				if(i%2==1) sa+=a[l];
				else sb+=a[l];
				break;
			}
			if(a[l]-max(a[l+1],a[r])>=a[r]-max(a[r-1],a[l])){
				if(i%2==1) sa+=a[l];
				else sb+=a[l];
				l++;
			}
			else {
				if(i%2==1) sa+=a[r];
				else sb+=a[r];
				r--;
			}
		}
		printf("%d\n",sa-sb);
	}
	return 0;
}
