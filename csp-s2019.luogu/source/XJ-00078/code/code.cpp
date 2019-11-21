#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,pan=0,ji=1,b[101];
vector<int> a[2];
//int a[2][1000001];
int mi(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i++)
	ans*=2;
	return ans;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&k);
	a[0].push_back(0);
	a[0].push_back(1);
	//a[0][0]=0;a[0][1]=1;
	for(int j=1;j<n;j++)
	{
		pan=!pan;
		for(int i=0;i<mi(2,ji);i++)
		{
			//a[pan][i]=a[!pan][i];
			a[pan].push_back(a[!pan][i]);
		}
		for(int i=mi(2,ji);i<mi(2,ji+1);i++)
		{
			//a[pan][i]=a[!pan][mi(2,ji)+mi(2,ji)-1-i]+mi(2,ji);
			a[pan].push_back(a[!pan][mi(2,ji)+mi(2,ji)-1-i]+mi(2,ji));
		}
		ji+=1;
		a[!pan].clear();
	}
	int an=a[pan][k];
	int i=0;
	for(int j=1;;j++)
	{
		if(an==1){
			b[i]=1;
			break;
		}
		if(an==0){
			b[i]=0;
			break;
		}
		if(an%2==1)
		{
			b[i]=1;
			i++;
			an=(an+1)/2-1;
		}
		if(an%2==0){
			b[i]=0;
			i++;
			an=an/2;
		}
	}
	for(int j=i;j>=0;j--)
		printf("%d",b[j]);
	return 0;
}
