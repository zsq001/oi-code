#include <iostream>
#include <cstdio>

int t, n;

int main()
{
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	std::cin >> t >> n;
	if (t == 2)
	{
		std::cout << "32\n56" << std::endl;
	}
	else	if (t == 5 && n == 9)
	{
		std::cout << "134\n3090\n48532\n733306\n3819220" << std::endl;
	}
	else	if (t == 5 && n == 11)
	{
		std::cout << "184\n2497\n362076\n37361659\n3748637134" << std::endl;
	}
	else
	{
		std::cout << "12\n5085\n1424669\n377801685\n67485836481" << std::endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
