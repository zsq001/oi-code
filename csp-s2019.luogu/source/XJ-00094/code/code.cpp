#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
template <class T> void read(T &x){
	x=0;bool f=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') f=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=f?-x:x;
}
queue <int> q;
unsigned long long n,tmp;
int a=1,b=0;
long long k;
void work(unsigned long long x,long long m){
	if(m==0) return;
	tmp=pow(2,m-1);
	if(x>tmp){
			q.push(1);
			tmp=tmp*2;
			x=tmp-x+1;
			work(x,m-1);
		}
	else{
			q.push(0);
			work(x,m-1);
		}
	return;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read(n),read(k);
	k++;
	work(k,n);
//	while(k){
//		if(k>(1<<(n-1))){
//			q.push(1);
//			k=(1<<n)-k+1;
//			n--;
//		}
//		else{
//			q.push(0);
//			k=k-1;
//			n--;
//		}
//	}
	while(q.empty()==0){
		tmp=q.front();
		q.pop();
		if(tmp)printf("1");
		else printf("0");
	}
	return 0;
}
