#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef unsigned long long ll;
typedef double db;
const int N=100050;

int n;
struct pr{ll x,y;}a[N],b[N];

bool cmp(pr t1,pr t2){return t1.x>t2.x;}

void cal(ll &s,ll v1,ll t1,ll v2,ll t2){
	if(t1>=t2) s+=(v1-v2)*t2+v1*(t1-t2);
	else s+=(v1-v2)*t1-v2*(t2-t1);
}

int main(){
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].x); read(a[i].y);
		b[i].x=a[i].x; b[i].y=a[i].y;
	}
	sort(b+1,b+n+1,cmp);
	ll v1=0,v2=0,s=0;
	for(int i=1;i<=n;i++){
//		s+=v1*b[i].y-v2*a[i].y;
		cal(s,v1,b[i].y,v2,a[i].y);
		v1+=b[i].x*b[i].y;
		v2+=a[i].x*a[i].y;
	}
	printf("%llu.0\n",s);
	return 0;
}
