#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int T;
	cin >> T;
	cout << setprecision(2);
	cout << setiosflags(ios::fixed);
	while (T--)
	{
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == '+')
		{
			cout << a + b << "\n";
		}
		else if (c == '-')
		{
			cout << a - b << "\n";
		}
		else if (c == '*')
		{
			cout << a * b << "\n";
		}
		else
		{
			if (a % b == 0)
			{
				cout << a / b << "\n";
			}
			else
			{
				cout << a * 1.0 / b << "\n";
			}
		}
	}
	return 0;
}
