#include <iostream>
#include <algorithm>

std::string s[50000];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> s[i];
	std::sort(s, s + n, [](const std::string &a, const std::string &b)
			  {
				  return a + b < b + a;
			  });
	for (int i = 0; i < n; ++i)
		std::cout << s[i];
	return 0;
}
