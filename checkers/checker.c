#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10
int top = -1;
int stack[LIMIT];
void pall(void);
void push(int data);

int main(void)
{
	// printf("stack[0] = %d", stack[0]);
	push(5);
	push(2);
	push(3);
	push(4);
	pall();
	return (0);
}

void pall(void)
{
	// printf("hello ");
	int i = top;

	if (top == -1)
	{
		fprintf(stderr, "stack underflow");
		exit(0);
	}
	else
	{
		for (i = top; i >= 0; i--)
		{
			printf("stack[%d] = %d\n", i, stack[i]);
		}
	}
}

void push(int data)
{
	if (top >= LIMIT)
	{
		fprintf(stderr, "stack overflow");
		exit(0);
	}
	else
	{
		top++;
		stack[top] = data;
	}
}
