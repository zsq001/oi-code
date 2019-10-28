#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
//#define pr pair<int,int> 
//#define x tmp.first
//#define y tmp.second

int a,b,xx,yy;

int gcd(int xx,int yy)
{
	if(yy==0) return xx;
	else return gcd(yy,xx%yy);
}

//pr exgcd(int a,int b)
//{
//	if(b==0) return  pr(1,0);
//	pr tmp=exgcd(b,a%b);
//	return pr(y,x-a/b*y);
//}

int main()
{
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);

	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d%d",&a,&b);
		scanf("%d%d",&xx,&yy);
		k=gcd(a,b);
		xx=abs(xx);
		yy=abs(yy);
		a=abs(a);
		b=abs(b);
		if(xx<k||yy<k||xx%k||yy%k)
		{
			printf("N\n");
			continue;
		}
		else
		{
			printf("Y\n");
			continue;
		}
//		printf("%d ",k);
//		pr tmp=exgcd(a,b);
//		printf("%d %d",x,y);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
