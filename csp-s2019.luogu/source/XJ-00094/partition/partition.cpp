#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 500005
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
int type,n,nt[maxn],per[maxn],ed,st,val[maxn],tol,tor,a[maxn],ans;
bool lflag,rflag;
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	read(n),read(type);
	for(int i=1;i<n;i++) nt[i]=i+1,per[i]=i-1;
	per[n]=n-1;
	nt[n]=0;
	ed=n;
	st=1;
	if(type==0){
		for(int i=1;i<=n;i++) read(a[i]),val[i]=a[i];
		for(int i=n-1;i;i=per[i]){
			if(val[i]>val[nt[i]]){
				int x=nt[i];
				int ltmp,rtmp;
				ltmp=rtmp=val[x];
				for(int i=nt[x];nt[i];i=nt[i]){
					int now=val[i]+rtmp;
					if(i==ed){
						rflag=1;
						tor=i;
						rtmp=now;
						break;
					}
					if(now<=val[nt[i]]){
						if(now>=val[per[x]]){
							rflag=1;
							tor=i;
							rtmp=now;
							break;
						}
						else rtmp=now;
					}
					else break;
				}
				for(int i=per[x];i;i=per[i]){
					int now=val[i]+ltmp;
					if(now<=val[nt[x]]){
						if(i==st){
							lflag=1;
							tol=i;
							ltmp=now;
							break;
						}
						if(now>=val[per[i]]){
							lflag=1;
							tol=i;
							ltmp=now;
							break;
						}
						else ltmp=now;
					}
					else break;
				}
				if(!(lflag)&&!(rflag)){
					rtmp=val[x];
					for(int i=nt[x];i;i=nt[i]){
					int now=val[i]+rtmp;
					if(i==ed){
						rtmp=now;
						tor=i;
						break;
					}
					if(now>=val[per[x]]){
						if(now<=val[nt[i]]){
							tor=i;
							rtmp=now;
							break;
						}
						else rtmp=now;
					}
						nt[x]=nt[tor];
						per[nt[x]]=x;
						val[x]=rtmp;
					}
					
				}
				else if(lflag&&rflag){
					if(rflag<lflag){
						nt[x]=nt[tor];
						per[nt[x]]=x;
						val[x]=rtmp;
					}
					else {
						if(x==ed) ed=per[tol];
						per[x]=per[tol];
						nt[per[tol]]=x;
						val[x]=ltmp;
					}
					lflag=rflag=0;
				}
				else if(lflag){
					if(x==ed) ed=per[tol];
					per[x]=per[tol];
					nt[per[tol]]=x;
					val[x]=ltmp;
					lflag=0;
				}
				else if(rflag){
					nt[x]=nt[tor];
					per[nt[x]]=x;
					val[x]=rtmp;
					rflag=0;
				}
			}
		}
		for(int i=st;i<ed;i=nt[i]){
			ans+=(val[i]*val[i]);
		}
		printf("%d",ans);
	}
	return 0;
}
