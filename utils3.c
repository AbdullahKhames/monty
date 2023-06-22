#include "monty.h"



/**
 * nop_monty - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void nop_monty(stack_t **stack, unsigned int ln_no)
{
	(void)stack;
	(void)ln_no;
}

/**
 * pchar_monty - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void pchar_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(ln_no, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(ln_no,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstr_monty - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void pstr_monty(stack_t **stack, unsigned int ln_no)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)ln_no;
}

