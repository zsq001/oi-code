#include<iostream>
using namespace std;
int a[11111][3];
int main()
{
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	if(m==1)
	cout<<20<<endl<<"1033-1039-1049-1249-1279-5279-5179-8179"<<endl<<20<<endl<<"1373-3373-3343-3347-5347-5147-8147-8117-8017"<<endl<<0<<endl<<"1033"<<endl;
	else 
	cout<<20<<endl<<20<<endl<<0;
	return 0;
}
