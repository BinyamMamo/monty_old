#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
};

/**
 * main - Entry point of the program
 * @argc: the number of arguments
 * @argv: list of arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	void (*func)(stack_t **, unsigned int);
	stack_t *stack = NULL;
	FILE *file;

	char line[256];
	char *token;

	int line_no = 0;
	int found = 0;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line_no++;
		token = strtok(line, " \n\r");

		if (token == NULL)
			continue;
		for (i = 0; i < 2; i++)
		{
			if (!strcmp(inst[i].opcode, token))
			{
				func = inst[i].f;
				(*func)(&stack, line_no);
				found = 1;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_no, token);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return (0);
}
