#include<iostream>
using namespace std;
	int n,m,k,x;
int poww(int a, int b) {
    int ans = 1, base = a;
    while (b ) {
        if (b & 1)
        	ans=ans*base%n;
        base=base*base%n;
        b >>= 1;
    }
    return ans;
}
int main()
{
	cin>>n>>m>>k>>x;
	cout<<(x%n+m%n*poww(10,k)%n)%n;
	return 0;
}
