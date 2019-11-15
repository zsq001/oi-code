#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=100005;
int n;
char s[N],t[N];

namespace pt1{
	bool eq(int l,int r,int x,int y){
		for(int i=l,j=x;j<=y;i++,j++)if(s[i]!=s[j])return 0;
		return 1;
	}
	bool jump(int l,int r,int x,int y){
		bool jp=0;
		for(int i=l,j=x;j<=y;i++,j++)
			if(s[i]!=s[j]){
				if(!jp){
					++j,jp=1;
					if(j<=y&&s[i]!=s[j])return 0;
				}
				else return 0;
			}
		return 1;
	}
	bool check(int len){
		bool jp=0;
		int p=len+1;
		while(p<=n){
			if(eq(1,len,p,min(n,p+len-1)))p+=len;
			else {
				if(jp)return 0;
				if(jump(1,len,p,min(n,p+len)))jp=1,p+=len+1;
				else return 0;
			}
		}
		return 1;
	}
	void solve(){
		int res=n;
		for(int l=1;l<=n;l++)
			if(check(l)){res=min(res,l);break;}
		for(int i=n>>1;i;i--)swap(s[i],s[n-i+1]);
		for(int l=1;l<=n;l++)
			if(check(l)){res=min(res,l);break;}
		printf("%d\n",res);
	}
}
/*namespace pt2{
	int cnt[265];
	int q[N],sz=0,ch;
	void solve(){
		memset(cnt,0,sizeof(cnt)); sz=ch=0;
		for(int i=1;i<=n;i++)++cnt[s[i]];
		for(int i=1;i<=255;i++)if(cnt[i]){
			if(cnt[i]<cnt[ch])ch=i,sz=0;
			if(cnt[i]==cnt[ch])q[++sz]=i;
		}
		
	}
}*/

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		pt1::solve();
//		else pt2::solve();
	}
}
