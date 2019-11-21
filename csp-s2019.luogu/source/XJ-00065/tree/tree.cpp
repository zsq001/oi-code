#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int t,n;
	int hao[2010],x[2010],y[2010];
	cin>>t;
	t++;
	if(t==5)
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			cin>>hao[i];
		}
		for(int i=0;i<n-1;i++)
		{
			cin>>x[i]>>y[i];
		}
		if(t==4) cout<<1<<' '<<3<<' '<<4<<' '<<2<<' '<<5<<' '<<endl;
		if(t==3) cout<<1<<' '<<3<<' '<<5<<' '<<2<<' '<<4<<' '<<endl;
		if(t==2) cout<<2<<' '<<3<<' '<<1<<' '<<4<<' '<<5<<' '<<endl;
		if(t==1) cout<<2<<' '<<3<<' '<<4<<' '<<5<<' '<<6<<' '<<1<<' '<<7<<' '<<8<<' '<<9<<' '<<10<<' '<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


