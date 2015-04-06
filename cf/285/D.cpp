#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	set<int> s;
	int a1[n];
	int a2[n];
	int t;
	for (int i = 0; i < n; ++i)
	{
		s.insert(i);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		a1[i] = distance(s.begin(), s.find(t));
		s.erase(t);
	}
	for (int i = 0; i < n; ++i)
	{
		s.insert(i);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		a2[i] = distance(s.begin(), s.find(t));
		s.erase(t);
	}
	int a[n];
	t = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		a[i] = (a1[i] + a2[i] + t) % (n - i);
		t = (a1[i] + a2[i] + t) / (n - i);
	}
	int w[n];
	for (int i = 0; i < n; ++i)
	{
		w[i] = i;
	}
	bool f = true;
	for (int i = 0; i < n; ++i)
	{
		if (f)
		{
			f = false;
		}
		else
		{
			printf(" ");
		}
		int _w[n];
		memcpy(_w, w, sizeof(w));
		nth_element(_w, _w + a[i], _w + n);
		printf("%d", *(_w + a[i]));
		w[*(_w + a[i])] = n;
	}
	printf("\n");
	return 0;
}
