#include <cstdio>
#include <cstring>
#define ll long long
char a[3000];
int len,end[3000],begin[3000];
ll ans;
/*void solve(int l,int r)
{
	int i=l,j=r;
	while(a[i]==a[j])
	{
		i++;
		j--;
		if(i>=j)break;
	}
	if(i>=j)
	{
		end[r]++;
		begin[l]++;
	}
}*/
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	//freopen("data.txt","r",stdin);
	ll rb;
	int l,r;
	scanf("%s",a+1);
	len=strlen(a+1);
	//for(int i=1;i<=len;++i)
		//end[i]=begin[i]=1;
	for(int i=1;i<=len;++i)
		for(int j=i;j<=len;++j)
		{
			l=i,r=j;
			while(a[l]==a[r])
			{
				++l;
				--r;
				if(l>=r)break;
			}
			if(l>=r)
			{
				++end[j];
				++begin[i];
			}
		}
	for(int i=1;i<len;++i)
	{
		rb=0;
		for(int j=i+1;j<=len;++j)
			rb+=begin[j];
		ans+=end[i]*rb;
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
