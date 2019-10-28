#include <stdio.h>
#include <algorithm>
using namespace std;
int ve[100],valu[100],op[100],v[100][10],val[100][10],type[100],shu[100],f[50000];
int main()
{
	int n,m,bnt=0;
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ve[i],&valu[i],&op[i]);
		valu[i]=ve[i]*valu[i];
		if(!op[i])
		{
			v[++bnt][++shu[bnt]]=ve[i];
			val[bnt][shu[bnt]]=valu[i];
			type[i]=bnt;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(op[i])
		{
			v[type[op[i]]][++shu[type[op[i]]]]=v[type[op[i]]][1]+ve[i];
			val[type[op[i]]][shu[type[op[i]]]]=val[type[op[i]]][1]+valu[i];
			if(shu[type[op[i]]]==3)
			{
				v[type[op[i]]][++shu[type[op[i]]]]=v[type[op[i]]][2]+ve[i];
				val[type[op[i]]][shu[type[op[i]]]]=val[type[op[i]]][2]+valu[i];
			}			
		}
	}
	for(int i=1;i<=bnt;i++)
		for(int j=n;j>=1;j--)
			for(int k=1;k<=shu[i];k++)
				if(j>=v[i][k])f[j]=max(f[j],f[j-v[i][k]]+val[i][k]);
	printf("%d\n",f[n]);
	return 0;
}
