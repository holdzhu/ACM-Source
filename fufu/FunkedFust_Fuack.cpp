#include <stdio.h>

struct Node
{
	char c;
	Node *next;
};

int main()
{
	char c;
	Node *top = NULL;
	while (1)
	{
		c = getchar();
		if (top == NULL)
		{
			top = new Node;
			top->next = NULL;
		}
		else
		{
			Node *newTop = new Node;
			newTop->next = top;
			top = newTop;
		}
		top->c = c;
		if (c == '\n')
			break;
	}
	Node *p = top;
	while (p != NULL)
	{
		putchar(p->c);
		p = p->next;
	}
	return 0;
}
