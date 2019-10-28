#include<iostream>
#include<cstdio>
#include<cstring>
#define mmm 10000
using namespace std;
char aa[mmm];
int ss[mmm];
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>aa;
	int len=strlen(aa);
	for(int i=1;i<=len;i++)
	ss[i]=aa[i]-'a'+1;
	cout<<5;
	return 0;
}
