#include <cstdio>
#include <set>

using namespace std;

struct Void 
{
	int a, b, c, d;
};

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		Void v[n];
		set<Void*> s;
		Void *m1, *m2, *m3, *t;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i].a);
		}
		m1 = v;
		m2 = v + 1;
		m3 = v + 2;
		if (m1->a < m2->a)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		if (m2->a < m3->a)
		{
			t = m3;
			m3 = m2;
			m2 = t;
		}
		if (m1->a < m2->a)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		for (int i = 3; i < n; ++i)
		{
			if (v[i].a > m1->a)
			{
				m3 = m2;
				m2 = m1;
				m1 = v + i;
			}
			else if (v[i].a > m2->a)
			{
				m3 = m2;
				m2 = v + i;
			}
			else if (v[i].a > m3->a)
			{
				m3 = v + i;
			}
		}
		s.insert(m1);
		s.insert(m2);
		s.insert(m3);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i].b);
		}
		m1 = v;
		m2 = v + 1;
		m3 = v + 2;
		if (m1->b < m2->b)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		if (m2->b < m3->b)
		{
			t = m3;
			m3 = m2;
			m2 = t;
		}
		if (m1->b < m2->b)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		for (int i = 3; i < n; ++i)
		{
			if (v[i].b > m1->b)
			{
				m3 = m2;
				m2 = m1;
				m1 = v + i;
			}
			else if (v[i].b > m2->b)
			{
				m3 = m2;
				m2 = v + i;
			}
			else if (v[i].b > m3->b)
			{
				m3 = v + i;
			}
		}
		s.insert(m1);
		s.insert(m2);
		s.insert(m3);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i].c);
		}
		m1 = v;
		m2 = v + 1;
		m3 = v + 2;
		if (m1->c < m2->c)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		if (m2->c < m3->c)
		{
			t = m3;
			m3 = m2;
			m2 = t;
		}
		if (m1->c < m2->c)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		for (int i = 3; i < n; ++i)
		{
			if (v[i].c > m1->c)
			{
				m3 = m2;
				m2 = m1;
				m1 = v + i;
			}
			else if (v[i].c > m2->c)
			{
				m3 = m2;
				m2 = v + i;
			}
			else if (v[i].c > m3->c)
			{
				m3 = v + i;
			}
		}
		s.insert(m1);
		s.insert(m2);
		s.insert(m3);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i].d);
			v[i].d += v[i].b + v[i].c;
		}
		m1 = v;
		m2 = v + 1;
		m3 = v + 2;
		if (m1->d < m2->d)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		if (m2->d < m3->d)
		{
			t = m3;
			m3 = m2;
			m2 = t;
		}
		if (m1->d < m2->d)
		{
			t = m1;
			m1 = m2;
			m2 = t;
		}
		for (int i = 3; i < n; ++i)
		{
			if (v[i].d > m1->d)
			{
				m3 = m2;
				m2 = m1;
				m1 = v + i;
			}
			else if (v[i].d > m2->d)
			{
				m3 = m2;
				m2 = v + i;
			}
			else if (v[i].d > m3->d)
			{
				m3 = v + i;
			}
		}
		s.insert(m1);
		s.insert(m2);
		s.insert(m3);
		int maxv = 0;
		int sn = s.size();
		for (set<Void*>::iterator i = s.begin(); i != s.end(); ++i)
		{
			for (set<Void*>::iterator j = s.begin(); j != s.end(); ++j)
			{
				if (i != j)
				{
					if ((*i)->a + (*j)->d > maxv)
					{
						maxv = (*i)->a + (*j)->d;
					}
					for (set<Void*>::iterator k = s.begin(); k != s.end(); ++k)
					{
						if (i != k && i != j)
						{
							if ((*i)->a + (*j)->b + (*k)->c > maxv)
							{
								maxv = (*i)->a + (*j)->b + (*k)->c;
							}
						}
					}
				}
			}
		}
		printf("%d\n", maxv);
	}
	return 0;
}
