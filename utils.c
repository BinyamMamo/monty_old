#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * pall - Prints all elements of the stack
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;

    if (*stack == NULL)
    {
        fprintf(stderr, "stack underflow");
        exit(0);
    }
    else
    {
        temp = *stack;
        while (temp != NULL)
        {
            printf("%d\n", temp->n);
            temp = temp->prev;
        }
    }
}

/**
 * push - pushes an element at the top of the stack
 * @stack: points to the top of the stack
 * @line_number: keeps track of the line number
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *token = NULL;
    int data = 0;
    stack_t *temp = malloc(sizeof(stack_t));

    token = strtok(NULL, " \n");

    if (token == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }

    data = atoi(token);
    if (temp == NULL)
    {
        fprintf(stderr, "stack overflow");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (*stack == NULL)
        {
            temp->prev = NULL;
            temp->n = data;
            temp->next = NULL;
            *stack = temp;
        }
        else
        {
            temp->n = data;
            temp->prev = *stack;
            temp->next = NULL;
            (*stack)->next = temp;
            *stack = temp;
        }
    }
}
