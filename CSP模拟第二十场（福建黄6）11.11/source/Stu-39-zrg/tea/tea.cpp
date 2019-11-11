#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 10000000
using namespace std;
template <class T> void read (T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
queue <int> q;
int m,c[maxn],opt;
bool czy;
void add(int x,int val){
	while(x<=maxn){
		c[x]+=val;
		x+=((-x)&x);
	}
}
int query(int x){
	int ret=0;
	while(x){
		ret+=c[x];
		x-=((-x)&x);
	}
	return ret;
}
bool check(int x){
	int f=query(x);
	if(f==x) return 1;
	return 0;
}
int tmp,ans,maxx;
int main(){
	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	read(m),read(czy);
	while(m--){
		read(opt);
		if(opt==1){
			read(tmp);
			if(czy==1)
				tmp^=ans;
			tmp++;
			if(tmp>maxx) maxx=tmp;
			add(tmp,1);
		}
		if(opt==2){
			read(tmp);
			if(czy==1)
				tmp^=ans;
			tmp++;
			add(tmp,-1);
			q.push(tmp);
		}
		if(opt==3){
			if(q.empty()) continue;
			tmp=q.front();
			q.pop();
			add(tmp,1);
		}
		if(opt==4){
			int l=1,r=maxx,mid=l+((r-l)>>1);
			while(l<=r){
				if(check(mid)) {
					l=mid+1;
					mid=l+((r-l)>>1);
				}
				else {
					r=mid-1;
					mid=l+((r-l)>>1);
				}
			}
			ans=l-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}
