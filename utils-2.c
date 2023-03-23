#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
int mlen(stack_t *);
/**
 * swap - swaps the top most elements of a stack
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void mswap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (mlen(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = ((*stack)->prev)->n;
	((*stack)->prev)->n = temp;
}

/**
 * nop - does nothing
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void mnop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{

	/* does nothing */
}
