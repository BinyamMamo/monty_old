#include <stdio.h>
#include <stdlib.h>
// #include "monty.h"

struct node
{
	int data;
	struct node *next;
};

struct node *temp = NULL;
void pall(void);
void push(int data);

int main(void)
{
	push(5);
	push(4);
	push(3);
	push(2);
	pall();
	return (0);
}

void pall(void)
{
	int i = 0;
	struct node *pointer = NULL;

	if (temp == NULL)
	{
		fprintf(stderr, "stack underflow");
		exit(0);
	}
	else
	{
		pointer = temp;
		while (pointer != NULL)
		{
			printf("stack[%d] = %d\n", i, pointer->data);
			i++;
			pointer = pointer->next;
		}
	}
}

void push(int data)
{
	struct node *new = malloc(sizeof(struct node *));

	if (new == NULL)
	{
		fprintf(stderr, "stack overflow");
		exit(0);
	}
	else
	{
		new->data = data;
		new->next = temp;
		temp = new;
	}
}
