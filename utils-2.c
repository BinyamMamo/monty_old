#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * swap - swaps the top most elements of a stack
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	int i = 0;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = ((*stack)->prev)->n;
	((*stack)->prev)->n = temp;
}

/**
 * add - adds the top most elements of a stack
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	pop();
	(*stack)->n += temp;
}

/**
 * nop - does nothing
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	// does nothing
}