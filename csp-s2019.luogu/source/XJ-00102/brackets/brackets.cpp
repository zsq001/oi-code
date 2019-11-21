#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("brackets.in","r");
	freopen("brackets.out","w");
	int n,b[1000],s=0,c;
	char a[1000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		c=1;
	    s=c*b[i]xor(c+1)*b[i+1];
    }
	printf("%d",s);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
