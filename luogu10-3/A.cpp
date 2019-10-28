#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct node{
	string q,ans;
}a[1000];
struct Node{
	string q,a,b,c,d;
}b[1000];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].q>>a[i].ans;
	for(int i=1;i<=q;i++)
		cin>>b[i].q>>b[i].a>>b[i].b>>b[i].c>>b[i].d;
	for(int i=1;i<=q;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[j].q.compare(b[i].q)==0)
			{
				if(a[j].ans.compare(b[i].a)==0)
				{
					cout<<"A"<<endl;
					break;
				}
				if(a[j].ans.compare(b[i].b)==0)
				{
					cout<<"B"<<endl;
					break;
				}
				if(a[j].ans.compare(b[i].c)==0)
				{
					cout<<"C"<<endl;
					break;
				}	
				if(a[j].ans.compare(b[i].d)==0)
				{
					cout<<"D"<<endl;
					break;
				}
			}
		}
	return 0;
}

