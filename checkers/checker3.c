#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void pall(void);
void push(int data);

stack_t *pos = NULL;
int main(void)
{
	// printf("hello ");
	push(5);
	push(3);
	push(4);
	push(2);
	pall();
	return (0);
}

void pall(void)
{
	int i = 0;
	stack_t *temp = NULL;
	if (pos == NULL)
	{
		fprintf(stderr, "stack underflow");
		exit(0);
	}
	else
	{
		temp = pos;
		while (temp != NULL)
		{
			printf("stack[%d] = %d\n", i, temp->n);
			temp = temp->prev;
			i++;
		}
	}
}

void push(int data)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "stack overflow");
		exit(0);
	}
	else
	{
		if (pos == NULL)
		{
			temp->prev = NULL;
			temp->n = data;
			temp->next = NULL;
			pos = temp;
		}
		else
		{
			temp->n = data;
			temp->prev = pos;
			temp->next = NULL;
			pos->next = temp;
			pos = temp;
		}
	}
}