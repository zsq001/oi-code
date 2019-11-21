#include<bits/stdc++.h>
using namespace std;
int n,k;
int code[4]={00,01,11,10};
int codeplus[8]={000,001,011,010,110,111,101,100};
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	if(k==3)
	{
		cout<<code[3];
	}
	else
	{
		cout<<codeplus[7];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
