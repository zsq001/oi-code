#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
char key[300010]={0};
int change[300010];
int n,cnt=1,m=0;

bool cmp(int x,int y)
{
	return x<y;
}
int call(int a)
{
	int hh=1;
	if(a&&key[a]==key[a-1]) hh++;
	if(a&&key[a]!=key[a-1]) hh--;
	return hh;
}

int calr(int a)
{
	int hh=1;
	if(a!=n*3-1&&key[a]==key[a+1]) hh++;
	if(a!=n*3-1&&key[a]!=key[a+1]) hh--;
	return hh;
}

int c_x()
{
	for(int i=3;i<n*3;i++)
	{
		int fi=i-3,se=i-2,th=i-1,fo=i;
		if(key[fi]==key[se]&&key[se]!=key[th]&&key[th]==key[fo])
		{
			cnt+=2;
			key[se]=!key[se];
			key[th]=!key[th];
			change[++m]=se;
			i+=2;
		}
		if(cnt>=(n<<1)) return 1;
	}
	return 0;
}

void c_y()
{
	for(int i=3;i<n*3;i++)
	{
		int fi=i-3,se=i-2,th=i-1,fo=i;
		if(key[fi]==key[se]&&key[se]==key[th]&&key[th]==key[fo])
		{
			if(call(fi)>=calr(th)) 
			{
				cnt+call(fi);
				change[++m]=fi;
				if(cnt>=(n<<1)) return ;
				key[fi]=!key[fi];
				key[se]=!key[se];
				cnt+=2;
				change[++m]=se;
			}
			else
			{
				cnt+call(th);
				change[++m]=th;
				if(cnt>=(n<<1)) return ;
				key[se]=!key[se];
				key[fo]=!key[fo];
				cnt+=2;
				change[++m]=se;
			} 
		}
		if(cnt>=(n<<1)) return ;
	}
	return ;
}

int main()
{
	freopen("key.in","r",stdin);	
	freopen("key.out","w",stdout);
	scanf("%s",key);
	n=strlen(key)/3;
	for(int i=0;i<n;i++)
	{
		if(i&&key[i-1]!=key[i]) cnt++;
	}
	if(cnt>=(n<<1))
	{
		printf("0\n");
		return  0;
	}
	if(c_x())
	{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
		{
			printf("%d ",change[i]);
		}
		return 0;
	}
	c_y();
	sort(change+1,change+m+1);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
	{
		printf("%d ",change[i]+1);
	}
	fclose(stdin);	
	fclose(stdout);	
	return 0;
}
