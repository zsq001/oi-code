#include <bits/stdc++.h>
using namespace std;

long long n;

bool isprime(long long x)
{
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    cin >> n;
    for (long long i = n; i>= 1; i--)
    {
        if (!isprime(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}
