#include<iostream>
#include<cstdio>
#include<cstring>
const int inf =0x7f;
using namespace std;
int main()
{
//	freopen("complexity.in","r",stdin);
//	freopen("complexity.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		/*memset(st,"",sizeof(st));
		memset(ed,"",sizeof(ed));
		memset(bian,"",sizeof(bian));*/
		char o[999],bian[120],st[120],ed[120];
	/*for(int i=1;i<=120;i++)
		{
			bian[i]=;
			st[i]=;
			ed[i]=;
		}*/
		int line,on,qt=0,ceng=0;
		int qw=0;
		cin>>line;
		cin>>o;
		if(o[3]!='^')
		{
		if(o[2]=='1')
			on=0;
		if('0'<o[3] or o[3]>'9')
			on=(10*(o[2]-'0'))+(o[3]-'0');
		else
			on=(o[2]-'0');
		}
		else 
		{
			if('0'<o[5] or o[5]>'9')
				on=(10*(o[4]-'0'))+(o[5]-'0');
			else
				on=(o[4]-'0');
		}
		int skip=0;
		int i=0;
		while (line--)
		{
			char qwq;
			cin>>qwq;
			if(qwq=='E')
				ceng--;
			else if(qwq=='E' and skip)
				skip--;
			else
			{
				if(!skip)
				{
					ceng++;
					qt=max(qt,ceng);
				}
				else
				skip++;
				char bi,s,edf;
				cin>>bian[i]>>s>>edf;
				i++;
				if(s=='n')
					st[i]=inf;
				else
					st[i]=s-'0';
				if(edf=='n')
					ed[i]=inf;
				else
					ed[i]=edf-'0';
				for(int j=i-1;j>0;j--)
				{
					if(bian[i]==bian[j])
					{
						cout<<"ERR"<<endl;
						qw=1;
						break;
					}
				}
				if(qw==1)
					break;
				if(ed[i]>st[i])
				{
					skip=1;
					continue;
				}
			}
				if(qw==1)
					continue;
		}
		int qqqqq=0;
		if(qt==on)
		{
			qqqqq=1;
			cout<<"Yes"<<endl;
		}
		else
		{
			qqqqq=1;
			cout<<"No"<<endl;
		}
		if(qqqqq==0)
		cout<<"ERR"<<endl;
	}
	return 0;
}
