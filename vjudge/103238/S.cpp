#include <iostream>
#include <algorithm>

using namespace std;

long long solve(string A, string B)
{
	int n = min(A.size(), B.size());
	long long res = 0;
	for (int i = n; i > 0; --i)
	{
		res *= 2;
		res += A.substr(A.size() - i) == B.substr(0, i);
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; ++kase)
	{
		string A, B;
		cin >> A >> B;
		long long SA = solve(B, B) - solve(B, A);
		long long SB = solve(A, A) - solve(A, B);
		long long S = SA + SB;
		long long g = __gcd(SA, S);
		cout << "Case #" << kase << ":\n" << SA / g << '/' << S / g << '\n';
	}
	return 0;
}
