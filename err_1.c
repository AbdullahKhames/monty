include "monty.h"

int usage_error(void);
int malloc_error(void);
int no_int_error(unsigned int line_number);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);

/**
 * usage_error - Print usage err message
 *
 * Return: (exit_failure)always
 */
int usage_error(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * malloc_error - Print malloc err message
 *
 * Return: (exit_failure)always
 */
int malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

/**
 * f_open_error - Print file opening err messages w/ file name
 * @filename: Name of file failed to open
 *
 * Return: (exit_failure) always.
 */
int f_open_error(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (exit_failure) always.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
line_number, opcode);
return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument err message
 * @line_number: Line number in byte codes file where err occurred
 *
 * Return: (exit_failure) always.
 */

int no_int_error(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
