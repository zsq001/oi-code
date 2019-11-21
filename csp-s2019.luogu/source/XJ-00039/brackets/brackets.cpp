#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
char en,emm[500050];
int ans[500050]={0},fa[500050]={0};
int main()
{
	int n,c,cut=0,d=0,w=0,m=1;
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%d",&n);
	scanf("%c",&en);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&emm[i]);
	}
	scanf("%c",&en);
	fa[1]=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!d)  c=i;
		if(emm[i]==')') 
		{
		    cut++;
		}
		else if(emm[i]=='(') 
		{
			if(cut>0)
			{
				ans[c]++;
				cut--;
			}
			else 
			{
				cut=0;
			}
		}
		if(fa[i])
		{
			i=fa[i]-1;
			d=1;
		}
		else
		{
			cut=0;
			i=c;
			d=0;
		}
	}
	w=ans[1];
	for(int i=2;i<=n;i++)
	{
		w=(ans[i]*i) xor w;
	}
	printf("%d",w);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
