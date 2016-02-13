#include <cstdio>

int main()
{
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	int delta;
	scanf("%d", &delta);
	int target = (hh * 60 + mm + delta) % (24 * 60);
	printf("%02d:%02d\n", target / 60, target % 60);
	return 0;
}
