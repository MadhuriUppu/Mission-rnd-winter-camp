#include "FunctionHeaders.h"

char *operators = "+-/*%<>";

int is_operator(char c){
	for (int i = 0; i < strlen(operators); i++)
		if (operators[i] == c)
			return 1;
	return 0;
}

double parse_double(char *str){

	char *fraction = NULL;
	int k = 0, is_double = 0;
	double result = 0, real = 0;
	double place_value = 10;
	for (int i = 0; str[i] != '\0'; i++){

		if (str[i] == '.'){
			fraction = (char*)malloc((strlen(str)) * sizeof(char));
			memset(fraction, 0, strlen(str));
			is_double = 1;
			for (int j = i + 1, k = 0; str[j] != '\0'; j++, k++){
				fraction[k] = str[j];
			}
			break;
		}
		result = (result * 10) + (str[i] - '0');
	}
	if (is_double == 1){
		for (int i = 0; fraction[i] != '\0'; i++){
			real += (fraction[i] - '0') / place_value;
			place_value *= 10;
		}
	}

	free(fraction);
	return result + real;
}

int precedence(char c)
{
	switch (c){

	case '(':
	case ')':
		return 0;
	case '%':
		return 1;
	case '+':
		return 2;
	case '-':
		return 3;
	case '>':
		return 4;
	case '<':
		return 5;
	case '*':
		return 6;
	case '/':
		return 7;
	default:
		return -1;
	}
}

int test_and_convert_postfix(char *input, char *output, int *len, char *postfix_operator_stack, int *top, double *operands, int *index)
{

	/*
	input = input string
	output = final postfix string stack
	len = pointer to top of output stack
	postfix_operator_stack = stack that aids in converting input to postfix
	top = pointer to top of postfix_operator_stack
	operands = list of all operands extracted from input;	
	index = length of operands
	*/

	int i, j = 0;
	char c;
	int multiple = 1; //if 1, number is positive, if -1, number is negative
	for (i = 0; i<strlen(input); i++)
	{
		if (input[i] == ' ')
			continue;
		else if (is_operator(input[i]) == 1)
		{
			if ((i == 0 || is_operator(input[i - 1]) == 1) && input[i] == '-'){
				multiple = -1; //negative(if current index has '-' and previous index is some other operator)
			}
			else if (i != 0 && is_operator(input[i - 1])){
				printf("INVALID\n"); //if above case fails, this can be triggered
				return 0;
			}
			else if (precedence(input[i]) >= precedence(postfix_operator_stack[*top]))
			{
				if ((input[i] == '>' && input[i + 1] == '>') || (input[i] == '<' && input[i + 1] == '<'))
					i++;
				else if ((input[i] == '>' && input[i + 1] != '>') || (input[i] == '<' && input[i + 1] != '<')){ //invalid shift operators
					printf("INVALID\n");
					return 0;
				}

				push(postfix_operator_stack, top, input[i]);
			}
			else if ((precedence(input[i]) < precedence(postfix_operator_stack[*top]))
				&& (postfix_operator_stack[*top] != '(' || postfix_operator_stack[*top] != ')'))  //incoming operator has lower precedence.        
			{
				output[(*len)++] = pop(postfix_operator_stack, top);
				i--;
			}
		}
		else if (input[i] == '(')
		{
			push(postfix_operator_stack, top, input[i]);
		}
		else if (input[i] == ')')
		{

			while (postfix_operator_stack[*top] != '(' && top >= 0){
				output[*len] = pop(postfix_operator_stack, top);
				*len = *len + 1;
			}
			pop(postfix_operator_stack, top); //pop the leftover '('

		}
		else if (isdigit(input[i]) || input[i] == '.')
		{
			output[*len] = 'a';
			char *number = (char*)malloc(50 * sizeof(char));
			int j = 0;
			while (input[i] == '.' || isdigit(input[i]))
				number[j++] = input[i++];
			i--;
			number[j] = '\0';
			double result = parse_double(number); //!!OUR STRING TO NUMBER LOOP!!
			operands[(*index)] = result * multiple;
			*index = *index + 1;
			multiple = 1;
			*len = *len+1;
			free(number);
		}
		else
		{
			printf("INVALID\n");
			return 0;
		}
	}//end of for loop. 
	while (*top >= 0 && postfix_operator_stack[*top] != '(')
	{
		output[*len] = pop(postfix_operator_stack, top);
		*len = *len + 1;
	}//Popping elements until left paranthesis is encountered.
	output[*len] = '\0';
	return 1;


}

void push(char *stack, int *top, char c)
{
	if (!isFull())
		stack[++(*top)] = c;
}

char pop(char *stack, int *top)
{
	if (isEmpty())
		return('#');
	else
		return (stack[(*top)--]);
}