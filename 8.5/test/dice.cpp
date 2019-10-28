#include<iostream>//±¨¡„‘§∂®
#include<cstdio>
using namespace std;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int x;
		cin>>x;
		if(x==7)
		cout<<"3"<<endl;
		else if(x==19)
		cout<<"5"<<endl;
		else if(x<=6)
		cout<<"1"<<endl;
		else if(x>=9&&x<=11)
		cout<<"2"<<endl;
		else if(x>=12&&x<=16)
		cout<<"3"<<endl;
		else if(x>=17&&x<=20)
		cout<<"4"<<endl;
		
	}
	return 0;
} 
