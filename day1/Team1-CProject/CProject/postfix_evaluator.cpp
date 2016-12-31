#include "FunctionHeaders.h"


double pop_int(double *postfix_eval_stack, int *top_int)
{
	*top_int = (*top_int) - 1;
	return (postfix_eval_stack[(*top_int)+1]);
}

void push_int(double *postfix_eval_stack, int *top_int, double item)
{
	*top_int = (*top_int) + 1;
	postfix_eval_stack[*top_int] = item;
}


void postfix_eval(char *postfix_exp, double* postfix_eval_stack, int *postfix_eval_stack_top, double *integer_stack, int *top)
{
	/*
	postfix_exp = input postfix expression
	postfix_eval_stack = 
	
	
	*/
	
	*postfix_eval_stack_top = -1;
	int i;
	double res = 0;
	double operand1, operand2;
	int index = 0;
	for (i = 0; i<strlen(postfix_exp); i++)
	{
		if (isalpha(postfix_exp[i]))
		{
			push_int(postfix_eval_stack, postfix_eval_stack_top, integer_stack[index++]);

		}
		else
		{
			operand1 = pop_int(postfix_eval_stack, postfix_eval_stack_top);
			operand2 = pop_int(postfix_eval_stack, postfix_eval_stack_top);
			switch (postfix_exp[i])
			{
			case '*': res = operand2 * operand1;
				break;
			case '+':res = operand2 + operand1;
				break;
			case '-':res = operand2 - operand1;
				break;
			case '/':if (operand1 == 0){
					printf("divide by zero error\n");
					return;
				}
				res = operand2 / operand1;
				break;
			case '%':if (operand1 == 0){
				printf("divide by zero error\n");
				return;
			}
			res = (int)operand2 % (int)operand1;
				break;
			case '<':res = (int)operand2 << (int)operand1;
				break;
			case '>':res = (int)operand2 >> (int)operand2;
				break;
			}
			push_int(postfix_eval_stack, postfix_eval_stack_top, res);
		}
	}
	if (*postfix_eval_stack_top < *top){
		printf("INVALID\n");
		return;

	}

	printf("%lf\n", pop_int(postfix_eval_stack, postfix_eval_stack_top));
}
