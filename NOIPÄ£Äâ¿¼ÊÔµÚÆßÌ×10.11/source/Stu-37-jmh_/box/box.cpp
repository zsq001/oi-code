#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

int ab=1,bc=1,ac=1,ans;
int inp[100050],prime[100050];
int v,p;

void f(int pr){
	while(v%pr==0){
		v/=pr;
		if(ab>=bc){
			if(ab>=ac){
				bc*=pr;
                ac*=pr;
			}
			else{
				ab*=pr;
				bc*=pr;
			}
		}
		else{
			if(bc>=ac){
				ab*=pr;
				ac*=pr;
			}
			else{
				bc*=pr;
				ab*=pr;
			}
		}
	}
}

int_ main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%lld",&v);
	int ttt=v;
	inp[0]=inp[1]=1;
	for(int i=2;i*i <= v;i++){
		if(!inp[i]){
			prime[++p]=i;
			f(prime[p]);
		}
		for(int j=1;j<=p && (prime[j]*i*i*prime[j] <=v);j++){
			inp[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
	if(v==ttt){
		ans=2*(2*v+1);
	}
	else{
		ans=2*(ab+bc+ac);
	}
	printf("%lld",ans);
	return 0;
}
