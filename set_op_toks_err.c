#include <string.h>
#include "monty.h"


int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_stack(stack_t **stack);

/**
 * init_stack - Initialize a stack_t stack with beginning
 * stack and ending queue node.
 * @stack: this a pointer on stack_t and unitialized stack.
 *
 * Return: If an error occurs -exit_failure.
 * Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
return (malloc_error());
s->n = STACK;
s->prev = NULL;
s->next = NULL;
*stack = s;
return (EXIT_SUCCESS);
}

/**
 * check_mode - Check if a stack_t linked list is in queue mode or stackxo
 * @stack: A pointer to the or bottom (Queue)
 * stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 * If the stack_t is in queue mode - QUEUE (1).
 * or Otherwise -2.
 */
int check_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 * stack_t bottom the queue.
 */
void free_stack(stack_t **stack)
{
stack_t *tmp = *stack;

while (*stack)
{
tmp = (*stack)->next;
free(*stack);
*stack = tmp;
}
}
