#include<cstdio>
#include<algorithm>
using namespace std;


int ans,a,b,t,n;
int c[11]={0,1,1,1,1,1,2,3,2,2,2};

int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a=n/11;
		b=n%11;
		if(a==0 && b==1) printf("%d",0);
		else{
		    ans=a*2+c[b];
		    printf("%d\n",ans);
		}
	} 
	return 0;
}


