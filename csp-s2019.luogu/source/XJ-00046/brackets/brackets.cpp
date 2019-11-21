#include<bits/stdc++.h>
using namespace std;
int a,s=0,i,j,k,pl=0,e,c[21];
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>a;
	char b[a];
	for(i=0;i<a;++i)
	 cin>>b[i];
	for(i=2;i<=a;++i)
	 cin>>c[i];
		 for(j=a;j>1;j--)
	{
	e=j;
	while(e!=1)
	{
	
		if(b[e-1]==40)
		++k,pl=pl-e+1;
		else
		--k,pl=pl+e-1;
		e=c[e-1];
		}
	 if((pl>=0)&&(k==0))
	 s++;
	 pl=0;
	 }
 s=2*a;
		
		printf("%d",s);
		
		
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	

