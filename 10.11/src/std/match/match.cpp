#include"cstdio"
#include"cstdlib"
#include"cstring"
#include"cmath"
#include"algorithm"
#include"vector"
#include"set"
#include"iostream"
#include"map"

using namespace std;

typedef pair<int , int> PII;
set<PII> memo;

int n , m , x , y , p , ans;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d %d %d %d" , &n , &m , &x , &y);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d" , &p);
		memo.insert(make_pair(p , i));
	}
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%d" , &p);
		set<PII>::iterator iter = memo.lower_bound(make_pair(p - y , 0));
		if(iter == memo.end()) continue;
		if(iter -> first - x <= p)
			ans++ , memo.erase(iter);
	}
	
	printf("%d\n" , ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
