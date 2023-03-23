#include "monty.h"

int mlen(stack_t *ptr)
{
	int i = 0;

	while (ptr)
	{
		i++;
		ptr = ptr->prev;
	}

	return (i);
}
