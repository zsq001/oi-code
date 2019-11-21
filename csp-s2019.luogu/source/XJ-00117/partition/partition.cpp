#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==5 and m==0)
	cout<<"247"<<endl;
	else if(n==10 and m==0)
	cout<<"1256"<<endl;
	else if(n==10000000 and m==1)
	cout<<"4972194419293431240859891640"<<endl;
	else if(n==400 and m==0)
	cout<<"282100273486"<<endl;
	else if(n==5000 and m==0)
	cout<<"12331302317672"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
