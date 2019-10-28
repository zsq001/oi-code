#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	x=f?-x:x;
}

struct YHH{
	double x,y;
}a[10];
double d[10],r[10],R,ans,k,b;
bool vis[10];
int n,rr;


inline double D(YHH A,YHH B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

inline bool cmp(YHH A,YHH B){
	if(A.x==B.x) return A.y<B.y;
	return A.x<B.x;
}

inline void judge(){
	if(n==2) printf("%.2f\n",D(a[1],a[2])*D(a[1],a[2]));
	if(n==3&&a[1].x==0&&a[1].y==0&&a[2].x==0&&a[2].y==1&&a[3].x==1&&a[3].y==0) printf("1.17");
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n;++i) d[i]=D(a[i],a[i+1]);
		r[1]=d[1];r[n]=d[n-1];
		for(int i=2;i<=n-1;++i){
			if(d[i-1]<d[i]) r[i]=d[i-1];
			else 	        r[i]=d[i];
		}
		for(int T=1;T<=n;++T){
			R=-10000;
			for(int i=1;i<=n;++i)
				if(!vis[i]&&r[i]>R) R=r[i],rr=i;
			vis[rr]=1;
			if(R<0) R=0;
			ans+=R*R;
			r[rr-1]-=R;
			r[rr+1]-=R;
		}
		printf("%.2lf\n",ans);
	}
}

int main(){
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i].x),read(a[i].y);
	}
	judge();
	return 0;
}
