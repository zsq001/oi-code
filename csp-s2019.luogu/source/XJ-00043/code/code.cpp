#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,k,m;
ll gl[100100];
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	m=n;
	for(int i=0;i<n;++i){
		if(m==1){
			if(k==1)
			gl[i]=1;
			else
			gl[i]=0;
		}
		else if(k<=(pow(2,m)/2-1)){
				gl[i]=0;
				m--;
		}
		else{
			k=(pow(2,m)-1)-k;
			gl[i]=1;
			m--;
		}
	}
	for(int i=0;i<n;++i)
	printf("%lld",gl[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
