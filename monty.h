#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
#define BUFSIZE 1024
/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln_no);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void push_monty(stack_t **stack, unsigned int ln_no);
void pall_monty(stack_t **stack, unsigned int ln_no);
void pint_monty(stack_t **stack, unsigned int ln_no);
void pop_monty(stack_t **stack, unsigned int ln_no);
void swap_monty(stack_t **stack, unsigned int ln_no);
void add_monty(stack_t **stack, unsigned int ln_no);
void nop_monty(stack_t **stack, unsigned int ln_no);
void sub_monty(stack_t **stack, unsigned int ln_no);
void div_monty(stack_t **stack, unsigned int ln_no);
void mul_monty(stack_t **stack, unsigned int ln_no);
void mod_monty(stack_t **stack, unsigned int ln_no);
void pchar_monty(stack_t **stack, unsigned int ln_no);
void pstr_monty(stack_t **stack, unsigned int ln_no);
void rotl_monty(stack_t **stack, unsigned int ln_no);
void rotr_monty(stack_t **stack, unsigned int ln_no);
void stack_monty(stack_t **stack, unsigned int ln_no);
void queue_monty(stack_t **stack, unsigned int ln_no);
void queue_mode_monty(stack_t *stack, stack_t *new, stack_t *temp);
/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int ln_no);
int no_int_error(unsigned int ln_no);
int pop_error(unsigned int ln_no);
int pint_error(unsigned int ln_no);
int short_stack_error(unsigned int ln_no, char *op);
int div_error(unsigned int ln_no);
int pchar_error(unsigned int ln_no, char *message);
void line_bringer(char **lineptr, size_t *n, char *buffer, size_t ind);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
#endif /* __MONTY_H__ */
