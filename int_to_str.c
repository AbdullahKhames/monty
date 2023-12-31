#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
void fill_numbase_buff(unsigned int num, unsigned int base,
char *buff, int buff_size);
int get_numbase_len(unsigned int num, unsigned int base);


/**
 * get_int - gets a character pointer to new string contain integer
 * @num: num to convert to str
 *
 * Return: char pointer to new created string.NULL if malloc fail.
 */
char *get_int(int num)
{
unsigned int temp;
int length = 0;
long num_l = 0;
char *ret;

temp = _abs(num);
length = get_numbase_len(temp, 10);

if (num < 0 || num_l < 0)
length++; /* negative sign */
ret = malloc(length + 1); /* create new string */
if (!ret)
return (NULL);

fill_numbase_buff(temp, 10, ret, length);
if (num < 0 || num_l < 0)
ret[0] = '-';

return (ret);
}

/**
 * _abs - get the absolute value of an int.
 * @i: integer to get absolute value.
 *
 * Return: unsigned integer abs repo of i.
 */
unsigned int _abs(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
 * get_numbase_len - get length of buffer need for an unsigned int
 * @num: num to get length needed for
 * @base: numbers represen used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
int len = 1; /* all numbers contain atleast one digit */

while (num > base - 1)
{
len++;
num /= base;
}
return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: numbers to string given in base 36
 * @base: base of numbers used it is only works up to base 36
 * @buff: buffer appear result of conversion.
 * @buff_size: the size of the buffer in byte.
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
int rem, i = buff_size - 1;

buff[buff_size] = '\0';
while (i >= 0)
{
rem = num % base;
if (rem > 9) /* return lowercase ascii val representation */
buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
else
buff[i] = rem + '0';
num /= base;
i--;
}
}
