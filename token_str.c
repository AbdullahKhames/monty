#include <stdlib.h>

int is_delim(char ch, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
char **strtow(char *str, char *delims);
int get_word_length(char *str, char *delims);

/**
 * is_delim - checks if stream delimitor charactezm
 *
 * @ch: character in streamonzo
 *
 * @delims: Pointer to null terminat array of delimitors all
 *
 * Return: one (success) zero (fail)
 */

int is_delim(char ch, char *delims)
{
int i = 0;

while (delims[i])
{
if (delims[i] == ch)
return (1);
i++;
}
return (0);
}

/**
 * strtow - takes its word a string and seperate them
 *
 * @str: string to seperate into single words
 * @delims: delimitors to use to delimition words.
 *
 * Return: 2d array each word to pointer .
 */

char **strtow(char *str, char *delims)
{
char **words = NULL;
int wc, wordLen, n, i = 0;

if (str == NULL || !*str)
return (NULL);
wc = get_word_count(str, delims);

if (wc == 0)
return (NULL);
words = malloc((wc + 1) * sizeof(char *));
if (words == NULL)
return (NULL);
while (i < wc)
{
wordLen = get_word_length(str, delims);
if (is_delim(*str, delims))
{
str = get_next_word(str, delims);
}
words[i] = malloc((wordLen + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i >= 0)
{
i--;
free(words[i]);
}
free(words);
return (NULL);
}
n = 0;
while (n < wordLen)
{
words[i][n] = *(str + n);
n++;
}
words[i][n] = '\0'; /* set end of str */
str = get_next_word(str, delims);
i++;
}
words[i] = NULL; /* last element is null for iteration */
return (words);
}

/**
 * get_word_length - gets the word length of cur word in str.
 *
 * @str: from current word stringz to get word length.
 * @delims: delimitor to use to delimit word.
 *
 * Return: word length of current word.
 */

int get_word_length(char *str, char *delims)
{
int wLen = 0, pending = 1, i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
wLen++;
}
if (wLen > 0 && is_delim(str[i], delims))
break;
i++;
}
return (wLen);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
int pending = 0;
int i = 0;

while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
break;
i++;
}
return (str + i);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
int wc = 0, pending = 1, i = 0;
while (*(str + i))
{
if (is_delim(str[i], delims))
pending = 1;
else if (pending)
{
pending = 0;
wc++;
}
i++;
}
return (wc);
}
