#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct node{
	int x,y;
};
node huiwen[200000];
int cnt;
map <pair<int,int>,int>visit;
int ans;
char line[2001];
int houji[2001];
int all_the_huiwen[2001];
int sum[27];
int lenther;
pair<int,int> news;
int find_huiwen(int x,int y){
	if(x==y){
		huiwen[++cnt]=(node){x,y};
		news.first=x ; news.second=y; 
		visit[news]=1;
		return 1;
	}
	if(y==x+1){
		if(line[x]==line[y])
		{
			huiwen[++cnt]=(node){x,y};
			news.first=x ; news.second=y; 
			visit[news]=1;
			return 1;
		}
		return 0;
	}
	if(line[x]==line[y]){
		if(find_huiwen(x+1,y-1)){
			huiwen[++cnt]=(node){x,y};
			news.first=x ; news.second=y; 
			visit[news]=1;
		}
		else {
			news.first=x , news.second=y; 
			visit[news]=0;
		}
	}
	else {
		news.first=x , news.second=y; 
		visit[news]=0;
		return 0;
	}
	return 0;
}
int cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%s",line+1);
	lenther=strlen(line+1);
	for(int i=lenther;i>=1;--i)
	{
		if(sum[line[i]]){
			houji[i]=sum[line[i]];
		}
		else houji[i]=-1;
		sum[line[i]]=i;
	}
	for(int i=1;i<=lenther;++i)
	{
		for(int j=i;j!=-1;j=houji[j])
		{
			news.first=i ; news.second=j; 
			if(visit.find(news)!=visit.end())continue;
			find_huiwen(i,j);
		}
	}
	sort(huiwen+1,huiwen+cnt+1,cmp);
	int ti=0;
	for(int i=1;i<=cnt;++i)
	{
		for(int j=ti;j<huiwen[i].x;++j)
		{
			all_the_huiwen[j]=cnt-i+1;
		}
		ti=huiwen[i].x;
    }
    for(int i=1;i<=cnt;++i)
    {
    	ans=ans+all_the_huiwen[huiwen[i].y];
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
