#include<iostream>
#include<algorithm>
using namespace std;
char f[20];
int aa[20];
int main()
{
	int a,b=0,c,d;
	char e,g;
	gets(f);
	aa[1]=f[0];
		aa[2]=f[3];
		aa[3]=f[6];
		aa[1]-=48;
		aa[2]-=48;
		aa[3]-=48;
	if((f[0]==f[3]&&f[3]==f[6])&&(f[1]==f[4]&&f[4]==f[7]))
	{
		cout<<"0";
		return 0;
	}
	if(f[1]==f[4]&&f[4]==f[7])
	{
		sort(aa+1,aa+3);
		if(aa[2]-1==aa[1]&&aa[2]+1==aa[3])
		cout<<"0";
		else if(aa[2]+2==aa[3])
		cout<<"1";
		else if(aa[2]-2==aa[1])
		cout<<"1";
		else if(aa[2]+1==aa[3])
		cout<<"1";
		else if(aa[2]-1==aa[1])
		cout<<"1";
		else
		cout<<"2";
		return 0;
	}
	else if(f[1]==f[4])
	{
		if(aa[1]==aa[2])
		cout<<"1";
		else if(aa[2]+2==aa[3])
		cout<<"1";
		else if(aa[2]-2==aa[1])
		cout<<"1";
		else if(aa[2]+1==aa[3])
		cout<<"1";
		else if(aa[2]-1==aa[1])
		cout<<"1";
		else
		cout<<"2";
		return 0;
	}
	else if(f[7]==f[4])
	{
		if(aa[3]==aa[2])
		cout<<"1";
		else if(aa[2]+2==aa[3])
		cout<<"1";
		else if(aa[2]-2==aa[1])
		cout<<"1";
		else if(aa[2]+2==aa[1])
		cout<<"1";
		else if(aa[2]-2==aa[3])
		cout<<"1";
		else if(aa[2]+1==aa[3])
		cout<<"1";
		else if(aa[2]-1==aa[1])
		cout<<"1";
		else if(aa[2]+1==aa[1])
		cout<<"1";
		else if(aa[2]-1==aa[3])
		cout<<"1";
		else
		cout<<"2";
		return 0;
	}
	else if(f[1]==f[4])
	{
		if(aa[3]==aa[2])
		cout<<"1";
		else if(aa[2]+2==aa[3])
		cout<<"1";
		else if(aa[2]-2==aa[1])
		cout<<"1";
		else if(aa[2]+2==aa[1])
		cout<<"1";
		else if(aa[2]-2==aa[3])
		cout<<"1";
		else if(aa[2]+1==aa[3])
		cout<<"1";
		else if(aa[2]-1==aa[1])
		cout<<"1";
		else if(aa[2]+1==aa[1])
		cout<<"1";
		else if(aa[2]-1==aa[3])
		cout<<"1";
		else
		cout<<"2";
		return 0;
	}
	else
	cout<<"2";
	return 0;
	
}
