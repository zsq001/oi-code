#include<iostream>
#include<initializer_list>
using namespace std;
int a[10];
int main()
{
	int n;
	cin>>n;
	for(auto i:n)
		cin>>a[i];
	for(auto i:n)
		cout<<a[i]<<" ";
	return 0;
}
