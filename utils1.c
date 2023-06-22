#include "monty.h"

/**
 * push_monty - Pushes to stack.
 * @stack: A pointer to the top stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void push_monty(stack_t **stack, unsigned int ln_no)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(ln_no));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(ln_no));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		queue_mode_monty(*stack, new,tmp);
	}
}
/**
 * pall_monty - Prints values stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void pall_monty(stack_t **stack, unsigned int ln_no)
{
	stack_t *current = (*stack)->next;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)ln_no;
}

/**
 * pint_monty - Prints the top value of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void pint_monty(stack_t **stack, unsigned int ln_no)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(ln_no));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * pop_monty - Removes the top value element of a stack
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void pop_monty(stack_t **stack, unsigned int ln_no)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(ln_no));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap_monty - Swaps the top two value elements of a stack
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @ln_no: The current working line number of a Monty bytecodes file.
 */
void swap_monty(stack_t **stack, unsigned int ln_no)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln_no, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

