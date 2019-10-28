#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long V,a,b,s,a1,b2;
int gs(long long a,long long b)
{
	int c=V/a/b;
	if(s==0)
	{
		s=2*(a*b+a*c+b*c);
		a1=a;
		b2=b;
	}
	else if(s>=2*(a*b+a*c+b*c))
	{
		s=2*(a*b+a*c+b*c);
		a1=a;
		b2=b;
	}
	return 0;
}
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	cin>>V;
	for(a=1;a*a*a<=V;a++)
	{
		if(V%a==0)
		{
			long long c=V/a,sc=(long)sqrt(c);
			for(b=a;b<=sc;b++)
			{
				if(c%b==0)gs(a,b);
			}
		}
	}
	cout<<s<<endl;
	//cout<<a1<<' '<<b2<<' '<<V/a1/b2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
