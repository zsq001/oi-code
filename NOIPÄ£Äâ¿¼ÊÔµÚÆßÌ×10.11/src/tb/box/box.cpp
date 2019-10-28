#include<stdio.h>
#include<algorithm>
using namespace std; 
int v;
int a, b, c;
long long ans = 0x7fffffff;
void search()
{
	for(int i = 1; i*i*i <= v; i++)
	{
		a = i;
		for(int j = 1; j*j <= v/a; j++)
		 {
		 	b = j;
	    	c = v/(a*b);
	    	if((v % (a*b*c)) == 0)
	      	  ans = min(ans, (long long)(2*(a*b+a*c+c*b)));
		 } 
	}
}
int main()
{
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	scanf("%d", &v);
	search();
	printf("%lld\n", ans);
	return 0; 
}
