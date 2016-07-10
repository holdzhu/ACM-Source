#include <stdio.h>

struct Node
{
	char c;
	Node *next;
};

int main()
{
	char c;
	Node *rear = NULL;
	Node *front = NULL;
	while (1)
	{
		c = getchar();
		if (rear == NULL)
		{
			rear = new Node;
			front = rear;
		}
		else
		{
			Node *newFront = new Node;
			newFront->next = NULL;
			front->next = newFront;
			front = newFront;
		}
		front->c = c;
		if (c == '\n')
			break;
	}
	Node *p = rear;
	while (p != NULL)
	{
		putchar(p->c);
		p = p->next;
	}
	return 0;
}
