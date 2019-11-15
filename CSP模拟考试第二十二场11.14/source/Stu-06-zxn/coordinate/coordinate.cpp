#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 
const ll mod=1e9+7;
int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

struct mat{
	ll a[3][3];
	void clean(){
		memset(a,0,sizeof(a));
	}
	mat operator *(mat x){
		mat ret;
		ret.clean();
		for(int k=1;k<=2;k++){
			for(int i=1;i<=2;i++)
				for(int j=1;j<=2;j++){
					ret.a[i][j]+=a[i][k]*x.a[k][j]%mod;
					ret.a[i][j]%=mod;
				}		
		}
		return ret;
	}
};

mat A;
	
void ksm(int n){
	mat ans;
	ans.clean();
	ans.a[1][1]=ans.a[2][2]=1;
	while(n){
		if(n&1) ans=ans*A;
		A=A*A;
		n>>=1;
	}
	printf("%lld",(ans.a[1][1]%mod+3*ans.a[2][1]%mod)%mod);
}

int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n;
	scanf("%d",&n);
	A.clean();
	A.a[1][2]=A.a[2][1]=1;A.a[2][2]=2;
	ksm(n);
	return 0;
}
