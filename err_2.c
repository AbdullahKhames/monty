#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int pchar_error(unsigned int line_number, char *message);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);

int div_error(unsigned int line_number);

/**
 * pop_error - Print pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (exit_failure) always.
 */
int pop_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pint_error - Print pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (exit_failure) always.
 */
int pint_error(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prin monty math function error message.
 * for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (exit_failure) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * div_error - Print division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (exit_failure) always.
 */
int div_error(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacs.
 *   empty stacks and non-character values
 * @line_number: Line number in Monty bytecodes file where err occurred.
 * @message: The corresponding err message
 *
 * Return: (exit_failure) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);
}
