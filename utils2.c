#include "monty.h"



/**
 * add_monty - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void add_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_monty(stack, ln_no);
}

/**
 * sub_monty - Subtracts the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void sub_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop_monty(stack, ln_no);
}

/**
 * div_monty - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void div_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(ln_no));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop_monty(stack, ln_no);
}

/**
 * mul_monty - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mul_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop_monty(stack, ln_no);
}

/**
 * mod_monty - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mod_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(ln_no));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_monty(stack, ln_no);
}

