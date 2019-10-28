#include"cstdio"
#include"cmath"
#include"iostream"

using namespace std;

typedef long long ll;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	
	int V;
	ll S = 1000000000000000000LL;
	
	cin >> V;
	
	for(int i = 1 ; i * i * i <= V ; i++)
		if(V % i == 0)
			for(int j = i ; j * j * i <= V ; j++)
				if((V / i) % j == 0)
				{
					int k = V / i / j;
					S = min((ll)V / i + V / j + V / k , S);
				}
	
	cout << S * 2 << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
