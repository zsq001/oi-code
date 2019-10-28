#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans;
int w[200050];
int bf[200050],af[100050];

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("1");
		return 0;
	}
	if(n==2 || n==0){
		printf("0");
		return 0;
	}
	int ou=0,ji=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		if(i%2==1){
			ji+=w[i];
			bf[i]=ji;
		}
		else{
			ou+=w[i];
			bf[i]=ou;
		}
	}
	ou=0,ji=0;
	for(int i=n;i>=1;i--){
		if(i%2==1){
			ji+=w[i];
			af[i]=ji;
		}
		else{
			ou+=w[i];
			af[i]=ou;
		}
	}
	if(af[2]==af[3]) ans++;
	if((bf[1]+af[4])==af[3]) ans++;
	for(int i=3;i<=n;i++){
		if((bf[i-1]+af[i+2])==(bf[i-2]+af[i+1])) ans++;
	}
	printf("%d",ans);
	return 0;
}
