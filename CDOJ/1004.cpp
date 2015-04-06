#include <cstdio>
#include <cstdlib>

struct Node
{
	int value;
	Node *next;
};

void init(Node **head)
{
	*head = (Node *) malloc(sizeof(Node *));
	(*head)->next = NULL;
}

void add(Node *head, int index, int value)
{
	int pos = 0;
	Node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		if (pos == index)
		{
			p->value += value;
			return;
		}
		pos++;
	}
	for (int i = 0; i < index - pos; ++i)
	{
		Node *s = (Node *) malloc(sizeof(Node *));
		s->value = 0;
		s->next = NULL;
		p->next = s;
		p = s;
	}
	Node *s = (Node *) malloc(sizeof(Node *));
	s->value = value;
	s->next = NULL;
	p->next = s;
}

int len(Node *head)
{
	int l = 0;
	while (head->next != NULL)
	{
		head = head->next;
		l++;
	}
	return l;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		Node *l1, *l2, *l3;
		init(&l1);
		init(&l2);
		init(&l3);
		while (scanf("%d %d", &a, &b))
		{
			if (b == -1)
			{
				break;
			}
			add(l1, b, a);
		}
		while (scanf("%d %d", &a, &b))
		{
			if (b == -1)
			{
				break;
			}
			add(l2, b, a);
		}
		int l = len(l1) + len(l2) - 2;
		int i = 0;
		int j;
		for (Node *p1 = l1->next; p1 != NULL; p1 = p1->next)
		{
			j = 0;
			for (Node *p2 = l2->next; p2 != NULL; p2 = p2->next)
			{
				add(l3, l - i - j, p1->value * p2->value);
				j++;
			}
			i++;
		}
		i = l;
		bool f = false;
		for (Node *p = l3->next; p != NULL; p = p->next)
		{
			if (p->value)
			{
				if (f && p->value > 0)
				{
					printf("+");
				}
				else
				{
					f = true;
				}
				if (i > 1)
				{
					if (p->value == -1)
					{
						printf("-");
					}
					else if (p->value != 1)
					{
						printf("%d*", p->value);
					}
					printf("x^%d", i);
				}
				else if (i == 1)
				{
					if (p->value == -1)
					{
						printf("-");
					}
					else if (p->value != 1)
					{
						printf("%d*", p->value);
					}
					printf("x");
				}
				else
				{
					printf("%d", p->value);
				}
			}
			i--;
		}
		if (!f)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
