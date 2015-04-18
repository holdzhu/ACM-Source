#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int l1, r1, l2, r2;
		scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
		int bl1[30], br1[30], bl2[30], br2[30];
		bool low1 = false;
		bool low2 = false;
		bool high1 = false;
		bool high2 = false;
		for (int i = 29; i >= 0; --i)
		{
			bl1[i] = l1 & 1;
			br1[i] = r1 & 1;
			bl2[i] = l2 & 1;
			br2[i] = r2 & 1;
			l1 >>= 1;
			r1 >>= 1;
			l2 >>= 1;
			r2 >>= 1;
		}
		int ans = 0;
		for (int i = 0; i < 30; ++i)
		{
			bool c1[2] = {1, 1};
			bool c2[2] = {1, 1};
			if (!high1 && br1[i] == 0)
			{
				c1[1] = false;
			}
			if (!low1 && bl1[i] == 1)
			{
				c1[0] = false;
			}
			if (!high2 && br2[i] == 0)
			{
				c2[1] = false;
			}
			if (!low2 && bl2[i] == 1)
			{
				c2[0] = false;
			}
			if (c1[0] && c1[1])
			{
				if (c2[0] && c2[1])
				{
					ans <<= 1;
					if (!low2 && !high2)
					{
						high1 = true;
						high2 = true;
					}
					else if (!low2)
					{
						high1 = true;
					}
					else if (!high2)
					{
						low1 = true;
					}
				}
				else if (c2[0])
				{
					ans <<= 1;
					ans |= 1;
					low1 = true;
				}
				else
				{
					ans <<= 1;
					ans |= 1;
					high1 = true;
				}
			}
			else if (c1[0])
			{
				if (c2[0] && c2[1])
				{
					ans <<= 1;
					high2 = true;
				}
				else if (c2[0])
				{
					ans <<= 1;
				}
				else
				{
					ans <<= 1;
					ans |= 1;
				}
			}
			else
			{
				if (c2[0] && c2[1])
				{
					ans <<= 1;
					low2 = true;
				}
				else if (c2[0])
				{
					ans <<= 1;
					ans |= 1;
				}
				else
				{
					ans <<= 1;
				}
			}
		}
		int ans2 = 0;
		low1 = false;
		low2 = false;
		high1 = false;
		high2 = false;
		for (int i = 0; i < 30; ++i)
		{
			bool c1[2] = {1, 1};
			bool c2[2] = {1, 1};
			if (!high1 && br1[i] == 0)
			{
				c1[1] = false;
			}
			if (!low1 && bl1[i] == 1)
			{
				c1[0] = false;
			}
			if (!high2 && br2[i] == 0)
			{
				c2[1] = false;
			}
			if (!low2 && bl2[i] == 1)
			{
				c2[0] = false;
			}
			if (c1[0] && c1[1])
			{
				if (c2[0] && c2[1])
				{
					ans2 <<= 1;
					if (!low2 && !high2)
					{
						low1 = true;
						low2 = true;
					}
					else if (!low2)
					{
						high1 = true;
					}
					else if (!high2)
					{
						low1 = true;
					}
				}
				else if (c2[0])
				{
					ans2 <<= 1;
					ans2 |= 1;
					low1 = true;
				}
				else
				{
					ans2 <<= 1;
					ans2 |= 1;
					high1 = true;
				}
			}
			else if (c1[0])
			{
				if (c2[0] && c2[1])
				{
					ans2 <<= 1;
					high2 = true;
				}
				else if (c2[0])
				{
					ans2 <<= 1;
				}
				else
				{
					ans2 <<= 1;
					ans2 |= 1;
				}
			}
			else
			{
				if (c2[0] && c2[1])
				{
					ans2 <<= 1;
					low2 = true;
				}
				else if (c2[0])
				{
					ans2 <<= 1;
					ans2 |= 1;
				}
				else
				{
					ans2 <<= 1;
				}
			}
		}
		printf("Case #%d: %d\n", kase, (ans > ans2) ? ans : ans2);
	}
	return 0;
}
