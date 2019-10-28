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

const int N = 2010 , mod = 10017;
int h[2][N] , mi[N] , len;
char str[2][N];

inline int Hash(int s , int t , int k)
{
	return h[k][t] - h[k][s - 1] * mi[t - s + 1];
}

long long Count(int s , int t , int k)
{
	int l = t - s + 1 , ans = 0;
	for(int length = 1 ; length <= l ; length++)
	{
		int s1 = t - length + 1 , t1 = t - length + (length + 1) / 2;
		int s2 = len + 1 - t , t2 = len - t + (length + 1) / 2;
		ans += Hash(s1 , t1 , k) == Hash(s2 , t2 , k ^ 1);
	}
	return ans;
}

int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	
	scanf("%s\n" , str[0]);
	len = strlen(str[0]);
	for(int i = 0 , j = len - 1 ; i < len ; j-- , i++)
		str[1][i] = str[0][j];
	
	mi[0] = 1;
	h[0][1] = str[0][0] - 'a';
	h[1][1] = str[1][0] - 'a';
	
	for(int i = 1 ; i <= len ; i++)
	{
		mi[i] = mi[i - 1] * mod;
		h[0][i + 1] = h[0][i] * mod + str[0][i] - 'a';
		h[1][i + 1] = h[1][i] * mod + str[1][i] - 'a';
	}
		
	long long ans = 0 , s = 0;
	for(int i = 0 ; i < len - 1  ; i++)
	{
		s += Count(1 , i + 1 , 0);
		ans += s * Count(1 , len - i - 1 , 1);
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
