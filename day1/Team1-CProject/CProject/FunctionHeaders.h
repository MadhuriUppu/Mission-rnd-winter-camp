#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pop(char*, int*);
int isEmpty();
int isFull();
void push(char*, int*, char);
int test_and_convert_postfix(char*, char*, int*, char*, int*, double*, int*);
void postfix_eval(char *postfix_exp, double* postfix_eval_stack, int *postfix_eval_stack_top, double *integer_stack, int *top);
int precedence(char);
double pop_int(double *postfix_eval_stack, int *top_int);
void push_int(double *postfix_eval_stack, int *top_int, double item);