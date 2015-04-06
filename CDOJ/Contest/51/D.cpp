#include <cstdio>
#include <cstring>
        
char s[100001];

int oddleft(int start, int end)
{
    int r = 0;
    int b = 0;
    for (int i = end; i >= start; --i)
    {
        if (s[i] == '1')
        {
            b++;
        }
        if ((i - end) % 2 == 0 && b % 2 == 0)
        {
            r++;
        }
    }
    return r;
}

int oddright(int start, int end)
{
    int r = 0;
    int b = 0;
    for (int i = start; i <= end; ++i)
    {
        if (s[i] == '1')
        {
            b++;
        }
        if ((i - start) % 2 == 0 && b % 2 == 0)
        {
            r++;
        }
    }
    return r;
}

int evenleft(int start, int end)
{
    int r = 0;
    int b = 0;
    for (int i = end; i >= start; --i)
    {
        if (s[i] == '1')
        {
            b++;
        }
        if ((i - end - 1) % 2 == 0 && b % 2 == 0)
        {
            r++;
        }
    }
    return r;
}

int evenright(int start, int end)
{
    int r = 0;
    int b = 0;
    for (int i = start; i <= end; ++i)
    {
        if (s[i] == '1')
        {
            b++;
        }
        if ((i - start - 1) % 2 == 0 && b % 2 == 0)
        {
            r++;
        }
    }
    return r;
}

long long evensum(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    else
    {
        int mid = (start + end) / 2;
        int oL = oddleft(start, mid);
        int oR = oddright(mid + 1, end);
        int eL = evenleft(start, mid);
        int eR = evenright(mid + 1, end);
        int eLl = (mid - start + 1) / 2;
        int eRl = (end - mid) / 2;
        int oLl = mid - start + 1 - eLl;
        int oRl = end - mid - eRl;
        return evensum(start, mid) + evensum(mid + 1, end) + oL * oR + eL * eR + (eLl - eL) * (eRl - eR) + (oLl - oL) * (oRl - oR);
    }
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
        int l = strlen(s);
        long long es = ((l + 1) / 2);
        es *= es;
        if (l % 2 == 0)
        {
            es += (l + 1) / 2;
        }
        es += evensum(0, l - 1);
        printf("%lld\n", es);
	}
	return 0;
}
