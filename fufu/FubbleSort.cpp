#include <stdio.h>

int a[100];

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int n;
	printf("���������С��");
	scanf("%d", &n);
	printf("�������飺");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; ; i++)
	{
		bool swaped = false;
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swaped = true;
			}
		}
		if (!swaped)
			break;
	}
	printf("�����");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
