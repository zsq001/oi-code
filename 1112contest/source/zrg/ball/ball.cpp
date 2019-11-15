#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
#define inf 500000000000000000
typedef long long ll;
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
stack <char> s;
int n;
char ch;
ll ans=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);
	while(n--){
		ch=getchar();
		while(ch!='B'&&ch!='R') ch=getchar();
		s.push(ch);
	}
	while(s.empty()==0) {
		ch=s.top();
		if(ch=='B') break;
		s.pop();
	}
	while(s.empty()==0){
		ch=s.top();s.pop();
		if(ans>inf) {
			printf("-1"); 
			return 0;
		}
		ans<<=1;
		if(ch=='B') ans|=1;
		
	}
	printf("%lld",ans);
	return 0;
}
