#include <bits/stdc++.h>
using namespace std;
unsigned long long K[500001],father[500001],ans;
int n;
char c;
bool kuohao[500001];
unsigned long long g(int i)
{
	unsigned long long temp=0,top=0;
	for(;;)
	{
		if(i==0) return temp;
		if(kuohao[i]) top++;
		else top--;
		i=father[i];
		if(top==0) temp++;
		if(top==-1) return temp;
	}
}
unsigned long long k(int i)
{
	if(K[i]!=-1) return K[i];
	return k(father[i])+g(i);
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	memset(K,-1,sizeof(K));
	K[1]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c==')')
			kuohao[i]=1;	
	}
	for(int i=2;i<=n;i++)
		cin>>father[i];
	for(int i=1;i<=n;i++)
		ans^=(i*k(i));
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
