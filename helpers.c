#include "monty.h"

int len(stack_t *ptr)
{
	int i = 0;

	while (ptr)
	{
		i++;
		ptr = ptr->prev;
	}

	return (i);
}
