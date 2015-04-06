#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int D;
	while (scanf("%d", &D) == 1 && D >= 0)
	{
		multiset<pair<double, bool> > s;
		double t = (180 - D) * 120 / 11.0;
		for (int i = 0; i < 11; ++i)
		{
			s.insert(make_pair(i * 43200.0 / 11.0 + 21600.0 / 11.0 - t, true));
			s.insert(make_pair(i * 43200.0 / 11.0 + 21600.0 / 11.0 + t, false));
		}
		t = (180 - D) * 10 / 59.0;
		for (int i = 0; i < 708; ++i)
		{
			s.insert(make_pair(i * 3600.0 / 59.0 + 1800.0 / 59.0 - t, true));
			s.insert(make_pair(i * 3600.0 / 59.0 + 1800.0 / 59.0 + t, false));
		}
		t = (180 - D) * 120 / 719.0;
		for (int i = 0; i < 719; ++i)
		{
			s.insert(make_pair(i * 43200.0 / 719.0 + 21600.0 / 719.0 - t, true));
			s.insert(make_pair(i * 43200.0 / 719.0 + 21600.0 / 719.0 + t, false));
		}
		double last = 0.0;
		int c = 0;
		double sum = 0.0;
		for (multiset<pair<double, bool> >::iterator i = s.begin(); i != s.end(); ++i)
		{
			if (c == 3)
			{
				sum += i->first - last;
			}
			if (i->second)
			{
				c++;
			}
			else
			{
				c--;
			}
			last = i->first;
		}
		printf("%.3lf\n", sum / 432);
	}
	return 0;
}
